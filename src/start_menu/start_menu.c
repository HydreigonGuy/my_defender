/*
** EPITECH PROJECT, 2021
** start_menu.c
** File description:
** my_defender
*/

#include "header.h"

static void function_call1_start(button_t **btn, sprite_t *l)
{
    for (int i = 0; i < 4; i++) {
        sfSprite_setPosition(btn[i]->spr->spr, btn[i]->spr->crds);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
    }
    sfSprite_setPosition(l->spr, l->crds);
}

static void func_c2_strt(sprite_t *bg, button_t **btn, game_t *g, sprite_t *l)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, l->spr, NULL);
    for (int i = 0; i < 4; i++) {
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}

void start_menu(game_t *game)
{
    sprite_t *start_bg = NULL;
    sprite_t *logo = fill_sprite("images/logo.png", 500, 0);
    button_t **btn = NULL;

    start_bg = fill_sprite("images/start_menu.png", 0, 0);
    btn = fill_start_btn();
    mouse_reset(game->mouse);
    function_call1_start(btn, logo);
    game->game_state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_start(game->window, game->mouse);
        mouse_check(game->mouse, btn, game, 4);
        func_c2_strt(start_bg, btn, game, logo);
    }
    for (int i = 0; i < 4; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    free_sprite(start_bg);
    scene_pick(game);
}