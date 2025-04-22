# Exterior generic
echo "EXTERIOR-GENERIC"
porytiles compile-primary -Wall -o ../../data/tilesets/primary/porytiles_primary_tutorial ./exterior-generic/ ../../include/constants/metatile_behaviors.h
# Ginko
echo "GINKO WOODS"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/ginko_woods ./ginko-woods/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Sunrise
echo "SUNRISE VILLAGE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/sunrise_village ./sunrise-village ./exterior-generic ../../include/constants/metatile_behaviors.h
# Saberside
echo "SABERSIDE TOWN"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/saberside/ ./saberside/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Coreef
echo "COREEF ISLE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/coral/ ./coral/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Open sea
echo "OPEN SEA"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/open_sea/ ./open-sea/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Uume
# echo "UUME FOREST"
# porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/uume_forest/ ./uume-forest/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Saku
echo "SAKU KURA"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/saku_kura ./saku-kura ./exterior-generic ../../include/constants/metatile_behaviors.h
# Harvest Shrine
echo "HARVEST SHRINE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/harvest_shrine ./harvest-shrine ./exterior-generic ../../include/constants/metatile_behaviors.h
# Silveridge
echo "SILVERIDGE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/silveridge/ ./silveridge/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Silver tunnel
echo "SILVER TUNNEL"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/silver_tunnel/ ./silver-tunnel/ ./exterior-generic ../../include/constants/metatile_behaviors.h
echo "BROWN CAVE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/brown_cave/ ./brown-cave/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Soulkeep
echo "SOULKEEP"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/soulkeep/ ./soulkeep/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Yifu
echo "YIFU CITY"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/yifu/ ./yifu/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Maguro
echo "MAGURO HARBOR"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/maguro ./maguro ./exterior-generic ../../include/constants/metatile_behaviors.h
# Grassflower
echo "GRASSFLOWER PLATEAU"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/grassflower/ ./grassflower/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Puddle Path
echo "PUDDLE PATH"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/puddle_path/ ./puddle-path/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Samurai palace
echo "SAMURAI PALACE"
porytiles compile-secondary -Wall -o ../../data/tilesets/secondary/shogunate/ ./shogunate/ ./exterior-generic ../../include/constants/metatile_behaviors.h
# Decay
echo "DECAY"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/decay/ ./decay/ ./exterior-generic ../../include/constants/metatile_behaviors.h

# Buildings
echo "BUILDING GENERIC"
porytiles compile-primary -Wall -o ../../data/tilesets/primary/building_generic/ ./building-generic/ ../../include/constants/metatile_behaviors.h
echo "HOUSES"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/house_beige/ ./house-beige/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/house_stone/ ./house-stone/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/house_green/ ./house-green/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/house_hardwood2/ ./house-hardwood2/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/house_marble/ ./house-marble/ ./building-generic/ ../../include/constants/metatile_behaviors.h
# Dojos
echo "DOJOS"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/dojo_maguro/ ./dojo-maguro/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/dojo_kura/ ./dojo-kura/ ./building-generic/ ../../include/constants/metatile_behaviors.h
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/dojo_yifu/ ./dojo-yifu/ ./building-generic/ ../../include/constants/metatile_behaviors.h
# Refuge
echo "REFUGE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/refuge/ ./refuge-shop/ ./building-generic/ ../../include/constants/metatile_behaviors.h
# School
echo "SCHOOL"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/school/ ./school/ ./building-generic/ ../../include/constants/metatile_behaviors.h
# Gate
echo "GATE"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/gate/ ./gate/ ./building-generic/ ../../include/constants/metatile_behaviors.h
# Crobat hideout
echo "CROBAT HIDEOUT"
porytiles compile-secondary -metatiles-total-override=4096 -Wall -o ../../data/tilesets/secondary/crobat_hideout/ ./crobat-hideout/ ./building-generic/ ../../include/constants/metatile_behaviors.h
