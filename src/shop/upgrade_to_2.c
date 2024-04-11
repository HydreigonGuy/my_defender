/*
** EPITECH PROJECT, 2021
** upgrade_to_2.c
** File description:
** my defender
*/

#include "header.h"

static void t_fill_1(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/knife2.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 20;
    t->type = 21;
}

static void t_fill_2(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/gun2.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 30;
    t->type = 22;
}

static void t_fill_3(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/bomb3.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 20;
    t->type = 23;
}

static void t_fill_4(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/freeze2.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 30;
    t->type = 24;
}

int upgrade_to_2(int id, int spot, tower_t *t)
{
    if (id == 1) {
        t_fill_1(t, spot);
        return (6);
    } if (id == 2) {
        t_fill_2(t, spot);
        return (5);
    } if (id == 3) {
        t_fill_3(t, spot);
        return (6);
    } if (id == 4) {
        t_fill_4(t, spot);
        return (10);
    }
    return (0);
}