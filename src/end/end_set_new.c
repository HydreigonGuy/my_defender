/*
** EPITECH PROJECT, 2021
** end_set_new.c
** File description:
** my defender
*/

#include "header.h"

int end_set_new(int a)
{
    if (a == 10)
        return (8);
    if (a == 11)
        return (2);
    if (a == 12)
        return (9);
    return (a);
}

void free_ele(button_t **btn, sprite_t *bg, sprite_t *win, text_t *s)
{
    for (int i = 0; i < 3; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    free_sprite(bg);
    free_sprite(win);
    destroy_text(s);
}