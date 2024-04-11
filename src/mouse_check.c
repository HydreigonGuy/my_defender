/*
** EPITECH PROJECT, 2021
** mouse_check.c
** File description:
** my defender
*/

#include "header.h"

void mouse_check(mouse_t *mouse, button_t **btn, game_t *game, int c)
{
    for (int i = 0; i < c; i++) {
        btn[i]->status = 0;
        if (mouse_on_button(mouse, btn[i]))
            btn[i]->status = 1;
        if (mouse_pressed_button(mouse, btn[i]))
            btn[i]->status = 2;
        if (mouse_released_on_button(mouse, btn[i]))
            game->game_state = 10 + i;
        btn[i]->spr->r.left = btn[i]->status * btn[i]->spr->r.width;
    }
}