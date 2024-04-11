##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## mydefender
##

SRC	=	src/fill_structs/fill_game.c	\
		src/fill_structs/fill_sprite.c	\
		src/fill_structs/load_enemies.c	\
		src/fill_structs/towers_set.c	\
		src/fill_structs/load_sounds.c	\
		src/fill_structs/enemy_stats/enemy_count.c	\
		src/fill_structs/enemy_stats/enemy_f_name.c	\
		src/fill_structs/enemy_stats/enemy_hp.c	\
		src/fill_structs/enemy_stats/enemy_spd.c	\
		src/fill_structs/enemy_stats/load_enemyl.c	\
		src/fill_structs/bulletlist.c	\
		src/fill_structs/bullet_stats.c	\
		src/free_structs/destroy.c	\
		src/free_structs/free_game.c	\
		src/pause_menu/pm_btn_handeling.c	\
		src/pause_menu/fill_pause_btn.c	\
		src/pause_menu/pause_menu.c	\
		src/start_menu/event_check_start.c	\
		src/start_menu/fill_start_btn.c	\
		src/start_menu/mouse_fill.c	\
		src/start_menu/start_menu.c	\
		src/shop/upgrade_to_3.c	\
		src/shop/upgrade_to_2.c	\
		src/shop/upgrade_tower.c	\
		src/shop/change_upgrade_btn.c	\
		src/shop/tower_change.c	\
		src/shop/new_tower.c	\
		src/shop/shop_display.c	\
		src/shop/fill_shop_display.c	\
		src/shop/shop.c	\
		src/tutorial/run_tuto.c	\
		src/settings/stngs_button_handeling.c	\
		src/settings/music_settings.c	\
		src/settings/fill_settings_btn.c	\
		src/settings/settings.c	\
		src/game_scene/bullet_handeling.c	\
		src/game_scene/enemy_handeling.c	\
		src/game_scene/display_enemy.c	\
		src/game_scene/gs_fill_struct.c	\
		src/game_scene/gs_button_press.c	\
		src/game_scene/gs_btn_fill.c	\
		src/game_scene/new_rect_set.c	\
		src/game_scene/set_gs_bg.c	\
		src/game_scene/game_scene.c	\
		src/game_scene/event_check_gs.c	\
		src/end/end_set_new.c	\
		src/end/victory/fill_win_btn.c	\
		src/end/victory/victory.c	\
		src/end/game_over/game_over.c	\
		src/end/display_score.c	\
		src/get_text.c	\
		src/hit_enemy.c		\
		src/mouse_check.c	\
		src/mouse_on_button.c	\
		src/mouse_reset.c	\
		src/mouse_released_on_button.c	\
		src/scene_pick.c	\
		src/rect_fill.c	\
		src/update_stats.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_getstr.c	\
		lib/my/my_strlen.c	\
		lib/my/restart_str.c	\
		lib/my/my_strcat.c	\
		src/main.c

all:
	gcc -o my_defender $(SRC) -I include -l csfml-graphics -l csfml-system -l csfml-audio

clean:

fclean:
	rm my_defender

re:	fclean	all

.PHONY:	all	fclean	clean	re
