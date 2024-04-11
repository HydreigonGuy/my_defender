/*
** EPITECH PROJECT, 2021
** pm_btn_handeling.c
** File description:
** my defender
*/

#include "header.h"

void pm_btn_handeling(game_t *game)
{
    if (game->game_state == 10) {
        settings(game);
        if (game->game_state != 2)
            pause_menu(game);
    }
    if (game->game_state == 11)
        game->game_state = 0;
    if (game->game_state == 3)
        game->game_state = 0;
    if (game->game_state == 12)
        game->game_state = 8;
    if (game->game_state == 13)
        game->game_state = 9;
    if (game->game_state == 14)
        game->game_state = 2;
}