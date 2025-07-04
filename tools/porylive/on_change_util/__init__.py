"""
Porylive - Live script updating system for Pokémon ROM hacking

This package provides the processing logic for updated script
files and notifies the Lua script to update the script data
in the running emulator.
"""

from .porylive_processor import PoryliveProcessor
from .logger import Logger
from .config import ConfigManager
from .map_file import MapFileManager
from .build_manager import BuildManager
from .script_differ import ScriptDiffer
from .macro_processor import MacroProcessor
from .lst_parser import LSTParser
from .file_manager import FileManager
from .notification import NotificationManager

__version__ = "1.0.0"
__all__ = [
    "PoryliveProcessor",
    "Logger",
    "ConfigManager",
    "MapFileManager",
    "BuildManager",
    "ScriptDiffer",
    "MacroProcessor",
    "LSTParser",
    "FileManager",
    "NotificationManager",
]
