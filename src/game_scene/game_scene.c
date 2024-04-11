/*
** EPITECH PROJECT, 2021
** game_scene.c
** File description:
** my_defender
*/

#include "header.h"

static void gs_f_call1(gs_t *gs, game_t *g)
{
    sfSprite_setPosition(gs->bg[1]->spr, gs->bg[1]->crds);
    sfSprite_setPosition(gs->bg[2]->spr, gs->bg[2]->crds);
    sfClock_restart(g->clock);
    g->time = sfClock_getElapsedTime(g->clock);
    for (int i = 0; i < 12; i++)
        sfSprite_setPosition(gs->twr[i]->hold->spr, gs->twr[i]->hold->crds);
    for (int i = 0; gs->btn[i]; i++)
        sfSprite_setPosition(gs->btn[i]->spr->spr, gs->btn[i]->spr->crds);
}

static void gs_display(gs_t *gs, game_t *g)
{
    int new = new_rect_set(sfClock_getElapsedTime(g->clock));

    sfRenderWindow_clear(g->window, sfBlack);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(g->window, gs->bg[i]->spr, NULL);
    for (int i = 0; i < 12; i++) {
        if (gs->twr[i]->type) {
            gs->twr[i]->spr->r.left = new;
            sfSprite_setTextureRect(gs->twr[i]->spr->spr, gs->twr[i]->spr->r);
            sfRenderWindow_drawSprite(g->window, gs->twr[i]->spr->spr, NULL);
        }
    }
    for (int i = 0; i < 9; i++)
        sfRenderWindow_drawSprite(g->window, gs->nums[i]->spr, NULL);
    display_enemy(g, gs->enemy, gs->bullet, new / 100);
    for (int i = 0; gs->btn[i]; i++) {
        sfSprite_setTextureRect(gs->btn[i]->spr->spr, gs->btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, gs->btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}

static void gs_free(tower_t **t, sprite_t **bg, gs_t *gs)
{
    for (int i = 0; i < 12; i++) {
        free_sprite(t[i]->hold);
        if (t[i]->type)
            free_sprite(t[i]->spr);
        free(t[i]);
    }
    for (enemy_t *tmp = NULL; gs->enemy != NULL ;) {
        free_sprite(gs->enemy->img);
        tmp = gs->enemy;
        gs->enemy = gs->enemy->next;
        free(tmp);
    }
    for (bullet_t *tmp = NULL ; gs->bullet != NULL ;) {
        free_sprite(gs->bullet->img);
        tmp = gs->bullet;
        gs->bullet = gs->bullet->next;
        free(tmp);
    }
    free_sprite(bg[0]);
    free_sprite(bg[1]);
}

int game_scene(game_t *game)
{
    gs_t *gs = gs_fill_struct();
    int delta = 0;

    mouse_reset(game->mouse);
    gs_f_call1(gs, game);
    game->game_state = 0;
    game->score = 0;
    game->currency = 3;
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_gs(game, game->mouse);
        mouse_check(game->mouse, gs->btn, game, 1);
        delta = enemy_handeling(gs->enemy, game);
        bullet_handeling(game, gs, delta);
        gs_display(gs, game);
        gs_button_press(game, gs);
    }
    gs_free(gs->twr, gs->bg, gs);
}