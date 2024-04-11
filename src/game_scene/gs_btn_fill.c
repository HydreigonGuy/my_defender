/*
** EPITECH PROJECT, 2021
** gs_btn_fill.c
** File description:
** my_defender
*/

#include "header.h"

button_t **gs_btn_fill(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 1);
    for (int i = 0; i < 1; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    btn[0]->spr = fill_sprite("images/shop_button.png", 1000, 550);
    rect_fill(&btn[0]->spr->r, 200, 150);
    return (btn);
}