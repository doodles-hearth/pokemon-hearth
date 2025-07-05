import sys
from pathlib import Path
from typing import Dict, List, Optional
from .logger import Logger

class MapFileManager:
    """Handles sym file operations and address lookups"""

    def __init__(self, logger: Logger, project_dir: Path):
        self.logger = logger
        self.project_dir = project_dir
        self._sym_file_lines: Optional[List[str]] = None
        self._address_cache: Dict[str, int] = {}
        self._current_sym_file: Optional[Path] = None

    def find_most_recent_sym_file(self) -> Path:
        """Find the most recently modified .sym file in the project directory"""
        sym_files = list(self.project_dir.glob("**/*.sym"))
        if not sym_files:
            self.logger.log_message("Error: No .sym files found in project directory")
            sys.exit(1)
        # Sort by modification time, most recent first
        most_recent = max(sym_files, key=lambda p: p.stat().st_mtime)
        self.logger.log_message(f"Using sym file: {most_recent}")
        return most_recent

    def load_sym_file(self, sym_file_path: Optional[Path] = None):
        """Load the sym file into memory"""
        if sym_file_path is None:
            sym_file_path = self.find_most_recent_sym_file()

        self._current_sym_file = sym_file_path
        with open(sym_file_path, "r") as f:
            self._sym_file_lines = f.readlines()

        # Clear the cache when loading a new sym file
        self._address_cache.clear()

    def get_sym_file_address(self, variable_name: str) -> Optional[int]:
        """Get the address of a variable from the sym file"""
        if self._sym_file_lines is None:
            self.load_sym_file()

        # Check cache first
        if variable_name in self._address_cache:
            return self._address_cache[variable_name]

        # Search in sym file
        # Format: <hex_address> <g|l> <size> <symbol_name>
        for line in self._sym_file_lines:
            parts = line.strip().split()
            if len(parts) >= 4 and parts[3] == variable_name:
                # Extract the address (first part, already in hex without 0x prefix)
                address_hex = parts[0]
                self._address_cache[variable_name] = int(address_hex, 16)
                return self._address_cache[variable_name]

        return None

    def clear_cache(self):
        """Clear the address cache"""
        self._address_cache.clear()

    @property
    def current_sym_file(self) -> Optional[Path]:
        """Get the currently loaded sym file path"""
        return self._current_sym_file
