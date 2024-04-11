/*
** EPITECH PROJECT, 2021
** upgrade_tower.c
** File description:
** my defender
*/

#include "header.h"

int upgrade_tower(int id, int spot, tower_t *t, int id2)
{
    int ret = 0;

    if (id == 5) {
        ret = upgrade_to_2(id2, spot, t);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (ret);
    } else if (id == 6) {
        ret = upgrade_to_3(id2, spot, t);
        sfSprite_setPosition(t->spr->spr, t->spr->crds);
        return (ret);
    }
    return (0);
}