# Live development rules for PoryLive

# Live-specific variables
OBJ_DIR_PORYLIVE ?= $(OBJ_DIR_NAME_PORYLIVE)
DATA_ASM_BUILDDIR_PORYLIVE ?= $(OBJ_DIR_PORYLIVE)/$(DATA_ASM_SUBDIR)

# Live targets
.PHONY: live tidylive live-update live-prep

live: tidylive all live-prep
	@if [ ! -f "tools/porylive/porylive_on_change.py" ]; then \
		echo ""; \
		echo "================================================"; \
		echo "Error: tools/porylive/porylive_on_change.py not found"; \
		echo "Please download PoryLive at https://github.com/Porylive/porylive and place it in the tools/porylive directory."; \
		echo "================================================"; \
		echo ""; \
		exit 1; \
	fi
	@trap 'echo ""; echo "Cleaning up..."; cat tools/porylive/watchman_clean.json | watchman -j > /dev/null; exit 0' INT TERM; \
	mkdir -p .porylive; \
	touch .porylive/porylive_on_change.log; \
	python3 tools/porylive/porylive_get_addresses.py pokeemerald.map $(OBJ_DIR_PORYLIVE)/addresses.lua; \
	echo ""; \
	echo ""; \
	echo -e "\033[0;90m========== \033[0;36mPorylive\033[0;90m ==========="; sleep 0.01; \
	echo -e "\033[0;31m            ⢀⣀⣀⣀             "; sleep 0.01; \
	echo -e "\033[0;31m         ⣠⠤⠛⠋⠉⠉⠉⠛⢦           "; sleep 0.01; \
	echo -e "\033[0;31m       ⣠⠶⠓⠂  \033[0;37m⠠⠤⠤\033[0;31m  ⠙⣆      \033[0;36m⡠⢤ "; sleep 0.01; \
	echo -e "\033[0;31m     ⢀⢖⡃    \033[0;37m⢰ \033[0;90m⣤⡄\033[0;31m   ⣹    \033[0;36m⢠⠔⠁⣼⠇"; sleep 0.01; \
	echo -e "\033[0;36m   ⢀⡞⠉ ⠑⣄\033[0;31m   \033[0;37m⠘   \033[0;37m⠐\033[0;31m ⣠⠋  \033[0;36m⢠⠖⠉ ⢰⠏ "; sleep 0.01; \
	echo -e "\033[0;36m   ⠈⠻⢄⣀⡀⢀⡇\033[0;31m     ⢀⡠⠟⠛⢤⣀\033[0;36m⠜⠋  ⢠⠃  "; sleep 0.01; \
	echo -e "\033[0;36m    ⣠⣴⠁⢉⣽⠟⠶⠶⠶⠾⡿⠁⡇\033[0;31m    ⠳⣤\033[0;36m ⢠⠇   "; sleep 0.01; \
	echo -e "\033[0;36m   ⠰⣏⠈⠢⡎⠒⣄  ⢀⠶⢁⡠⠃\033[0;31m     ⢸\033[0;36m⣄⠎    "; sleep 0.01; \
	echo -e "\033[0;36m    ⠈⠑⣤⣧ ⠈⠑⡄⣾⣴⢋⡔⢫⡉⠉⠉⠉⠉⠙⣦     "; sleep 0.01; \
	echo -e "\033[0;36m        ⠛⣄ ⡞⢃⡴⠋  ⢙⠦⠤⠤⠤⠤⠤⢽    "; sleep 0.01; \
	echo -e "\033[0;36m         ⠈⠉⢹⣿⣀ ⢀⡴⠋    ⣀⣤⠇    "; sleep 0.01; \
	echo -e "\033[0;36m           ⢸⣇⠈⣶⠊  ⣀⣠⠤⠒⠋      "; sleep 0.01; \
	echo -e "\033[0;36m            ⠻⢤⣟⣤⠶⠛⠁          \033[0m"; sleep 0.01; \
	echo ""; sleep 0.01; \
	echo -e "\033[0;90mPress Ctrl+C to stop monitoring for changes. \033[0m"; sleep 0.1; \
	echo ""; \
	echo "Starting watchman triggers..."; \
	watchman watch . > /dev/null; \
	cat tools/porylive/watchman.json | watchman -j > /dev/null; \
	echo "Ready! Watching for changes..."; \
	tail -n 0 -F .porylive/porylive_on_change.log

tidylive:
	find $(OBJ_DIR_NAME_PORYLIVE)/data -name "*.lst" -type f -delete 2>/dev/null || true
	rm -rf $(OBJ_DIR_NAME_PORYLIVE)/bin
	rm -f $(OBJ_DIR_NAME_PORYLIVE)/porylive_generated_files.json
	rm -f $(OBJ_DIR_NAME_PORYLIVE)/porylive_generated_files.lua
	mkdir -p $(OBJ_DIR_NAME_PORYLIVE)/data

live-update:
	@for src in $(DATA_ASM_SRCS); do \
		target=$$(echo $$src | sed "s|$(DATA_ASM_SUBDIR)/|$(DATA_ASM_BUILDDIR_PORYLIVE)/|" | sed 's/\.s$$/.live.lst/'); \
		$(PREPROC) $$src charmap.txt | $(CPP) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $$src charmap.txt | $(AS) $(ASFLAGS) -alc=$$target --listing-cont-lines=10 -o /dev/null; \
	done

live-prep:
	@for src in $(DATA_ASM_SRCS); do \
		target=$$(echo $$src | sed "s|$(DATA_ASM_SUBDIR)/|$(DATA_ASM_BUILDDIR_PORYLIVE)/|" | sed 's/\.s$$/.lst/'); \
		$(PREPROC) $$src charmap.txt | $(CPP) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $$src charmap.txt | $(AS) $(ASFLAGS) -alc=$$target --listing-cont-lines=10 -o /dev/null; \
	done

# Pattern rules (only active if PORYLIVE=1)
ifeq ($(PORYLIVE),1)
$(DATA_ASM_BUILDDIR_PORYLIVE)/%.lst: $(DATA_ASM_SUBDIR)/%.s
	$(PREPROC) $< charmap.txt | $(CPP) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -alc=$@ --listing-cont-lines=10 -o /dev/null

$(DATA_ASM_BUILDDIR_PORYLIVE)/%.live.lst: $(DATA_ASM_SUBDIR)/%.s $(wildcard $(DATA_ASM_SUBDIR)/scripts/*.inc)
	$(PREPROC) $< charmap.txt | $(CPP) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -alc=$@ --listing-cont-lines=10 -o /dev/null
endif
