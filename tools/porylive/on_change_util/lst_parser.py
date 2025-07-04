from pathlib import Path
from typing import Dict, Set
from .logger import Logger
from .map_file import MapFileManager
from .macro_processor import MacroProcessor
from .porylive_types import RoutineData, ScriptParams

class LSTParser:
    """Handles LST file parsing and routine extraction"""

    def __init__(self, logger: Logger, map_file_manager: MapFileManager, macro_processor: MacroProcessor):
        self.logger = logger
        self.map_file_manager = map_file_manager
        self.macro_processor = macro_processor

    def parse_lst(self, lst_path: Path, updated_scripts: Set[str], src_file: str,
                  needs_macro_adjustment: bool, used_global_labels: Set[str],
                  new_script_labels: Set[str]) -> Dict[str, RoutineData]:
        """Parse LST file and extract routine data"""
        routines = {}
        current_script = None

        started_parsing = False
        found_label = False  # Flag to track if we just found a label
        is_updated = False

        # All scripts that need to be processed
        scripts_to_process = new_script_labels.union(used_global_labels).union(updated_scripts)

        with open(lst_path) as f:
            for line in f:
                line = line.rstrip()

                # Wait for the .section line before starting to parse
                if not started_parsing:
                    if '.section script_data,"aw",%progbits' in line:
                        started_parsing = True
                    continue

                # Skip empty lines and form feed characters
                if not line or line.startswith("\x0c"):
                    continue

                # Skip . operations like .macro and .set
                line_parts = line.split()
                if len(line_parts) > 1 and line_parts[1].startswith('.'):
                    continue

                # Check for label line - it will have a colon and start with spaces followed by a number
                if ':' in line and line.lstrip().split()[0].isdigit():
                    # Extract label name - it's the part before the colon, after the number
                    _label = line.split(':')[0].split()[-1]

                    # Store the previous script if it exists and needs processing
                    if current_script and current_script["label"] in scripts_to_process:
                        routines[current_script["label"]] = {
                            'scripts': current_script["scripts"],
                            'starting_offset': current_script["offset"],
                            'original_address': self.map_file_manager.get_sym_file_address(current_script["label"]),
                        }

                    # Start new script
                    current_script = {
                        "label": _label,
                        "scripts": [],
                        "offset": 0,
                    }
                    found_label = True  # Set flag that we found a label
                    if _label in updated_scripts:
                        current_script["data"] = bytearray()  # Reset to empty bytearray
                        is_updated = True
                    else:
                        current_script["data"] = None
                        is_updated = False
                elif current_script and line:
                    if not needs_macro_adjustment and not is_updated:
                        continue
                    parts = line.split(';')[0].split()
                    if len(parts) >= 4 and is_updated:
                        _name = parts[3]
                        _params_joined = ",".join(parts[4:])
                        _params = _params_joined.split(",") if len(parts) >= 5 else []
                        current_script["scripts"].append({
                            "name": _name,
                            "params": _params,
                            "data": bytearray(),
                        })
                    if len(parts) >= 2:
                        if found_label:
                            try:
                                current_script["offset"] = int(parts[1], 16)
                            except ValueError:
                                continue
                            found_label = False  # Reset the flag
                        # For lines with 2 parts, hex data is in part 2
                        # For lines with 3+ parts, hex data is in part 3
                        hex_data = parts[2] if len(parts) >= 3 else parts[1]
                        # Only add if it contains valid hex characters
                        if all(c in "0123456789abcdef" for c in hex_data.lower()) and current_script["scripts"]:
                            # Convert hex pairs to bytes and add to current script's data
                            for i in range(0, len(hex_data), 2):
                                byte_value = int(hex_data[i:i+2], 16)
                                current_script["scripts"][-1]["data"].append(byte_value)

        # Store the final script if it exists
        if current_script and current_script["label"] in scripts_to_process:
            routines[current_script["label"]] = {
                'starting_offset': current_script["offset"],
                'scripts': current_script["scripts"],
                'original_address': self.map_file_manager.get_sym_file_address(current_script["label"]),
            }

        # Process routines to adjust data from macros
        for label, routine in routines.items():
            if len(routine["scripts"]) == 0:
                continue
            data = bytearray()
            lua_adjustments = []
            for script in routine["scripts"]:
                if needs_macro_adjustment:
                    script_data, _lua_adjustments = self.macro_processor.adjust_data_from_macro(
                        routines, script, src_file, new_script_labels, updated_scripts)
                    for adjustment in _lua_adjustments:
                        adjustment["offset"] += len(data)
                        lua_adjustments.append(adjustment)
                else:
                    script_data = script["data"]
                data.extend(script_data)
            routines[label]["data"] = bytes(data)
            routines[label]["lua_adjustments"] = lua_adjustments

        # Filter out routines that don't have any scripts
        routines = {k: v for k, v in routines.items() if v["scripts"]}
        return routines
