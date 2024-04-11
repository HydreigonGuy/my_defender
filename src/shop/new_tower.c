/*
** EPITECH PROJECT, 2021
** new_tower.c
** File description:
** my defender
*/

#include "header.h"

static void t_fill_1(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/knife.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 30;
    t->last_rchrg = 0;
    t->type = 1;
}

static void t_fill_2(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/gun.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 50;
    t->last_rchrg = 0;
    t->type = 2;
}

static void t_fill_3(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/bomb.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 100;
    t->last_rchrg = 0;
    t->type = 3;
}

static void t_fill_4(tower_t *t, int spot)
{
    t->spr = fill_sprite("images/freeze.png", t_x(spot), t_y(spot));
    rect_fill(&t->spr->r, 100, 100);
    t->rchrg_time = 50;
    t->last_rchrg = 0;
    t->type = 4;
}

int new_t(int id, int spot, tower_t *t, int id2)
{
    if (id == 1) {
        t_fill_1(t, spot);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (1);
    } if (id == 2) {
        t_fill_2(t, spot);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (2);
    } if (id == 3) {
        t_fill_3(t, spot);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (3);
    } if (id == 4) {
        t_fill_4(t, spot);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (1);
    }
    return (upgrade_tower(id, spot, t, id2));
}