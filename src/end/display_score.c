/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** display_score.c
*/

#include "header.h"

void display_score(sfRenderWindow *win, text_t *score)
{
    sfVector2f pos = sfText_getPosition(score->text);

    pos.x = sfRenderWindow_getSize(win).x / 2 - \
    sfText_getGlobalBounds(score->text).width / 2;
    sfText_setPosition(score->text, pos);
    sfRenderWindow_drawText(win, score->text, NULL);
    sfRenderWindow_display(win);
}