#!/usr/bin/env python3
"""
Porylive On-Change Script - Refactored Version

This is the main entry point for the porylive system that processes
modified scripts and notifies the Lua script to update the script data
in the running emulator.
"""

import sys
import os
from pathlib import Path

# Import after path modification
from on_change_util.porylive_processor import PoryliveProcessor

# Constants
PROFILING = False

def main():
    """Main entry point for the porylive on-change script"""
    # Get the porylive_util directory
    porylive_dir = Path(__file__).parent

    # Check for custom project directory from environment variable
    custom_project_dir = os.getenv('PORYLIVE_PROJECT_DIR')
    if custom_project_dir:
        project_dir = Path(custom_project_dir)
    else:
        # Fall back to default behavior
        project_dir = porylive_dir.parent.parent

    try:
        # Initialize the processor
        processor = PoryliveProcessor(project_dir, porylive_dir, PROFILING)

        # Get the updated file from command line arguments
        updated_file = sys.argv[1] if len(sys.argv) > 1 else None

        # Process the file
        success = processor.process_file(updated_file)

        if not success:
            sys.exit(1)

    except Exception as e:
        # If we have a processor with a logger, use it; otherwise use basic logging
        try:
            processor.logger.log_message(f"Error: {e}")
        except:
            print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
