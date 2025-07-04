import os
import subprocess
import sys
from pathlib import Path
from .logger import Logger

class BuildManager:
    """Handles build processes and external tool execution"""

    def __init__(self, logger: Logger, project_dir: Path):
        self.logger = logger
        self.project_dir = project_dir

    def try_process_poryscript_file(self, pory_file_path: Path):
        """Attempt to invoke tools/poryscript to process a .pory file"""
        filename = pory_file_path.name
        try:
            self.logger.log_message(f"Processing pory file: {filename}")
            result = subprocess.run(
                [
                    "tools/poryscript/poryscript",
                    "-cc", "tools/poryscript/command_config.json",
                    "-fc", "tools/poryscript/font_config.json",
                    "-i", pory_file_path,
                    "-o", pory_file_path.with_suffix(".inc"),
                ],
                check=True,
                capture_output=True,
                cwd=self.project_dir
            )
            if result.stderr:
                error_message = result.stderr.decode('utf-8').strip().split('\n')
                error_message.insert(0, f"Error while processing {pory_file_path}:")
                self.logger.log_message(*error_message)
                sys.exit(1)
        except subprocess.CalledProcessError as e:
            error_message = e.stderr.decode('utf-8').strip().split('\n')
            error_message.insert(0, f"Error while processing {pory_file_path}:")
            self.logger.log_message(*error_message)
            sys.exit(1)

    def run_make_live_update(self, build_dir: Path) -> bool:
        """Run make live-update command"""
        env = os.environ.copy()
        if "modern" in str(build_dir.name):
            env["MODERN"] = "1"

        try:
            result = subprocess.run(
                ["make", "live-update"],
                check=True,
                capture_output=True,
                env=env,
                cwd=self.project_dir
            )
            if result.stderr:
                # Convert result.stderr from bytes to string
                error_message = result.stderr.decode('utf-8').strip().split('\n')
                error_message.insert(0, "Error while assembling scripts:")
                self.logger.log_message(*error_message)
                sys.exit(1)
            return True

        except subprocess.CalledProcessError as e:
            self.logger.log_message(f"make live-update failed with return code {e.returncode}")
            if e.stdout:
                self.logger.log_message(f"stdout: {e.stdout}")
            if e.stderr:
                self.logger.log_message(f"stderr: {e.stderr}")
            sys.exit(1)
