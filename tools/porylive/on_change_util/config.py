import json
import re
from pathlib import Path
from typing import Dict, Optional
from .logger import Logger

class ConfigManager:
    """Handles configuration loading and path management"""

    def __init__(self, project_dir: Path, porylive_dir: Path, logger: Logger):
        self.project_dir = project_dir
        self.porylive_dir = porylive_dir
        self.logger = logger

        # Configuration files
        self.config_file = self.project_dir / "build" / "porylive_config.lua"
        self.macro_data_file = self.porylive_dir / "porylive_macro_data.json"

        # Cached data
        self._build_dir: Optional[Path] = None
        self._macro_data_cache: Optional[Dict] = None

    def load_porylive_config(self) -> Path:
        """Load porylive_config.lua from the build directory and return BUILD_DIR"""
        with open(self.config_file, "r") as f:
            content = f.read()
            # Extract the current_build_dir value from the Lua file
            # Look for the pattern: current_build_dir = 'path'
            match = re.search(r"current_build_dir\s*=\s*['\"]([^'\"]+)['\"]", content)
            if match:
                self._build_dir = self.project_dir / match.group(1)
                return self._build_dir
            else:
                raise ValueError("Could not find current_build_dir in porylive_config.lua")

    @property
    def build_dir(self) -> Path:
        """Get the build directory, loading config if necessary"""
        if self._build_dir is None:
            self.load_porylive_config()
        return self._build_dir

    def load_macro_data(self) -> Dict:
        """Load macro adjustment data from JSON file"""
        if self._macro_data_cache is None:
            with open(self.macro_data_file, "r") as f:
                self._macro_data_cache = json.load(f)
        return self._macro_data_cache

    def get_macros_to_adjust(self, src_file: str) -> Dict:
        """Get macro adjustment data for a specific file"""
        macro_data = self.load_macro_data()
        return macro_data.get(src_file, {})

    @property
    def project_dir(self) -> Path:
        """Get the project root directory"""
        return self._project_dir

    @project_dir.setter
    def project_dir(self, value: Path):
        """Set the project root directory"""
        self._project_dir = value
