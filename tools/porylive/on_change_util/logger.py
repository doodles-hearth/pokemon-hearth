import time
from datetime import datetime
from pathlib import Path
from typing import Optional

class Logger:
    """Handles all logging functionality for porylive"""

    def __init__(self, project_dir: Path, profiling: bool = False):
        self.project_dir = project_dir
        self.profiling = profiling
        self.log_file_path = project_dir / ".porylive" / "porylive_on_change.log"

    def log_message(self, *args):
        """Log a message to porylive_watchman.log with timestamp. The file should be created by the Makefile"""
        timestamp = datetime.now().strftime("%H:%M:%S")
        with open(self.log_file_path, "a") as f:
            if args:
                # First argument gets timestamp, rest are joined with newline + 18 spaces
                if len(args) == 1:
                    f.write(f"[{timestamp}] {args[0]}\n")
                else:
                    _spaces = " " * 11
                    additional_args = f"\n{_spaces}".join(str(arg) for arg in args[1:])
                    f.write(f"[{timestamp}] {args[0]}\n{_spaces}{additional_args}\n")
            else:
                f.write(f"[{timestamp}] \n")

    def log_profiling(self, message: str):
        """Log a profiling message with [PROFILE] prefix"""
        if not self.profiling:
            return
        self.log_message(f"[PROFILE] {message}")

    def enable_profiling(self):
        """Enable profiling logs"""
        self.profiling = True

    def disable_profiling(self):
        """Disable profiling logs"""
        self.profiling = False
