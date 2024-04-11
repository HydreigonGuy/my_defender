/*
** EPITECH PROJECT, 2021
** bullet_handeling.c
** File description:
** my defender
*/

#include "header.h"

void next_wave(game_t *game, gs_t *gs)
{
    game->currency += gs->wave;
    gs->wave++;
    if (gs->wave > 13)
        game->game_state = -1;
    else {
        if (sfSound_getStatus(game->sounds->l_sounds->next->sound) != sfPaused)
            sfSound_play(game->sounds->l_sounds->next->sound);
        gs->enemy = create_enemy_list(gs->wave);
    }
}

void bullet_handeling(game_t *game, gs_t *gs, int delta)
{
    bullet_t *curr = gs->bullet;

    for (curr; curr != NULL; curr = curr->next) {
        curr->img->crds.x -= delta * curr->speed;
        curr->range -= delta * curr->speed;
    }
    for (int i = 0; i < 12; i++) {
        if (gs->twr[i]->type)
            gs->twr[i]->last_rchrg -= delta;
        if (gs->twr[i]->type && gs->twr[i]->last_rchrg <= 0) {
            add_bullet(&gs->bullet, gs->twr[i]->spr->crds, gs->twr[i]->type);
            gs->twr[i]->last_rchrg = gs->twr[i]->rchrg_time;
        }
    }
    if (gs->enemy == NULL)
        next_wave(game, gs);
    check_bullets(gs, game);
    update_stats(gs, game);
}