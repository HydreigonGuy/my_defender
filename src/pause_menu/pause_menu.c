/*
** EPITECH PROJECT, 2021
** pause_menu.c
** File description:
** my defender
*/

#include "header.h"

static void function_call1_pause(button_t **btn)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(btn[i]->spr->spr, btn[i]->spr->crds);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
    }
}

static void function_call2_pause(sprite_t *bg, button_t **btn, game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, bg->spr, NULL);
    for (int i = 0; i < 5; i++) {
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(game->window, btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(game->window);
}

void pause_menu(game_t *game)
{
    sprite_t *pause_bg = NULL;
    button_t **btn = NULL;

    game->game_state = 0;
    pause_bg = fill_sprite("images/back_ground_pause.png", 0, 0);
    btn = fill_pause_btn();
    mouse_reset(game->mouse);
    function_call1_pause(btn);
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_gs(game, game->mouse);
        mouse_check(game->mouse, btn, game, 5);
        function_call2_pause(pause_bg, btn, game);
    }
    for (int i = 0; i < 5; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    free_sprite(pause_bg);
    pm_btn_handeling(game);
    game->time = sfClock_getElapsedTime(game->clock);
}