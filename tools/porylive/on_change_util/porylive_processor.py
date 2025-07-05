import sys
import time
from pathlib import Path
from typing import Optional, Set
from .logger import Logger
from .config import ConfigManager
from .map_file import MapFileManager
from .build_manager import BuildManager
from .script_differ import ScriptDiffer
from .macro_processor import MacroProcessor
from .lst_parser import LSTParser
from .file_manager import FileManager
from .notification import NotificationManager
from .porylive_types import SUPPORTED_FILES

class PoryliveProcessor:
    """Main processor that orchestrates all porylive operations"""

    def __init__(self, project_dir: Path, porylive_dir: Path, profiling: bool = False):
        # Initialize logger first
        self.logger = Logger(project_dir, profiling)

        # Initialize all components
        self.config_manager = ConfigManager(project_dir, porylive_dir, self.logger)
        self.map_file_manager = MapFileManager(self.logger, self.config_manager.project_dir)
        self.build_manager = BuildManager(self.logger, self.config_manager.project_dir)
        self.script_differ = ScriptDiffer(self.logger, self.config_manager)
        self.macro_processor = MacroProcessor(self.logger, self.config_manager, self.map_file_manager)
        self.lst_parser = LSTParser(self.logger, self.map_file_manager, self.macro_processor)
        self.file_manager = FileManager(self.logger)
        self.notification_manager = NotificationManager(self.logger)

    def determine_selected_file(self, updated_file: Optional[str]) -> Optional[str]:
        """Determine which supported file to process based on the updated file"""
        if not updated_file:
            return None

        # If the file ends with .inc, use event_scripts.s
        if updated_file.endswith('.inc'):
            return 'data/event_scripts.s'

        # Try to match with supported files by comparing the relative path
        for supported_file in SUPPORTED_FILES:
            if updated_file.endswith(supported_file):
                return supported_file

        return None

    def validate_build_environment(self) -> bool:
        """Validate that the build environment is ready"""
        build_dir = self.config_manager.build_dir
        if not build_dir.exists() or not any(build_dir.iterdir()):
            self.logger.log_message(f"{build_dir} directory does not exist or is empty - run make live first")
            return False
        return True

    def process_file(self, updated_file: Optional[str]) -> bool:
        """Process a single file update"""
        main_start = time.perf_counter()
        self.logger.log_profiling("Starting main function")

        # Skip initial watchman trigger
        if len(sys.argv) > 2:
            return True

        # Write arguments to log
        _args = ["Script invoked with arguments:"]
        for i, arg in enumerate(sys.argv):
            _args.append(f"  argv[{i}]: {arg}")
        self.logger.log_message(*_args)

        # Load configuration
        self.config_manager.load_porylive_config()

        # If the file ends with .pory, try to process it with poryscript
        if updated_file and updated_file.endswith('.pory'):
            self.build_manager.try_process_poryscript_file(self.config_manager.project_dir / updated_file)
            return True

        # Load map file
        self.map_file_manager.load_sym_file()

        # Determine which supported file to process
        selected_file = self.determine_selected_file(updated_file)

        # Exit early if no matching file found
        if not selected_file:
            self.logger.log_message(f"File not supported with porylive: {updated_file}")
            return False

        # Validate build environment
        if not self.validate_build_environment():
            return False

        self.notification_manager.send_processing()

        # Set up file paths based on selected file
        # Generate .lst file paths by replacing .s with .live.lst and .o.lst
        base_path = str(selected_file).replace('.s', '')
        build_dir = self.config_manager.build_dir
        src_lst_live = build_dir / (base_path + '.live.lst')
        src_lst_old = build_dir / (base_path + '.lst')

        # Run make live-update
        make_start = time.perf_counter()
        self.build_manager.run_make_live_update(build_dir)
        make_end = time.perf_counter()
        self.logger.log_profiling(f"make live-update took {make_end - make_start:.4f}s")

        # Get updated scripts
        scripts_start = time.perf_counter()
        updated_scripts, needs_macro_adjustment = self.script_differ.get_updated_scripts(src_lst_old, src_lst_live, selected_file)
        scripts_end = time.perf_counter()
        self.logger.log_profiling(f"get_updated_scripts took {scripts_end - scripts_start:.4f}s")

        global_state = self.script_differ.global_state

        if len(global_state['new_script_labels']) > 0:
            self.logger.log_message(f"Found {len(updated_scripts)} updated script(s) and {len(global_state['new_script_labels'])} new script(s)")
        else:
            self.logger.log_message(f"Found {len(updated_scripts)} updated script(s)")

        # Parse LST file
        parse_start = time.perf_counter()
        new_routines = {}
        if len(updated_scripts) > 0:
            new_routines = self.lst_parser.parse_lst(
                src_lst_live,
                updated_scripts,
                selected_file,
                needs_macro_adjustment,
                global_state['used_global_labels'],
                global_state['new_script_labels']
            )
        parse_end = time.perf_counter()
        self.logger.log_profiling(f"parse_lst took {parse_end - parse_start:.4f}s")

        # Create output directory and clean it
        changed_output_path = build_dir / "bin/" / base_path
        self.file_manager.cleanup_output_directory(changed_output_path)

        # Load existing generated files
        generated_files = self.file_manager.load_generated_files_json(build_dir / "porylive_generated_files.json")
        generated_files[selected_file] = []

        # Write binary files
        file_infos = self.file_manager.write_binary_files(new_routines, changed_output_path, selected_file)
        generated_files[selected_file] = file_infos

        # Write JSON and Lua files
        self.file_manager.write_generated_files_json(generated_files, build_dir / "porylive_generated_files.json")
        self.file_manager.write_generated_files_lua(generated_files, build_dir / "porylive_generated_files.lua")

        self.notification_manager.send_reload()

        main_end = time.perf_counter()
        total_main_time = main_end - main_start
        self.logger.log_profiling(f"main function total time: {total_main_time:.4f}s")

        return True
