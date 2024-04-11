/*
** EPITECH PROJECT, 2021
** towers_set.c
** File description:
** my defender
*/

#include "header.h"

int t_x(int i)
{
    return (150 * (i / 2) + 175);
}

int t_y(int i)
{
    return (150 * (i % 2) + 125);
}

tower_t **towers_set(void)
{
    tower_t **ret = NULL;

    ret = malloc(sizeof(tower_t *) * 12);
    for (int i = 0; i < 12; i++) {
        ret[i] = malloc(sizeof(tower_t));
        ret[i]->hold = fill_sprite("images/tower.png", t_x(i), t_y(i));
        ret[i]->damage = 0;
        ret[i]->range = 0;
        ret[i]->rchrg_time = 0;
        ret[i]->last_rchrg = 0;
        ret[i]->type = 0;
    }
    return (ret);
}