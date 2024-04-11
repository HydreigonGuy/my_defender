/*
** EPITECH PROJECT, 2021
** gs_button_press.c
** File description:
** my defender
*/

#include "header.h"

void gs_button_press(game_t *game, gs_t *gs)
{
    if (game->game_state == 10) {
        shop(game, gs);
        game->game_state = 0;
        mouse_reset(game->mouse);
    }
    if (game->game_state == 3)
        pause_menu(game);
}