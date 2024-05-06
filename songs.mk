STD_REVERB = 50

$(MID_BUILDDIR)/%.o: $(MID_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -I sound -o $@ $<

$(MID_SUBDIR)/mus_aqua_magma_hideout.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_aqua_magma_hideout -V084

$(MID_SUBDIR)/mus_encounter_aqua.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_aqua -V086

$(MID_SUBDIR)/mus_route111.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route111 -V076

$(MID_SUBDIR)/mus_encounter_suspicious.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_suspicious -V078

$(MID_SUBDIR)/mus_b_arena.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_arena -V090

$(MID_SUBDIR)/mus_b_dome.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_dome -V090

$(MID_SUBDIR)/mus_b_dome_lobby.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_dome -V056

$(MID_SUBDIR)/mus_b_factory.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_factory -V100

$(MID_SUBDIR)/mus_b_frontier.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_frontier -V094

$(MID_SUBDIR)/mus_b_palace.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_palace -V105

$(MID_SUBDIR)/mus_b_tower_rs.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_tower_rs -V080

$(MID_SUBDIR)/mus_b_pike.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_pike -V092

$(MID_SUBDIR)/mus_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_trainer -V080 -P1

$(MID_SUBDIR)/mus_vs_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_wild -V080 -P1

$(MID_SUBDIR)/mus_vs_aqua_magma_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_aqua_magma_leader -V080 -P1

$(MID_SUBDIR)/mus_vs_aqua_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_aqua_magma -V080 -P1

$(MID_SUBDIR)/mus_vs_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_gym_leader -V080 -P1

$(MID_SUBDIR)/mus_vs_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_champion -V080 -P1

$(MID_SUBDIR)/mus_vs_kyogre_groudon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_kyogre_groudon -V080 -P1

$(MID_SUBDIR)/mus_vs_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_rival -V080 -P1

$(MID_SUBDIR)/mus_vs_regi.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_regi -V080 -P1

$(MID_SUBDIR)/mus_vs_elite_four.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_elite_four -V080 -P1

$(MID_SUBDIR)/mus_roulette.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_roulette -V080

$(MID_SUBDIR)/mus_lilycove_museum.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_lilycove_museum -V080

$(MID_SUBDIR)/mus_encounter_brendan.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_brendan -V078

$(MID_SUBDIR)/mus_encounter_male.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_male -V080

$(MID_SUBDIR)/mus_victory_road.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_road -V076

$(MID_SUBDIR)/mus_game_corner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_game_corner -V072

$(MID_SUBDIR)/mus_contest_winner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_contest_winner -V100

$(MID_SUBDIR)/mus_contest_results.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_contest_results -V080

$(MID_SUBDIR)/mus_contest_lobby.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_contest_lobby -V060

$(MID_SUBDIR)/mus_contest.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_contest -V088

$(MID_SUBDIR)/mus_cycling.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_cycling -V083

$(MID_SUBDIR)/mus_encounter_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_champion -V076

$(MID_SUBDIR)/mus_petalburg_woods.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_petalburg_woods -V080

$(MID_SUBDIR)/mus_abandoned_ship.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_abandoned_ship -V080

$(MID_SUBDIR)/mus_cave_of_origin.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_cave_of_origin -V080

$(MID_SUBDIR)/mus_underwater.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_underwater -V094

$(MID_SUBDIR)/mus_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_intro -V090

$(MID_SUBDIR)/mus_hall_of_fame.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_hall_of_fame -V078

$(MID_SUBDIR)/mus_route110.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route110 -V080

$(MID_SUBDIR)/mus_route120.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route120 -V080

$(MID_SUBDIR)/mus_route122.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route122 -V080

$(MID_SUBDIR)/mus_route101.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route101 -V080

$(MID_SUBDIR)/mus_dummy.s: %.s: %.mid
	$(MID) $< $@ -E -R40

$(MID_SUBDIR)/mus_hall_of_fame_room.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_hall_of_fame_room -V080

$(MID_SUBDIR)/mus_end.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_end -V036

$(MID_SUBDIR)/mus_help.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_help -V078

$(MID_SUBDIR)/mus_level_up.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_obtain_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_evolved.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_gsc_route38.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_slateport.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_slateport -V070

$(MID_SUBDIR)/mus_poke_mart.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_poke_mart -V085

$(MID_SUBDIR)/mus_oceanic_museum.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_oceanic_museum -V080

$(MID_SUBDIR)/mus_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_gym -V080

$(MID_SUBDIR)/mus_encounter_may.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_may -V078

$(MID_SUBDIR)/mus_encounter_female.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_female -V072

$(MID_SUBDIR)/mus_verdanturf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_verdanturf -V090

$(MID_SUBDIR)/mus_rustboro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rustboro -V085

$(MID_SUBDIR)/mus_route119.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route119 -V096

$(MID_SUBDIR)/mus_encounter_intense.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_intense -V078

$(MID_SUBDIR)/mus_weather_groudon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_weather_groudon -V050

$(MID_SUBDIR)/mus_dewford.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_dewford -V078

$(MID_SUBDIR)/mus_encounter_twins.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_twins -V075

$(MID_SUBDIR)/mus_encounter_interviewer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_interviewer -V062

$(MID_SUBDIR)/mus_victory_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_trainer -V091

$(MID_SUBDIR)/mus_victory_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_wild -V080

$(MID_SUBDIR)/mus_victory_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_gym_leader -V080

$(MID_SUBDIR)/mus_victory_aqua_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_aqua_magma -V088

$(MID_SUBDIR)/mus_victory_league.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_league -V080

$(MID_SUBDIR)/mus_caught.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_victory_wild -V080

$(MID_SUBDIR)/mus_encounter_cool.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_cool -V086

$(MID_SUBDIR)/mus_trick_house.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_trick_house -V070

$(MID_SUBDIR)/mus_route113.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route113 -V084

$(MID_SUBDIR)/mus_sailing.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sailing -V086

$(MID_SUBDIR)/mus_mt_pyre.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_mt_pyre -V088

$(MID_SUBDIR)/mus_sealed_chamber.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sealed_chamber -V100

$(MID_SUBDIR)/mus_petalburg.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_petalburg -V080

$(MID_SUBDIR)/mus_fortree.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fortree -V080

$(MID_SUBDIR)/mus_oldale.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_oldale -V080

$(MID_SUBDIR)/mus_mt_pyre_exterior.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_mt_pyre_exterior -V080

$(MID_SUBDIR)/mus_heal.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_slots_jackpot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_slots_win.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_obtain_badge.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_obtain_berry.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_obtain_b_points.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_frontier -V090 -P5

$(MID_SUBDIR)/mus_rg_photo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_photo -V100 -P5

$(MID_SUBDIR)/mus_evolution_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_evolution -V080

$(MID_SUBDIR)/mus_obtain_symbol.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_frontier -V100 -P5

$(MID_SUBDIR)/mus_awaken_legend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_register_match_call.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_register_match_call -V090 -P5

$(MID_SUBDIR)/mus_move_deleted.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_obtain_tmhm.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_too_bad.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fanfare -V090 -P5

$(MID_SUBDIR)/mus_encounter_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_magma -V072

$(MID_SUBDIR)/mus_lilycove.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_lilycove -V085

$(MID_SUBDIR)/mus_littleroot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_littleroot -V100

$(MID_SUBDIR)/mus_surf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_surf -V080

$(MID_SUBDIR)/mus_route104.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_route104 -V097

$(MID_SUBDIR)/mus_gsc_pewter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_birch_lab.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_birch_lab -V080

$(MID_SUBDIR)/mus_abnormal_weather.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_abnormal_weather -V080

$(MID_SUBDIR)/mus_school.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_school -V100

$(MID_SUBDIR)/mus_c_comm_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_poke_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_poke_center -V092

$(MID_SUBDIR)/mus_b_pyramid.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_pyramid -V079

$(MID_SUBDIR)/mus_b_pyramid_top.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_pyramid_top -V077

$(MID_SUBDIR)/mus_ever_grande.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_ever_grande -V086

$(MID_SUBDIR)/mus_rayquaza_appears.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rayquaza_appears -V090

$(MID_SUBDIR)/mus_rg_rocket_hideout.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_rocket_hideout -V090

$(MID_SUBDIR)/mus_rg_follow_me.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_follow_me -V068

$(MID_SUBDIR)/mus_rg_victory_road.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_victory_road -V090

$(MID_SUBDIR)/mus_rg_cycling.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_cycling -V090

$(MID_SUBDIR)/mus_rg_intro_fight.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_intro_fight -V090

$(MID_SUBDIR)/mus_rg_hall_of_fame.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_hall_of_fame -V079

$(MID_SUBDIR)/mus_rg_encounter_deoxys.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_deoxys -V079

$(MID_SUBDIR)/mus_rg_credits.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_credits -V090

$(MID_SUBDIR)/mus_rg_encounter_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_boy -V090

$(MID_SUBDIR)/mus_rg_dex_rating.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_dex_rating -V070 -P5

$(MID_SUBDIR)/mus_rg_obtain_key_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_obtain_key_item -V077 -P5

$(MID_SUBDIR)/mus_rg_caught_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_caught_intro -V094 -P5

$(MID_SUBDIR)/mus_rg_caught.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_victory_wild -V100

$(MID_SUBDIR)/mus_rg_cinnabar.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_cinnabar -V090

$(MID_SUBDIR)/mus_rg_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_gym -V090

$(MID_SUBDIR)/mus_rg_fuchsia.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_fuchsia -V090

$(MID_SUBDIR)/mus_rg_poke_jump.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_game_corner -V090

$(MID_SUBDIR)/mus_rg_heal.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_heal -V090

$(MID_SUBDIR)/mus_rg_oak_lab.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_oak_lab -V075

$(MID_SUBDIR)/mus_rg_berry_pick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_game_corner -V090

$(MID_SUBDIR)/mus_rg_vermillion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vermillion -V090

$(MID_SUBDIR)/mus_rg_route1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_route1 -V079

$(MID_SUBDIR)/mus_rg_route3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_route3 -V083

$(MID_SUBDIR)/mus_rg_route11.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_route11 -V090

$(MID_SUBDIR)/mus_rg_pallet.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_pallet -V100

$(MID_SUBDIR)/mus_rg_surf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_surf -V071

$(MID_SUBDIR)/mus_rg_sevii_45.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_sevii_45 -V084

$(MID_SUBDIR)/mus_rg_sevii_67.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_sevii_67 -V084

$(MID_SUBDIR)/mus_rg_sevii_123.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_pewter -V084

$(MID_SUBDIR)/mus_rg_sevii_cave.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_mt_moon -V090

$(MID_SUBDIR)/mus_rg_sevii_dungeon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_viridian_forest -V100

$(MID_SUBDIR)/mus_rg_sevii_route.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_sevii_route -V080

$(MID_SUBDIR)/mus_rg_net_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_poke_center -V096

$(MID_SUBDIR)/mus_rg_pewter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_pewter -V084

$(MID_SUBDIR)/mus_rg_oak.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_oak -V086

$(MID_SUBDIR)/mus_rg_mystery_gift.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_mystery_gift -V100

$(MID_SUBDIR)/mus_rg_route24.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_route24 -V086

$(MID_SUBDIR)/mus_rg_teachy_tv_show.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_mt_moon -V068

$(MID_SUBDIR)/mus_rg_mt_moon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_mt_moon -V090

$(MID_SUBDIR)/mus_rg_poke_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_poke_tower -V090

$(MID_SUBDIR)/mus_rg_poke_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_poke_center -V096

$(MID_SUBDIR)/mus_rg_poke_flute.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_poke_tower -V048 -P5

$(MID_SUBDIR)/mus_rg_poke_mansion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_poke_mansion -V090

$(MID_SUBDIR)/mus_rg_jigglypuff.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_jigglypuff -V068 -P5

$(MID_SUBDIR)/mus_rg_encounter_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_rival -V079

$(MID_SUBDIR)/mus_rg_rival_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_rival -V079

$(MID_SUBDIR)/mus_rg_encounter_rocket.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_rocket -V096

$(MID_SUBDIR)/mus_rg_ss_anne.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_ss_anne -V090

$(MID_SUBDIR)/mus_rg_new_game_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_new_game_intro -V088

$(MID_SUBDIR)/mus_rg_new_game_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_new_game_intro -V088

$(MID_SUBDIR)/mus_rg_lavender.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_lavender -V090

$(MID_SUBDIR)/mus_rg_silph.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_silph -V076

$(MID_SUBDIR)/mus_rg_encounter_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_girl -V051

$(MID_SUBDIR)/mus_rg_encounter_boy.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_encounter_boy -V090

$(MID_SUBDIR)/mus_rg_game_corner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_game_corner -V090

$(MID_SUBDIR)/mus_rg_slow_pallet.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_pallet -V092

$(MID_SUBDIR)/mus_rg_new_game_instruct.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_new_game_intro -V085

$(MID_SUBDIR)/mus_rg_viridian_forest.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_viridian_forest -V090

$(MID_SUBDIR)/mus_rg_trainer_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_gym -V090

$(MID_SUBDIR)/mus_rg_celadon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_celadon -V070

$(MID_SUBDIR)/mus_rg_title.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_title -V090

$(MID_SUBDIR)/mus_rg_game_freak.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_game_freak -V075

$(MID_SUBDIR)/mus_rg_teachy_tv_menu.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_teachy_tv_menu -V059

$(MID_SUBDIR)/mus_rg_union_room.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_game_corner -V090

$(MID_SUBDIR)/mus_rg_vs_legend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_wild -V090

$(MID_SUBDIR)/mus_rg_vs_deoxys.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_deoxys -V080

$(MID_SUBDIR)/mus_rg_vs_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_frontier_brain -V090

$(MID_SUBDIR)/mus_rg_vs_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_champion -V090

$(MID_SUBDIR)/mus_rg_vs_mewtwo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_wild -V090

$(MID_SUBDIR)/mus_rg_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_trainer -V090

$(MID_SUBDIR)/mus_rg_vs_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_vs_wild -V090

$(MID_SUBDIR)/mus_rg_victory_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_victory_gym_leader -V090

$(MID_SUBDIR)/mus_rg_victory_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_victory_trainer -V089

$(MID_SUBDIR)/mus_rg_victory_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_rg_victory_wild -V090

$(MID_SUBDIR)/mus_cable_car.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_cable_car -V078

$(MID_SUBDIR)/mus_sootopolis.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sootopolis -V062

$(MID_SUBDIR)/mus_safari_zone.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_safari_zone -V082

$(MID_SUBDIR)/mus_b_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_b_tower -V100

$(MID_SUBDIR)/mus_evolution.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_evolution -V080

$(MID_SUBDIR)/mus_encounter_elite_four.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_elite_4 -V078

$(MID_SUBDIR)/mus_c_vs_legend_beast.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_c_vs_legend_beast -V090

$(MID_SUBDIR)/mus_encounter_swimmer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_swimmer -V080

$(MID_SUBDIR)/mus_encounter_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_girl -V080

$(MID_SUBDIR)/mus_intro_battle.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_intro_battle -V088

$(MID_SUBDIR)/mus_encounter_rich.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_rich -V094

$(MID_SUBDIR)/mus_link_contest_p1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_link_contest_p1 -V079

$(MID_SUBDIR)/mus_link_contest_p2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_link_contest_p2 -V090

$(MID_SUBDIR)/mus_link_contest_p3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_link_contest_p3 -V075

$(MID_SUBDIR)/mus_link_contest_p4.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_link_contest_p4 -V090

$(MID_SUBDIR)/mus_littleroot_test.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_littleroot_test -V099

$(MID_SUBDIR)/mus_credits.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_credits -V100

$(MID_SUBDIR)/mus_title.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_title -V090

$(MID_SUBDIR)/mus_fallarbor.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_fallarbor -V100

$(MID_SUBDIR)/mus_mt_chimney.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_mt_chimney -V078

$(MID_SUBDIR)/mus_follow_me.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_follow_me -V074

$(MID_SUBDIR)/mus_vs_frontier_brain.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_frontier_brain -V090 -P1

$(MID_SUBDIR)/mus_vs_mew.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_mew -V090

$(MID_SUBDIR)/mus_vs_rayquaza.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_vs_rayquaza -V080 -P1

$(MID_SUBDIR)/mus_encounter_hiker.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_encounter_hiker -V076

$(MID_SUBDIR)/ph_choice_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_choice_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_choice_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cloth_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cloth_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cloth_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cure_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cure_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_cure_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_dress_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_dress_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_dress_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_face_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_face_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_face_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_fleece_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_fleece_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_fleece_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_foot_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_foot_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_foot_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goat_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goat_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goat_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goose_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goose_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_goose_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_kit_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_kit_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_kit_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_lot_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_lot_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_lot_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_mouth_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_mouth_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_mouth_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_nurse_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_nurse_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_nurse_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_price_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_price_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_price_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_strut_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_strut_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_strut_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_thought_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_thought_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_thought_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_trap_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_trap_held.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/ph_trap_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G_bard -P4

$(MID_SUBDIR)/se_a.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V095 -P4

$(MID_SUBDIR)/se_bang.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_taillow_wing_flap.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P5

$(MID_SUBDIR)/se_glass_flute.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P5

$(MID_SUBDIR)/se_boo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P4

$(MID_SUBDIR)/se_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V070 -P4

$(MID_SUBDIR)/se_ball_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_mugshot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P5

$(MID_SUBDIR)/se_contest_heart.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P5

$(MID_SUBDIR)/se_contest_curtain_fall.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V070 -P5

$(MID_SUBDIR)/se_contest_curtain_rise.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V070 -P5

$(MID_SUBDIR)/se_contest_icon_change.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P5

$(MID_SUBDIR)/se_contest_mons_turn.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P5

$(MID_SUBDIR)/se_contest_icon_clear.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P5

$(MID_SUBDIR)/se_card.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P4

$(MID_SUBDIR)/se_pike_curtain_close.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_pike_curtain_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_ledge.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P4

$(MID_SUBDIR)/se_itemfinder.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P5

$(MID_SUBDIR)/se_applause.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P5

$(MID_SUBDIR)/se_field_poison.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P5

$(MID_SUBDIR)/se_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V080 -P5

$(MID_SUBDIR)/se_e.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P4

$(MID_SUBDIR)/se_elevator.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_escalator.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_exp.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V080 -P5

$(MID_SUBDIR)/se_exp_max.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V094 -P5

$(MID_SUBDIR)/se_fu_zaku.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V120 -P4

$(MID_SUBDIR)/se_contest_condition_lose.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P4

$(MID_SUBDIR)/se_lavaridge_fall_warp.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -P4

$(MID_SUBDIR)/se_balloon_red.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P4

$(MID_SUBDIR)/se_balloon_blue.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P4

$(MID_SUBDIR)/se_balloon_yellow.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P4

$(MID_SUBDIR)/se_arena_timeup1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_arena_timeup2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_bridge_walk.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V095 -P4

$(MID_SUBDIR)/se_failure.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V120 -P4

$(MID_SUBDIR)/se_rotating_gate.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_low_health.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P3

$(MID_SUBDIR)/se_i.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P4

$(MID_SUBDIR)/se_sliding_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V095 -P4

$(MID_SUBDIR)/se_vend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_bike_hop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P4

$(MID_SUBDIR)/se_bike_bell.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_contest_place.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P4

$(MID_SUBDIR)/se_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V120 -P5

$(MID_SUBDIR)/se_use_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_unlock.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_4.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_super_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P5

$(MID_SUBDIR)/se_not_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P5

$(MID_SUBDIR)/se_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P5

$(MID_SUBDIR)/se_puddle.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V020 -P4

$(MID_SUBDIR)/se_berry_blender.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_switch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P4

$(MID_SUBDIR)/se_n.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -P4

$(MID_SUBDIR)/se_ball_throw.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P5

$(MID_SUBDIR)/se_ship.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V075 -P4

$(MID_SUBDIR)/se_flee.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P5

$(MID_SUBDIR)/se_o.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P4

$(MID_SUBDIR)/se_intro_blast.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_pc_login.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_pc_off.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_pc_on.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_pin.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V060 -P4

$(MID_SUBDIR)/se_ding_dong.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P5

$(MID_SUBDIR)/se_pokenav_off.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_pokenav_on.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_faint.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P5

$(MID_SUBDIR)/se_shiny.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V095 -P5

$(MID_SUBDIR)/se_shop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P5

$(MID_SUBDIR)/se_rg_bag_cursor.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_rg_bag_pocket.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_rg_card_flip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_rg_card_flipping.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -P5

$(MID_SUBDIR)/se_rg_card_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V112 -P5

$(MID_SUBDIR)/se_rg_deoxys_move.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V080 -P5

$(MID_SUBDIR)/se_rg_poke_jump_success.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P5

$(MID_SUBDIR)/se_rg_ball_click.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V100 -P5

$(MID_SUBDIR)/se_rg_help_close.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V095 -P5

$(MID_SUBDIR)/se_rg_help_error.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V125 -P5

$(MID_SUBDIR)/se_rg_help_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V096 -P5

$(MID_SUBDIR)/se_rg_ss_anne_horn.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V096 -P5

$(MID_SUBDIR)/se_rg_poke_jump_failure.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -P5

$(MID_SUBDIR)/se_rg_shop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V080 -P5

$(MID_SUBDIR)/se_rg_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V100 -P5

$(MID_SUBDIR)/se_ice_crack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P4

$(MID_SUBDIR)/se_ice_stairs.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_ice_break.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_fall.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_save.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V080 -P5

$(MID_SUBDIR)/se_success.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V080 -P4

$(MID_SUBDIR)/se_select.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V080 -P5

$(MID_SUBDIR)/se_ball_trade.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_thunderstorm.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V080 -P2

$(MID_SUBDIR)/se_thunderstorm_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V080 -P2

$(MID_SUBDIR)/se_thunder.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P3

$(MID_SUBDIR)/se_thunder2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P3

$(MID_SUBDIR)/se_rain.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V080 -P2

$(MID_SUBDIR)/se_rain_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V080 -P2

$(MID_SUBDIR)/se_downpour.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P2

$(MID_SUBDIR)/se_downpour_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P2

$(MID_SUBDIR)/se_orb.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P5

$(MID_SUBDIR)/se_egg_hatch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P5

$(MID_SUBDIR)/se_roulette_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P2

$(MID_SUBDIR)/se_roulette_ball2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P2

$(MID_SUBDIR)/se_ball_tray_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V100 -P5

$(MID_SUBDIR)/se_ball_tray_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P5

$(MID_SUBDIR)/se_ball_tray_enter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P5

$(MID_SUBDIR)/se_click.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V110 -P4

$(MID_SUBDIR)/se_warp_in.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P4

$(MID_SUBDIR)/se_warp_out.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P4

$(MID_SUBDIR)/se_pokenav_call.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V120 -P5

$(MID_SUBDIR)/se_pokenav_hang_up.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V110 -P5

$(MID_SUBDIR)/se_note_a.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_b.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_c.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_c_high.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_d.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_mud_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_e.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_f.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_note_g.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_breakable_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_truck_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_truck_unload.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -P4

$(MID_SUBDIR)/se_truck_move.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -P4

$(MID_SUBDIR)/se_truck_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -P4

$(MID_SUBDIR)/se_repel.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -V090 -P4

$(MID_SUBDIR)/se_u.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -P4

$(MID_SUBDIR)/se_sudowoodo_shake.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_frlg -V077 -P5

$(MID_SUBDIR)/se_m_double_slap.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_comet_punch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P4

$(MID_SUBDIR)/se_m_pay_day.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V095 -P4

$(MID_SUBDIR)/se_m_fire_punch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_scratch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_vicegrip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_razor_wind.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_razor_wind2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_m_swords_dance.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_m_cut.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V120 -P4

$(MID_SUBDIR)/se_m_gust.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_gust2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_wing_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P4

$(MID_SUBDIR)/se_m_fly.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_bind.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V100 -P4

$(MID_SUBDIR)/se_m_mega_kick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V090 -P4

$(MID_SUBDIR)/se_m_mega_kick2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_jump_kick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_sand_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_headbutt.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_horn_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_take_down.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V105 -P4

$(MID_SUBDIR)/se_m_tail_whip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_m_leer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_2 -V110 -P4

$(MID_SUBDIR)/se_dex_search.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G_sfx_rs_1 -v100 -P5
