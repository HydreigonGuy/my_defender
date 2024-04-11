/*
** EPITECH PROJECT, 2021
** fill_settings_btn.c
** File description:
** my defender
*/

#include "header.h"

static void settings_btn_fill(button_t **btn)
{
    btn[0]->spr = fill_sprite("images/music_on_off.png", 250, 75);
    rect_fill(&btn[0]->spr->r, 300, 100);
    btn[1]->spr = fill_sprite("images/sound_on_off.png", 650, 75);
    rect_fill(&btn[1]->spr->r, 300, 100);
    btn[2]->spr = fill_sprite("images/volume.png", 350, 200);
    rect_fill(&btn[2]->spr->r, 200, 100);
    btn[3]->spr = fill_sprite("images/volume_down.png", 650, 200);
    rect_fill(&btn[3]->spr->r, 100, 100);
    btn[4]->spr = fill_sprite("images/volume_up.png", 750, 200);
    rect_fill(&btn[4]->spr->r, 100, 100);
    btn[5]->spr = fill_sprite("images/exit_button.png", 500, 325);
    rect_fill(&btn[5]->spr->r, 200, 100);
    btn[6]->spr = fill_sprite("images/quit.png", 500, 450);
    rect_fill(&btn[6]->spr->r, 200, 100);
}

button_t **fill_settings_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 7);
    for (int i = 0; i < 7; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    settings_btn_fill(btn);
    return (btn);
}