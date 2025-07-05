local SCRIPT_INITIALIZED   -- gPoryLiveScriptInitialized
local SCRIPT_OVERRIDES     -- gPoryLiveOverrides
local SCRIPT_BUFFER        -- gPoryLiveScriptBuffer

local SCRIPT_OVERRIDES_SIZE = 200
local SCRIPT_BUFFER_SIZE = 102400 -- 100kb buffer

-- OS variables
local is_windows = false

-- Socket server variables
local server = nil
local sockets = {}
local nextID = 1
local LISTEN_PORT = 1370

-- Path variables
local build_dir
local bin_data_dir
local generated_files_path

-- Function to convert WSL path to Windows path
function convert_wsl_path_to_windows(path)
  if not is_windows then
    return path  -- No conversion needed on non-Windows systems
  end

  -- Check if this is a WSL path (starts with /mnt/)
  local drive_letter, rest_of_path = path:match("^/mnt/([a-zA-Z])/(.*)$")
  if drive_letter and rest_of_path then
    -- Convert /mnt/c/... to C:\...
    local windows_path = drive_letter:upper() .. ":/" .. rest_of_path
    return windows_path
  end

  return path  -- Return original path if not a WSL path
end

-- Function to set up project paths based on project root
function setup_project_paths(project_root)
  -- Ensure project_root ends with a slash
  if not project_root:match("/$") then
    project_root = project_root .. "/"
  end
  
  local status, result = pcall(function()
    return dofile(project_root .. "build/porylive_config.lua")
  end)
  if status and type(result) == "table" then
    build_dir = project_root .. result.current_build_dir
  else
    console:error("[-] Failed to setup project paths")
    return false
  end
  bin_data_dir = build_dir .. "/bin/data"
  generated_files_path = build_dir .. "/porylive_generated_files.lua"
  
  console:log("[+] Project paths set up:")
  console:log("    Project root: " .. project_root)
  console:log("    Build dir: " .. result.current_build_dir)
  
  -- Load addresses from the build directory
  local status, result = pcall(function()
    return dofile(build_dir .. "/addresses.lua")
  end)
  if status and type(result) == "table" then
    SCRIPT_INITIALIZED = result.gPoryLiveScriptInitialized
    SCRIPT_OVERRIDES = result.gPoryLiveOverrides
    SCRIPT_BUFFER = result.gPoryLiveScriptBuffer
    console:log("[+] Addresses loaded successfully")
  else
    console:error("[-] Failed to load Porylive utility addresses. Please run `make live` to generate the addresses.lua file.")
    return false
  end

  return true
end

local script_overrides_map = {}

function to_hex(num)
  return string.format("%02x", num)
end

function write_script_override(index, key, script_ptr)
  emu:write32(SCRIPT_OVERRIDES + index * 8, key)
  emu:write32(SCRIPT_OVERRIDES + index * 8 + 4, script_ptr)
end

