/*
** EPITECH PROJECT, 2021
** scene_pick.c
** File description:
** my_defender
*/

#include "header.h"

void scene_pick(game_t *game)
{
    int x = game->game_state;

    game->game_state = 0;
    if (x == 10 || x == 8)
        game_scene(game);
    if (x == 11)
        run_tuto(game);
    if (x == 12) {
        settings(game);
        if (game->game_state != 2)
            start_menu(game);
    }
    if (x == 9)
        start_menu(game);
    if (game->game_state == -1)
        victory(game);
    if (game->game_state == -2)
        game_over(game);
    if (game->game_state > 2 && game->window)
        scene_pick(game);
}