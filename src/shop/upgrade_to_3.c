/*
** EPITECH PROJECT, 2021
** upgrade_to_3.c
** File description:
** my defender
*/

#include "header.h"

static void t_fill_1(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/knife3.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 40;
    t->type = 31;
}

static void t_fill_2(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/gun3.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 60;
    t->type = 32;
}

static void t_fill_3(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/bomb2.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 100;
    t->type = 33;
}

static void t_fill_4(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/freeze3.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 50;
    t->type = 34;
}

int upgrade_to_3(int id, int spot, tower_t *t)
{
    if (id == 1) {
        t_fill_1(t, spot);
        return (4);
    } if (id == 2) {
        t_fill_2(t, spot);
        return (3);
    } if (id == 3) {
        t_fill_3(t, spot);
        return (5);
    } if (id == 4) {
        t_fill_4(t, spot);
        return (6);
    }
    return (0);
}