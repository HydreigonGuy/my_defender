/*
** EPITECH PROJECT, 2021
** event_check_start.c
** File description:
** my_deender
*/

#include "header.h"

void event_check_start(sfRenderWindow *w, mouse_t *mc)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(w, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(w);
        mc->x = event.mouseMove.x;
        mc->y = event.mouseMove.y;
        mc->p_x = event.mouseButton.x;
        mc->p_y = event.mouseButton.y;
        if (event.type == sfEvtMouseButtonReleased) {
            mc->r_x = event.mouseButton.x;
            mc->r_y = event.mouseButton.y;
        }
    }
}