function reload()
  -- Exit early if rom has not been loaded
  if emu == nil then
    console:log("[-] ROM not loaded")
    return
  end

  -- Clear existing data
  script_overrides_map = {}
  for i = 0, (SCRIPT_BUFFER_SIZE / 4) - 1 do
    emu.memory.cart0:write32(SCRIPT_BUFFER + i , 0)
  end
  for i = 0, (SCRIPT_OVERRIDES_SIZE / 4) - 1 do
    emu:write32(SCRIPT_OVERRIDES + i * 8, 0)
  end

  -- Load the generated files list from script directory
  local status, file_list = pcall(function()
    return dofile(generated_files_path)
  end)
  
  if not status or not file_list then
    console:log("[-] Failed to load generated files list: " .. tostring(file_list))
    console:log("[-] Make sure " .. generated_files_path .. " exists and is valid Lua")
    return
  end

  console:log("[+] Successfully loaded " .. #file_list .. " file entries")

  -- Steps:
  -- 1. Find all files in the data build directory, recursively checking subdirectories
  -- 2. For each filename (format label-address.bin), read the file and get the label and address
  -- 3. Read the binary data and write it to the script buffer at the address
  -- 4. Add the binary data to the script_overrides_map with the address as the key
  -- 5. Loop through the script_overrides_map and write the script to the script buffer at the address

  -- Function to find .bin files without using popen
  local function find_bin_files(dir)
    local files = {}
    
    for _, file_entry in ipairs(file_list) do
      local original_filename = convert_wsl_path_to_windows(file_entry.filename)
      -- Verify the file exists
      local test_file = io.open(original_filename, "rb")
      if test_file then
        test_file:close()
        table.insert(files, original_filename)
      else
        console:error("[-] File not found: " .. original_filename)
      end
    end
    
    return files
  end

  -- Find all .bin files in the data build directory
  local bin_files = find_bin_files(bin_data_dir)

  console:log("[+] Loading " .. #bin_files .. " script overrides")

  -- Process each .bin file
  console:log("[+] Scripts to override:")
  for _, file_path in ipairs(bin_files) do
    -- Extract filename from full path
    local filename = file_path:match("([^/]+)$")

    -- Parse filename format: label-address.bin
    local label, address_str = filename:match("^(.+)%-(%d+)%.bin$")

    if label and address_str then
      local address = tonumber(address_str)

      -- Read binary data from file
      local file_handle = io.open(file_path, "rb")
      if file_handle then
        local binary_data = {}
        local byte = file_handle:read(1)
        while byte do
          table.insert(binary_data, string.byte(byte))
          byte = file_handle:read(1)
        end
        file_handle:close()

        -- Store in script_overrides_map with address as key (in hex format)
        -- For new scripts (address 0), use a unique key based on label to avoid collisions
        local map_key
        if address == 0 then
          map_key = "new_" .. label  -- Use label-based key for new scripts
        else
          map_key = string.format("%x", address)  -- Use hex address for override scripts
        end
        
        script_overrides_map[map_key] = {
          binary_data = binary_data,
          label = label,
          lua_adjustments = nil,  -- Will be set below if found
          is_new_script = (address == 0),  -- Mark if this is a new script (address 0)
          original_address = address  -- Store original address for reference
        }

        -- Check if this file has lua_adjustments in the file_list
        for _, file_entry in ipairs(file_list) do
          if file_entry.filename == file_path and file_entry.lua_adjustments then
            script_overrides_map[map_key].lua_adjustments = file_entry.lua_adjustments
            break
          end
        end
        
        if address == 0 then
          console:log("      " .. label .. " \t(" .. #binary_data .. " bytes) [NEW SCRIPT]")
        else
          console:log("      " .. label .. " \t(" .. #binary_data .. " bytes)")
        end
      else
        console:log("[-] Failed to open file: " .. file_path)
      end
    else
      console:log("[-] Failed to parse filename: " .. filename)
    end
  end

  -- Write all binary data to script buffer and update script_overrides_map with buffer addresses
  local buffer_index = 0
  local final_overrides_map = {}

  -- First pass: calculate buffer addresses for all scripts
  local buffer_addresses = {}
  local temp_buffer_index = 0
  for map_key, script_data in pairs(script_overrides_map) do
    buffer_addresses[map_key] = SCRIPT_BUFFER + temp_buffer_index
    temp_buffer_index = temp_buffer_index + #script_data.binary_data
  end

  -- Second pass: write data with lua_adjustments applied
  for map_key, script_data in pairs(script_overrides_map) do
    local buffer_address = buffer_addresses[map_key]
    -- Only add to final_overrides_map if it's not a new script (address 0)
    if not script_data.is_new_script then
      final_overrides_map[map_key] = buffer_address
    end
    local binary_data = script_data.binary_data
    local lua_adjustments = script_data.lua_adjustments

    -- Write binary data to script buffer one byte at a time
    local to_skip = 0
    for byte_index, byte_value in ipairs(binary_data) do
      if to_skip > 0 then
        to_skip = to_skip - 1
      else
        local current_offset = byte_index - 1  -- Convert to 0-based offset
        
        -- Check if we need to apply lua_adjustments at this offset
        local adjustment_applied = false
        if lua_adjustments then
          for _, adjustment in ipairs(lua_adjustments) do
            if current_offset == adjustment.offset then
              -- Find the target script's buffer address by label
              local target_label = adjustment.label
              local target_buffer_address = nil
              
              -- Search for the target label in script_overrides_map
              for target_map_key, target_data in pairs(script_overrides_map) do
                if target_data.label == target_label then
                  target_buffer_address = buffer_addresses[target_map_key]
                  break
                end
              end
              
              if target_buffer_address then
                -- Calculate the final address (target buffer address + address_offset)
                local final_address = target_buffer_address + adjustment.address_offset
                
                -- Write the address in little endian format (4 bytes)
                emu.memory.cart0:write8(SCRIPT_BUFFER + buffer_index, final_address & 0xFF)
                emu.memory.cart0:write8(SCRIPT_BUFFER + buffer_index + 1, (final_address >> 8) & 0xFF)
                emu.memory.cart0:write8(SCRIPT_BUFFER + buffer_index + 2, (final_address >> 16) & 0xFF)
                emu.memory.cart0:write8(SCRIPT_BUFFER + buffer_index + 3, (final_address >> 24) & 0xFF)
                
                buffer_index = buffer_index + 4
                adjustment_applied = true
                
                -- Skip the next 3 bytes in the loop since we wrote 4 bytes total
                to_skip = 3
                break
              end
            end
          end
        end
      
        -- If no adjustment was applied, write the original byte
        if not adjustment_applied then
          emu.memory.cart0:write8(SCRIPT_BUFFER + buffer_index, byte_value)
          buffer_index = buffer_index + 1
        end
      end
    end
  end
  -- Calculate buffer usage percentage
  local buffer_used_percentage = (buffer_index / SCRIPT_BUFFER_SIZE) * 100
  local buffer_used_kb = buffer_used_percentage / 100 * SCRIPT_BUFFER_SIZE / 1024
  
  -- Replace script_overrides_map with final addresses
  script_overrides_map = final_overrides_map

  -- Calculate script overrides remaining (after final_overrides_map excludes address 0)
  local overrides_used = 0
  for _ in pairs(script_overrides_map) do
    overrides_used = overrides_used + 1
  end
  local overrides_remaining = SCRIPT_OVERRIDES_SIZE - overrides_used
  
  console:log(string.format("[+] All scripts written to buffer (%.1fkb / %.1fkb, %.1f%% used; %d scripts remaining)",
    buffer_used_kb, SCRIPT_BUFFER_SIZE / 1024, buffer_used_percentage, overrides_remaining))

  -- Mark end of buffer
  emu.memory.cart0:write8(SCRIPT_BUFFER + SCRIPT_BUFFER_SIZE - 1, 0xFF)

  -- Write script overrides to memory
  -- console:log("== Script Overrides ==")
  local override_index = 0
  for map_key, buffer_address in pairs(script_overrides_map) do
    -- script_overrides_map now only contains override scripts (not new scripts)
    -- For override scripts, map_key is the hex address, so convert back to number
    local key = tonumber(map_key, 16)
    write_script_override(override_index, key, buffer_address)
    -- console:log("  0x" .. map_key .. " -> 0x" .. string.format("%x", buffer_address))
    override_index = override_index + 1
  end

  emu:write32(SCRIPT_INITIALIZED, 1)
end

-- Socket helper functions
function socket_stop(id)
  local sock = sockets[id]
  sockets[id] = nil
  if sock then
    sock:close()
  end
end

function socket_format(id, msg, isError)
  local prefix = "Socket " .. id
  if isError then
    prefix = "[-] " .. prefix .. " Error: "
  else
    prefix = "[+] " .. prefix .. " Received: "
  end
  return prefix .. msg
end

function socket_error(id, err)
  -- Don't log errors for normal disconnections (when client closes connection)
  if err ~= socket.ERRORS.DISCONNECTED then
    console:error(socket_format(id, err, true))
  end
  socket_stop(id)
end

function socket_received(id)
  local sock = sockets[id]
  if not sock then return end
  while true do
    local p, err = sock:receive(1024)
    if p then
      local message = p:match("^(.-)%s*$")
      -- console:log(socket_format(id, message))

      -- Check notification type
      if message == "PROCESSING" then
        console:log(os.date("\n[%H:%M:%S]"))
        console:log("[+] Porylive is processing new changes...")
      elseif message == "RELOAD" then
        console:log("[+] Processing complete. Loading new changes...")
        reload()
      end
      -- Close the socket after processing RELOAD to avoid error messages
      socket_stop(id)
      return
    else
      if err ~= socket.ERRORS.AGAIN then
        -- Only log error if it's not a normal disconnection
        if err ~= socket.ERRORS.DISCONNECTED then
          console:error(socket_format(id, err, true))
        end
        socket_stop(id)
      end
      return
    end
  end
end

function socket_accept()
  local sock, err = server:accept()
  if err then
    console:error(socket_format("Accept", err, true))
    return
  end
  local id = nextID
  nextID = id + 1
  sockets[id] = sock
  sock:add("received", function() socket_received(id) end)
  sock:add("error", function(socket_err) socket_error(id, socket_err) end)
  -- console:log(socket_format(id, "Connected"))
end

-- Initialize socket server
function init_socket_server()
  local port = LISTEN_PORT
  server = nil
  while not server do
    server, err = socket.bind(nil, port)
    if err then
      if err == socket.ERRORS.ADDRESS_IN_USE then
        port = port + 1
        if port > LISTEN_PORT + 10 then
          console:error("[-] Could not bind to any port near " .. LISTEN_PORT)
          break
        end
      else
        console:error("[-] Bind Error: " .. tostring(err))
        break
      end
    else
      local ok
      ok, err = server:listen()
      if err then
        server:close()
        console:error("[-] Listen Error: " .. tostring(err))
      else
        console:log("[+] Listening on port " .. port .. " for updates")
        server:add("received", socket_accept)
      end
    end
  end
end

console:log("======== Porylive initialized ========")
console:log("Make sure to run `make live` in your decomp project to start live script editing.\n")


-- Start Porylive
function start_porylive(path_to_project)
  if path_to_project == nil then
    console:error("[-] No path to project provided")
    return
  end

  -- Detect if we're running on Windows
  is_windows = path_to_project:match("^[a-zA-Z]:/") ~= nil

  local success = setup_project_paths(path_to_project)
  if not success then
    console:error("[-] Failed to setup project paths")
    return
  end
  if emu == nil then
    console:log("[-] Please load your GBA ROM to before using Porylive")
  end
  init_socket_server()
end

-- Use mGBA's script.dir to determine paths
-- Remove the last two directory components (tools/porylive) to get project root
local auto_project_root = script.dir:match("(.*)/[^/]+/[^/]+/?$") or script.dir:match("(.*)[/\\][^/\\]+[/\\][^/\\]+[/\\]?$")
if not auto_project_root then
  auto_project_root = script.dir .. "/../../"
end

callbacks:add("reset", reload)

start_porylive(auto_project_root)

-- emu:setWatchpoint(handle_script_override, SCRIPT_WAITING, C.WATCHPOINT_TYPE.WRITE)
-- callbacks:add("frame", handle_script_override)
