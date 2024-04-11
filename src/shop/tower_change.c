/*
** EPITECH PROJECT, 2021
** tower_change.c
** File description:
** my defender
*/

#include "header.h"

static int tower_picked(mouse_t *m, int x, int y)
{
    if (x > m->r_x)
        return (0);
    if (x + 100 < m->r_x)
        return (0);
    if (y > m->r_y)
        return (0);
    if (y + 100 < m->r_y)
        return (0);
    return (1);
}

int id_cost(int id)
{
    if (id == 1)
        return (1);
    if (id == 2)
        return (2);
    if (id == 3)
        return (3);
    if (id == 4)
        return (1);
}

int ug_cost(int id, int type)
{
    if (id == 5) {
        if (type == 1)
            return (6);
        if (type == 2)
            return (5);
        if (type == 3)
            return (6);
        if (type == 4)
            return (10);
    } if (type == 1)
        return (4);
    if (type == 2)
        return (3);
    if (type == 3)
        return (5);
    if (type == 4)
        return (6);
}

void tower_change(gs_t *gs, game_t *g, shop_t *s)
{
    for (int i = 0; i < 12; i++) {
        if (gs->twr[i]->type && tower_picked(g->mouse, t_x(i), t_y(i))
            && s->s != i) {
            s->s = i;
            change_upgrade_btn(s, gs->twr[i]->type);
        } if (gs->twr[i]->type == 0 && tower_picked(g->mouse, t_x(i), t_y(i))
            && g->currency >= id_cost(s->id)) {
            g->currency = g->currency - new_t(s->id, i, gs->twr[i], 0);
            play_sound(g->sounds->l_sounds);
        }
    }
    if ((s->id == 5 || s->id == 6) && s->s != -1 &&
        g->currency >= ug_cost(s->id, gs->twr[s->s]->type)) {
        g->currency -= new_t(s->id, s->s, gs->twr[s->s], gs->twr[s->s]->type);
        s->s = -1;
        s->id = 0;
        play_sound(g->sounds->l_sounds);
    } if (s->s == -1)
        change_upgrade_btn(s, 0);
    mouse_reset(g->mouse);
}