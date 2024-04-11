/*
** EPITECH PROJECT, 2021
** stngs_button_handeling.c
** File description:
** my defender
*/

#include "header.h"

void stngs_button_handeling(game_t *game)
{
    switch (game->game_state) {
        case 16:
            game->game_state = 2;
            return;
        case 10:
            play_stop_music(game->sounds->music, game->mouse);
            break;
        case 11:
            play_stop_sound(game->sounds, game->mouse);
            break;
        case 13:
            set_volume(game->sounds, '-');
            break;
        case 14:
            set_volume(game->sounds, '+');
            break;
        default:
            return;
    }
    game->game_state = 0;
}

void mouse_check_stg(mouse_t *mouse, button_t **btn, game_t *game, int c)
{
    for (int i = 0; i < c; i++) {
        btn[i]->status = 0;
        if (mouse_on_button(mouse, btn[i]))
            btn[i]->status = 1;
        if (mouse_pressed_button(mouse, btn[i]))
            btn[i]->status = 2;
        if (mouse_released_on_button(mouse, btn[i]))
            game->game_state = 10 + i;
        if (btn[0]->status != 1 && sfMusic_getStatus(game->sounds->music) \
        == sfStopped)
            btn[0]->status = 2;
        if (btn[1]->status != 1 && \
        sfSound_getStatus(game->sounds->l_sounds->sound) == sfPaused)
            btn[1]->status = 2;
        btn[i]->spr->r.left = btn[i]->status * btn[i]->spr->r.width;
    }
}