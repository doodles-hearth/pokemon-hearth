import re
import sys
from typing import Dict, List, Tuple, Any, Union
from .logger import Logger
from .config import ConfigManager
from .map_file import MapFileManager
from .conditional_processor import ConditionalProcessor
from .porylive_types import ScriptParams, RoutineData, LuaAdjustment

class MacroProcessor:
    """Handles macro adjustments for script data"""

    def __init__(self, logger: Logger, config_manager: ConfigManager, map_file_manager: MapFileManager):
        self.logger = logger
        self.config_manager = config_manager
        self.map_file_manager = map_file_manager
        self.conditional_processor = ConditionalProcessor(logger)

    def _find_matching_macro(self, script_name: str, macros_to_adjust: Dict[str, Any]) -> Any:
        """Find a macro definition that matches the script name, supporting both exact matches and regex patterns

        Returns:
            The macro_info if found, None otherwise
        """
        # First try exact match
        if script_name in macros_to_adjust:
            return macros_to_adjust[script_name]

        # Then try regex patterns (indicated by $() syntax)
        for macro_key, macro_info in macros_to_adjust.items():
            if macro_key.startswith("$(") and macro_key.endswith(")"):
                # Extract the regex pattern (remove $( and ))
                pattern = macro_key[2:-1]
                try:
                    if re.match(pattern, script_name):
                        return macro_info
                except re.error as e:
                    self.logger.log_message(f"[_find_matching_macro] Invalid regex pattern '{pattern}': {e}")
                    continue

        return None

    def _resolve_arg_reference(self, value: Union[str, Any], script: ScriptParams) -> Any:
        """Resolve $arg[n] references in macro definitions"""
        if not isinstance(value, str):
            return value

        # Check for $arg[n] pattern
        arg_match = re.match(r'^\$arg\[(\d+)\]$', value)
        if arg_match:
            arg_index = int(arg_match.group(1))
            if arg_index < len(script["params"]):
                return script["params"][arg_index]
            else:
                self.logger.log_message(f"[_resolve_arg_reference] Argument index {arg_index} out of range for {script['name']}")
                return value

        return value

    def _resolve_macro_params(self, params: List[Any], script: ScriptParams) -> List[Any]:
        """Resolve $arg[n] references in macro parameter list"""
        resolved_params = []
        for param in params:
            resolved_params.append(self._resolve_arg_reference(param, script))
        return resolved_params

    def adjust_data_from_macro(self, routines: Dict[str, RoutineData], script: ScriptParams,
                               src_file: str, new_script_labels: set, updated_scripts: set,
                               base_offset: int = 0) -> Tuple[bytearray, List[LuaAdjustment]]:
        """Adjust script data based on macro definitions

        Args:
            base_offset: Accumulated offset from parent macro calls
            updated_scripts: Set of script labels that have been updated
        """

        def adjust_by_address(script: ScriptParams, info: Dict[str, Any], lua_adjustments: List[LuaAdjustment]):
            """Adjust script data by address lookup"""
            if "name" in info.keys():
                _name = info["name"]
            else:
                _name = script["params"][info["index"]]
            # Do not process if _name is a hex number (e.g. 0x8000000)
            if _name.startswith("0x"):
                return script["data"], []

            address = self.map_file_manager.get_sym_file_address(_name)
            if address is not None:
                if "add" in info:
                    address += info["add"]
                actual_offset = info["offset"] + base_offset
                script["data"][actual_offset:actual_offset+4] = address.to_bytes(4, "little")
            elif _name in new_script_labels:
                # Needs to be adjusted in Lua
                lua_adjustments.append({
                    "label": _name,
                    "offset": info["offset"] + base_offset,
                    "address_offset": 0,
                })
            else:
                # Exit with error
                self.logger.log_message(f"[address] Unknown symbol for {script['name']}: {_name}")
                sys.exit(1)

        def adjust_by_offset(script: ScriptParams, info: Dict[str, Any], lua_adjustments: List[LuaAdjustment]):
            """Adjust script data by offset lookup"""
            _name = script["params"][info["index"]]
            # Do not process if _name is a hex number (e.g. 0x8000000)
            if _name.startswith("0x"):
                return script["data"], []

            if _name in routines.keys():
                # Check if label is new OR has been updated
                if _name in new_script_labels or _name in updated_scripts:
                    # Needs to be adjusted in Lua
                    lua_adjustments.append({
                        "label": _name,
                        "offset": info["offset"] + base_offset,
                        "address_offset": 0,
                    })
                else:
                    # Get the address directly from the child script
                    address = routines[_name].get('original_address')
                    if address is not None:
                        actual_offset = info["offset"] + base_offset
                        script["data"][actual_offset:actual_offset+4] = address.to_bytes(4, "little")
                    else:
                        # Exit with error
                        self.logger.log_message(f"[offset] No address found for script: {_name}")
                        sys.exit(1)
            else:
                # Check if _name exists in map file before erroring
                address = self.map_file_manager.get_sym_file_address(_name)
                if address is not None:
                    if "add" in info:
                        address += info["add"]
                    actual_offset = info["offset"] + base_offset
                    script["data"][actual_offset:actual_offset+4] = address.to_bytes(4, "little")
                else:
                    # Exit with error
                    self.logger.log_message(f"[offset] Unknown symbol for {script['name']}: {_name}")
                    sys.exit(1)

        macros_to_adjust = self.config_manager.get_macros_to_adjust(src_file)

        # Find matching macro (exact or regex)
        macro_info = self._find_matching_macro(script["name"], macros_to_adjust)

        lua_adjustments: List[LuaAdjustment] = []

        if not macro_info:
            return script["data"], []

        # Determine which adjustments to apply
        if isinstance(macro_info, dict) and ("$condition" in macro_info or "$if" in macro_info):
            # Handle conditional macros
            adjustments = self.conditional_processor.process_conditional_macro(script, macro_info)
        elif isinstance(macro_info, list):
            # Handle non-conditional macros (when macro_info is a list)
            adjustments = macro_info
        else:
            # Exit with error
            self.logger.log_message(f"[adjust_data_from_macro] Unknown macro_info type for {script['name']}: {macro_info}")
            sys.exit(1)

        # Process all adjustments
        for info in adjustments:
            if info["type"] == "macro":
                # Resolve macro name from $arg[n] if necessary
                macro_name = self._resolve_arg_reference(info["name"], script)

                # Resolve macro parameters from $arg[n] references
                if "param_len" in info:
                    params = [0] * info["param_len"]
                else:
                    params = self._resolve_macro_params(info["params"], script)

                # Get the offset for this macro and add it to the accumulated base_offset
                macro_offset = info.get("offset", 0)
                accumulated_offset = base_offset + macro_offset

                # Recursively process the macro with the accumulated offset
                script["data"], _lua_adjustments = self.adjust_data_from_macro(routines, {
                    "name": macro_name,
                    "params": params,
                    "data": script["data"],
                }, src_file, new_script_labels, updated_scripts, accumulated_offset)

                lua_adjustments.extend(_lua_adjustments)
            elif "index" in info.keys() and info["index"] >= len(script["params"]):
                continue
            elif info["type"] == "address":
                # Replace 32 bits starting at info["offset"] with the address from the map file
                adjust_by_address(script, info, lua_adjustments)
            elif info["type"] == "offset":
                # Find the script directly in routines
                adjust_by_offset(script, info, lua_adjustments)
            elif info["type"] == "dynamic":
                # Check if the 4 bytes to overwrite are all 0
                actual_offset = info["offset"] + base_offset
                if script["data"][actual_offset:actual_offset+4] == b"\x00\x00\x00\x00":
                    # Replace with the address of the script
                    adjust_by_address(script, info, lua_adjustments)
                else:
                    adjust_by_offset(script, info, lua_adjustments)

        return script["data"], lua_adjustments
