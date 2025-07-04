import json
import time
from pathlib import Path
from typing import Dict, List
from .logger import Logger
from .porylive_types import GeneratedFileInfo, RoutineData

class FileManager:
    """Handles file I/O operations for porylive"""

    def __init__(self, logger: Logger):
        self.logger = logger

    def cleanup_output_directory(self, output_dir: Path):
        """Delete all files in the output directory"""
        cleanup_start = time.perf_counter()
        if output_dir.exists():
            for file in output_dir.iterdir():
                file.unlink()
        cleanup_end = time.perf_counter()
        self.logger.log_profiling(f"File cleanup took {cleanup_end - cleanup_start:.4f}s")

    def load_generated_files_json(self, json_path: Path) -> Dict[str, List[GeneratedFileInfo]]:
        """Load the generated files JSON, creating empty dict if file doesn't exist"""
        json_load_start = time.perf_counter()
        generated_files: Dict[str, List[GeneratedFileInfo]] = {}

        try:
            with open(json_path, "r") as f:
                generated_files = json.load(f)
        except FileNotFoundError:
            pass
        except json.JSONDecodeError:
            pass

        json_load_end = time.perf_counter()
        self.logger.log_profiling(f"JSON load took {json_load_end - json_load_start:.4f}s")
        return generated_files

    def write_binary_files(self, routines: Dict[str, RoutineData], output_dir: Path,
                          selected_file: str) -> List[GeneratedFileInfo]:
        """Write binary files from routines and return file info list"""
        file_write_start = time.perf_counter()

        # Create output directory if it doesn't exist
        output_dir.mkdir(parents=True, exist_ok=True)

        file_infos: List[GeneratedFileInfo] = []

        for label, data in routines.items():
            if data['data'] is None:
                continue

            # Create filename with label and starting offset
            filename = f"{label}-{data['original_address'] if data['original_address'] else '0'}.bin"
            output_path = output_dir / filename

            # Write binary data to file
            output_path.write_bytes(data['data'])
            self.logger.log_message(f"Wrote {filename}")

            # Add to generated files list
            file_infos.append({
                'label': label,
                'address': data['original_address'],
                'filename': str(output_path),
                'lua_adjustments': data['lua_adjustments'],
            })

        file_write_end = time.perf_counter()
        self.logger.log_profiling(f"Binary file writing took {file_write_end - file_write_start:.4f}s")
        return file_infos

    def write_generated_files_json(self, generated_files: Dict[str, List[GeneratedFileInfo]],
                                  json_path: Path):
        """Write the generated files JSON"""
        json_write_start = time.perf_counter()
        with open(json_path, "w") as f:
            json.dump(generated_files, f)
        json_write_end = time.perf_counter()
        self.logger.log_profiling(f"JSON write took {json_write_end - json_write_start:.4f}s")

    def write_generated_files_lua(self, generated_files: Dict[str, List[GeneratedFileInfo]],
                                 lua_path: Path):
        """Write the generated files list to porylive_generated_files.lua"""
        lua_write_start = time.perf_counter()

        with open(lua_path, 'w') as f:
            f.write("return {\n")
            for file_group in generated_files.keys():
                for file_info in generated_files[file_group]:
                    f.write(f"  {{\n")
                    f.write(f"    label = \"{file_info['label']}\",\n")
                    f.write(f"    address = {file_info['address']},\n")
                    f.write(f"    filename = \"{file_info['filename']}\",\n")
                    if 'lua_adjustments' in file_info.keys():
                        f.write( "    lua_adjustments = {\n")
                        for adjustment in file_info['lua_adjustments']:
                            f.write(f"      {{\n")
                            f.write(f"        label = \"{adjustment['label']}\",\n")
                            f.write(f"        offset = {adjustment['offset']},\n")
                            f.write(f"        address_offset = {adjustment['address_offset']},\n")
                            f.write(f"      }},\n")
                        f.write(f"    }},\n")
                    f.write(f"  }},\n")
            f.write("}\n")

        lua_write_end = time.perf_counter()
        self.logger.log_profiling(f"Lua file write took {lua_write_end - lua_write_start:.4f}s")
        self.logger.log_message(f"Wrote porylive_generated_files.lua")
