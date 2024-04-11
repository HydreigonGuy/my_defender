/*
** EPITECH PROJECT, 2021
** fill_pause_btn.c
** File description:
** my defender
*/

#include "header.h"

button_t **fill_pause_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 5);
    for (int i = 0; i < 5; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    btn[0]->spr = fill_sprite("images/settings_button.png", 475, 75);
    rect_fill(&btn[0]->spr->r, 250, 100);
    btn[1]->spr = fill_sprite("images/resume.png", 500, 200);
    rect_fill(&btn[1]->spr->r, 200, 100);
    btn[2]->spr = fill_sprite("images/restart.png", 500, 325);
    rect_fill(&btn[2]->spr->r, 200, 100);
    btn[3]->spr = fill_sprite("images/back_to_start.png", 500, 450);
    rect_fill(&btn[3]->spr->r, 200, 100);
    btn[4]->spr = fill_sprite("images/quit.png", 500, 575);
    rect_fill(&btn[4]->spr->r, 200, 100);
    return (btn);
}