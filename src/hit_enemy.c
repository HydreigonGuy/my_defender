/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** hit_enemy.c
*/

#include "header.h"

int hit_enemies(gs_t *gs, game_t *g, bullet_t *bullet)
{
    enemy_t *curr = gs->enemy;
    sfFloatRect bounds_b = sfSprite_getGlobalBounds(bullet->img->spr);
    sfFloatRect bounds_e;
    int index = 0;
    int res = -1;

    for (; curr != NULL && res == -1 ; index++, curr = curr->next) {
        bounds_e = sfSprite_getGlobalBounds(curr->img->spr);
        if (sfFloatRect_intersects(&bounds_b, &bounds_e, NULL)) {
            curr->hp -= bullet->damage;
            res = index;
        } if (sfFloatRect_intersects(&bounds_b, &bounds_e, NULL) &&
            bullet->range % 10 == 1 && curr->spd > 2)
            curr->spd -= 2;
        if (curr->hp <= 0) {
            destroy_enemy(&(gs->enemy), index);
            g->score += 100;
        }
    }
    return res;
}

void check_bullets(gs_t *gs, game_t *g)
{
    bullet_t *curr = gs->bullet;
    int index_e = -1;

    for (int cmp = 0; curr != NULL ; ) {
        index_e = hit_enemies(gs, g, curr);
        if (index_e != -1) {
            curr = destroy_bullet(&(gs->bullet), cmp);
            continue;
        }
        if (curr->range < 0) {
            curr = destroy_bullet(&(gs->bullet), cmp);
            continue;
        }
        curr = curr->next;
        cmp++;
    }
}