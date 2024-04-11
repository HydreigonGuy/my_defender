/*
** EPITECH PROJECT, 2021
** fill_start_btn.c
** File description:
** my_defender
*/

#include "header.h"

button_t **fill_start_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    btn[0]->spr = fill_sprite("images/start_button.png", 400, 100);
    rect_fill(&btn[0]->spr->r, 400, 200);
    btn[1]->spr = fill_sprite("images/tutorial_button.png", 475, 325);
    rect_fill(&btn[1]->spr->r, 250, 100);
    btn[2]->spr = fill_sprite("images/settings_button.png", 475, 450);
    rect_fill(&btn[2]->spr->r, 250, 100);
    btn[3]->spr = fill_sprite("images/exit_button.png", 500, 575);
    rect_fill(&btn[3]->spr->r, 200, 100);
    return (btn);
}