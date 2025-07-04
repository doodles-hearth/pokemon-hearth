import re
from pathlib import Path
from typing import TypedDict, List, Dict, Set

class ScriptParams(TypedDict):
    name: str
    params: List[str]
    data: bytearray

class RoutineData(TypedDict):
    scripts: List[ScriptParams]
    starting_offset: int

class MacroAdjustmentInfo(TypedDict):
    index: int
    offset: int
    type: str
    add: int

class LuaAdjustment(TypedDict):
    label: str
    offset: int
    address_offset: int

class GeneratedFileInfo(TypedDict):
    label: str
    address: int
    filename: str
    lua_adjustments: List[LuaAdjustment]

# Constants
SECTION_PATTERN = re.compile(r'\.section script_data,"aw",%progbits')

# Supported files for porylive processing
SUPPORTED_FILES = [
    'data/battle_anim_scripts.s',
    'data/event_scripts.s'
]

# Global state types (these will be managed by appropriate classes)
GlobalState = TypedDict('GlobalState', {
    'new_script_labels': Set[str],
    'used_global_labels': Set[str]
})
