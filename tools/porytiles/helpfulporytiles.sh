#!/bin/bash

# CUSTOM PATHS

# "it’s meant to be a very rag-tag way of getting the filepath of the project directory no matter what machine it’s on"
# case $0 in
#   /*) script_path=$0 ;;
#   *) script_path=$(pwd)/$0 ;;
# esac

dir_project="/home/purrfectdoodle/romhack/pokemon-hearth/"
porytiles_dir="${dir_project}tools/porytiles/"

## WSL PATHS
dir_compiled_primary="${dir_project}data/tilesets/primary/"
dir_compiled_secondary="${dir_project}data/tilesets/secondary/"
metatile_behaviors="${dir_project}include/constants/metatile_behaviors.h"
dir_raw_tilesets="${porytiles_dir}_raw_tilesets/"
dir_raw_tilesets_primary="${dir_raw_tilesets}primary/"
dir_raw_tilesets_secondary="${dir_raw_tilesets}secondary/"
dir_aseprite_folder="/mnt/c/Program Files/"
normalize_py="${porytiles_dir}normalize.py"

## WINDOWS PATH
dir_aseprite_raw_tilesets="\\wsl.localhost\Ubuntu\home\purrfectdoodle\romhack\pokemon-hearth\tools\porytiles\_raw_tilesets\" 

# END OF CUSTOM PATHS

lastcmd=""
doubleconfirm="1"

attribute_generation=""
mostrar_menu() {
    echo 
    echo "PORYTILES HELPER MENU"
    echo "What to do?"
    echo "1. Compile primary"
    echo "2. Compile secondary"
    echo "3. Decompile primary" 
    echo "4. Decompile secondary"
    echo "5. Repeat last command (avoid unless certain what this does)"
    echo "6. Toggle double confirmation while compiling"
    echo "7. Edit current paths"
    echo "8. Bulk recompile secondary tilesets"
    echo -n "9. Toggle -disable-attribute-generation ON/OFF (Currently: "
    if [ "$attribute_generation" = "" ]; then
        echo "OFF)"
    else
        echo "ON)"
    fi
    echo "0. Exit"
    read -p "Choose an option: " opcao
}

