/*
** EPITECH PROJECT, 2021
** fill_win_btn.c
** File description:
** my defender
*/

#include "header.h"

button_t **fill_win_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 3);
    for (int i = 0; i < 3; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    btn[0]->spr = fill_sprite("images/play_again.png", 200, 400);
    rect_fill(&btn[0]->spr->r, 200, 100);
    btn[1]->spr = fill_sprite("images/quit.png", 500, 400);
    rect_fill(&btn[1]->spr->r, 200, 100);
    btn[2]->spr = fill_sprite("images/back_to_start.png", 800, 400);
    rect_fill(&btn[2]->spr->r, 200, 100);
    return (btn);
}