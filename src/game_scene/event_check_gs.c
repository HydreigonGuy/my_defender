/*
** EPITECH PROJECT, 2021
** event_check_gs.c
** File description:
** my_defender
*/

#include "header.h"

void event_check_gs(game_t *g, mouse_t *mc)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            g->game_state = 3;
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