# VARIABLES OUTSIDE OF THE LOOP FOR PRE-SET UP & OPTION 5
tileset=""
tilesetsrc=""
tilesetsrc2=""
while(true); do 
    mostrar_menu
    case $opcao in
        1) 
            # COMPILE PRIMARY

            echo "Remember to correctly name your layers in aseprite!"
            if [ "$tileset" != "" ]; then
                echo "Current folder of the resulting primary tileset: " $tileset
                echo "Current folder containing the .aseprite file in ${dir_raw_tilesets_primary} " $tilesetsrc
                read -p "Accept this set up? (y/n) " use
                if [ "$use" = "n" ]; then
                    read -p "Folder of the resulting primary tileset in data/tilesets: " tileset
                    read -p "folder containing the .aseprite file in ${dir_raw_tilesets_primary}: "   tilesetsrc
                else 
                    if [ "$doubleconfirm" = "1" ]; then
                        read -p "Input 'y' to confirm the current setup. " confirm
                        if [ "$confirm" != "y" ]; then
                            break
                        fi
                    fi
                fi
            else 
                    read -p "Folder of the resulting primary tileset in data/tilesets: " tileset
                    read -p "folder containing the .aseprite file in ${dir_raw_tilesets_primary}: "   tilesetsrc
            fi

            # separates each layer of the tileset into individual .png files
            "${dir_aseprite_folder}Aseprite/aseprite.exe" -b ${dir_aseprite_raw_tilesets}primary/${tilesetsrc}/tilesetase.ase --save-as ${dir_aseprite_raw_tilesets}primary/${tilesetsrc}/{layer}.png

            # check if the above cmd worked by checking if the file bottom.png exists
            if [ ! -f "${dir_raw_tilesets_primary}${tilesetsrc}/bottom.png" ]; then
                echo "Couldn't find the 'bottom.png' file. Make sure the 'tilesetase.ase' file is in the correct folder and that the layers in the .aseprite file are named correctly."

                echo "${dir_raw_tilesets_primary}${tilesetsrc}/bottom.png"
                # break the loop and go back to the main menu
                break
            fi

            # replace transparency with #ff00ff 
            python3 ${normalize_py} ${dir_raw_tilesets_primary}${tilesetsrc}/bottom.png ${dir_raw_tilesets_primary}${tilesetsrc}/bottom.png
            
            python3 ${normalize_py} ${dir_raw_tilesets_primary}${tilesetsrc}/middle.png ${dir_raw_tilesets_primary}${tilesetsrc}/middle.png

            python3 ${normalize_py} ${dir_raw_tilesets_primary}${tilesetsrc}/top.png ${dir_raw_tilesets_primary}${tilesetsrc}/top.png


            # run porytiles
            porytiles compile-primary ${attribute_generation} -Wall -o ${dir_compiled_primary}${tileset} ${dir_raw_tilesets_primary}${tilesetsrc} ${metatile_behaviors}

            lastcmd="porytiles compile-primary ${attribute_generation} -Wall -o ${dir_compiled_primary}${tileset} ${dir_raw_tilesets_primary}${tilesetsrc} ${metatile_behaviors}"

            echo "Compiled primary tileset."
            ;;
        2)
            echo "Remember to correctly name your layers in aseprite!"
            if [ "$tileset" != "" ]; then
                echo "Current folder of the resulting compiled tileset in data/tilesets: " $tileset
                echo "Current folder in ${dir_raw_tilesets_secondary} that contains the .aseprite file: "    $tilesetsrc
                echo "Current folder in ${dir_raw_tilesets_primary} for the related primary tileset: "     $tilesetsrc2
                read -p "Accept this setup? (y/n) " use
                if [ "$use" = "n" ]; then
                    read -p "Folder of the resulting compiled tileset in data/tilesets: " tileset

                    read -p "Folder in ${dir_raw_tilesets_secondary} that contains the .aseprite file: "     tilesetsrc

                    read -p "Folder in ${dir_raw_tilesets_primary} for the related primary tileset: (-1 to use cached option)"  tilesetsrc2

                    if [ "$tilesetsrc2" = "-1" ]; then
                        tilesetsrc2=$(cat "${dir_raw_tilesets_secondary}${tilesetsrc}/primarysrc.txt")
                    fi
                else 
                    if [ "$doubleconfirm" = "1" ]; then
                        read -p "Input 'y' to confirm the current setup. " confirm
                        if [ "$confirm" != "y" ]; then
                            break
                        fi
                    fi
                fi
            else
                    read -p "Folder of the resulting compiled tileset in data/tilesets: " tileset

                    read -p "Folder in ${dir_raw_tilesets_secondary} contains the .aseprite file: "     tilesetsrc

                    read -p "Folder in ${dir_raw_tilesets_primary} for the related primary tileset: (-1 to use cached src) "  tilesetsrc2

                    if [ "$tilesetsrc2" = "-1" ]; then
                        tilesetsrc2=$(cat "${dir_raw_tilesets_secondary}${tilesetsrc}/primarysrc.txt")
                    fi
            fi
            
            # separates each layer of the tileset into individual .png files
            "${dir_aseprite_folder}Aseprite/aseprite.exe" -b ${dir_aseprite_raw_tilesets}secondary/${tilesetsrc}/tilesetase.ase --save-as ${dir_aseprite_raw_tilesets}secondary/${tilesetsrc}/{layer}.png

            # check if the above cmd worked by checking if the file bottom.png exists
            if [ ! -f "${dir_raw_tilesets_secondary}${tilesetsrc}/bottom.png" ]; then
                echo "Couldn't find the 'bottom.png' file. Make sure the 'tilesetase.ase' file is in the correct folder and that the layers in the .aseprite file are named correctly."

                echo "${dir_raw_tilesets_secondary}${tilesetsrc}/bottom.png"
                # break the loop and go back to the main menu
                break
            fi

            # replace transparency with #ff00ff
            python3 ${normalize_py} ${dir_raw_tilesets_secondary}${tilesetsrc}/bottom.png ${dir_raw_tilesets_secondary}${tilesetsrc}/bottom.png
            
            python3 ${normalize_py} ${dir_raw_tilesets_secondary}${tilesetsrc}/middle.png ${dir_raw_tilesets_secondary}${tilesetsrc}/middle.png

            python3 ${normalize_py} ${dir_raw_tilesets_secondary}${tilesetsrc}/top.png ${dir_raw_tilesets_secondary}${tilesetsrc}/top.png

            # run porytiles
            porytiles compile-secondary ${attribute_generation} -Wall -o ${dir_compiled_secondary}${tileset} ${dir_raw_tilesets_secondary}${tilesetsrc} ${dir_raw_tilesets_primary}${tilesetsrc2} ${metatile_behaviors}

            lastcmd="porytiles compile-secondary ${attribute_generation} -Wall -o ${dir_compiled_secondary}${tileset} ${dir_raw_tilesets_secondary}${tilesetsrc} ${dir_raw_tilesets_primary}${tilesetsrc2} ${metatile_behaviors}"

            # write ${tilesetsrc2} to a .txt file for use later
            echo $tilesetsrc2 > ${dir_raw_tilesets_secondary}${tilesetsrc}/primarysrc.txt

            echo "Compiled secondary tileset."
            ;;
        3) 
            # DECOMPILE PRIMARY
            read -p "Folder name for the resulting decompiled tileset in ${dir_raw_tilesets}: " destino
            read -p "Folder name for the primary tileset to be decompiled in ${dir_compiled_primary}: " tilesetsrc

            # run porytiles
            porytiles decompile-primary -o ${dir_raw_tilesets}${destino} ${dir_compiled_primary}${tilesetsrc} ${metatile_behaviors}

            lastcmd="porytiles decompile-primary -o ${dir_raw_tilesets}${destino} ${dir_compiled_primary}${tilesetsrc} ${metatile_behaviors}"

            echo "Decompiled primary tileset."
            ;;
        4)
            # DECOMPILE SECONDARY
            read -p "Folder name for the resulting decompiled tileset in ${dir_raw_tilesets}: " destino
            read -p "Folder name for the secondary tileset to be decompiled in ${dir_compiled_secondary}: " tilesetsrc
            read -p "Folder name for the linked primary tileset in ${dir_compiled_primary}: " tilesetsrc2

            # run porytiles
            porytiles decompile-secondary -o ${dir_raw_tilesets}${destino} ${dir_compiled_secondary}${tilesetsrc} ${dir_compiled_primary}${tilesetsrc2} ${metatile_behaviors}

            lastcmd="porytiles decompile-secondary -o ${dir_raw_tilesets}${destino} ${dir_compiled_secondary}${tilesetsrc} ${dir_compiled_primary}${tilesetsrc2} ${metatile_behaviors}"

            echo "Decompiled secondary tileset."
            ;;
        5)
            # run the command stored in lastcmd
            # show what is in lastcmd and confirm if the user wants to run it
            echo "Last command: " $lastcmd
            read -p "Run this command? (y/n) " run
            if [ "$run" = "s" ]; then
                $lastcmd
            fi
            ;;
        6) 
            if [ "$doubleconfirm" = "1" ]; then
                doubleconfirm="0"
                echo "Double confirmation disabled."
            else
                doubleconfirm="1"
                echo "Double confirmation enabled."
            fi
            ;;
        7) 
            echo "Current paths:"
            echo "1) Raw tilesets: " $dir_raw_tilesets
            echo "2) Aseprite folder: " $dir_aseprite_folder
            echo "3) Aseprite raw tilesets: " $dir_aseprite_raw_tilesets
            echo "4) Compiled primary: " $dir_compiled_primary
            echo "5) Compiled secondary: " $dir_compiled_secondary
            echo "6) Metatile behaviors: " $metatile_behaviors
            while (true); do
                read -p "Which path would you like to change? (1-6) " path
                case $path in
                    1)
                        read -p "New raw tilesets path: " dir_raw_tilesets
                        ;;
                    2)
                        read -p "New Aseprite folder path: " dir_aseprite_folder
                        ;;
                    3)
                        read -p "New Aseprite raw tilesets path: " dir_aseprite_raw_tilesets
                        ;;
                    4)
                        read -p "New compiled primary path: " dir_compiled_primary
                        ;;
                    5)
                        read -p "New compiled secondary path: " dir_compiled_secondary
                        ;;
                    6)
                        read -p "New metatile behaviors path: " metatile_behaviors
                        ;;
                    *)
                        echo "Invalid option."
                        ;;
                esac
                read -p "Change another path? (y/n) " change
                if [ "$change" = "n" ]; then
                    break
                fi
            done
            ;;

        8) 
        # bulk recompile secondary tilesets
            dir_path="${dir_raw_tilesets_secondary}"

            for folder in "$dir_path"*/; do
                echo "$(basename "$folder")"

                tileset=$(basename "$folder")
                tilesetsrc="$folder"

                # check if ${dir_compiled_secondary}${tileset} doesn't exist, which means that names differ and it will mess up, so break
                if [ ! -d "${dir_compiled_secondary}${tileset}" ]; then
                    echo "The folder ${dir_compiled_secondary}${tileset} does not exist, even though the raw secondary tileset is named $(basename "$folder"). Make sure the folder names match to use this command."
                    break
                fi

                # get the primary tileset linked with the secondary tileset
                tilesetsrc2=""
                tilesetsrc2=$(cat "$folder/primarysrc.txt")

                if [ "$tilesetsrc2" = "" ]; then
                    echo "Couldn't find the 'primarysrc.txt' file. Make sure the 'primarysrc.txt' file is in the correct folder."
                    break
                fi

                tilesetsrc2="/primary/${tilesetsrc2}"

                porytiles compile-secondary -Wall -o ${dir_compiled_secondary}${tileset} ${attribute_generation} ${tilesetsrc} ${dir_raw_tilesets}${tilesetsrc2} ${metatile_behaviors}

                echo "Compiled $(basename "$folder")."
            done
            ;;
        9)
            if [ "$attribute_generation" = "" ]; then
                attribute_generation="--disable-attribute-generation"
                echo "Attribute generation is now disabled."
            else
                attribute_generation=""
                echo "Attribute generation is now enabled."
            fi
            ;;
        0)
            # exit from the script
            break
            ;;
        *)
            echo "Invalid option."
            ;;
    esac
done 