/*
** EPITECH PROJECT, 2021
** enemy_handeling.c
** File description:
** my_defender
*/

#include "header.h"

void new_crds_set2(enemy_t *e, int l)
{
    if (e ->spot > 900 - l && e->spot <= 1050 - l)
        e->img->crds.x = e->spot - 600;
    if (e->spot > 1050 - l && e->spot <= 1350 - l)
        e->img->crds.y = e->spot - 1050 + 100;
    if (e ->spot > 1350 - l && e->spot <= 1500 - l)
        e->img->crds.x = e->spot - 900;
    if (e->spot > 1500 - l && e->spot <= 1800 - l)
        e->img->crds.y = 400 - (e->spot - 1500 + l * 2);
    if (e ->spot > 1800 - l && e->spot <= 2100 - l)
        e->img->crds.x = e->spot - 1200;
    if (e->spot > 2100 - l && e->spot <= 2250 - l)
        e->img->crds.y = e->spot - 2100 + 100;
    if (e ->spot > 2250 - l && e->spot <= 2400 - l)
        e->img->crds.x = e->spot - 1350;
}

void new_crds_set(enemy_t *e)
{
    int l = e->img->r.width / 2;

    if (e->spot <= 900 - l) {
        if (e->spot <= 150 - l)
            e->img->crds.x = e->spot;
        if (e->spot > 150 - l && e->spot <= 450 - l)
            e->img->crds.y = e->spot - 150 + 100;
        if (e ->spot > 450 - l && e->spot <= 600 - l)
            e->img->crds.x = e->spot - 300;
        if (e->spot > 600 - l && e->spot <= 900 - l)
            e->img->crds.y = 400 - (e->spot - 600 + l * 2);
    } else
        new_crds_set2(e, l);
}

int enemy_handeling(enemy_t *enemy, game_t *game)
{
    sfTime new_time = sfClock_getElapsedTime(game->clock);
    int delta = (new_time.microseconds - game->time.microseconds) / 30000;
    enemy_t *curr = enemy;

    for (curr; curr != NULL; curr = curr->next) {
        curr->spot += delta * curr->spd;
        new_crds_set(curr);
        if (curr->spot >= 2400)
            game->game_state = -2;
    }
    game->time = new_time;
    return (delta);
}