/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** my defender
*/

#include "header.h"

void mouse_check_stg(mouse_t *mouse, button_t **btn, game_t *game, int c);

static void function_call1_settings(button_t **btn)
{
    for (int i = 0; i < 7; i++) {
        sfSprite_setPosition(btn[i]->spr->spr, btn[i]->spr->crds);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
    }
}

static void function_call2_settings(sprite_t *bg, button_t **btn, game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, bg->spr, NULL);
    for (int i = 0; i < 7; i++) {
        if (i != 2)
            sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(game->window, btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(game->window);
    if (game->game_state)
        stngs_button_handeling(game);
}

void settings(game_t *game)
{
    sprite_t *settings_bg = NULL;
    button_t **btn = NULL;

    game->game_state = 0;
    settings_bg = fill_sprite("images/back_ground_pause.png", 0, 0);
    btn = fill_settings_btn();
    mouse_reset(game->mouse);
    function_call1_settings(btn);
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_gs(game, game->mouse);
        mouse_check_stg(game->mouse, btn, game, 7);
        function_call2_settings(settings_bg, btn, game);
        if (game->game_state == 12)
            game->game_state = 0;
    }
    for (int i = 0; i < 7; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    free_sprite(settings_bg);
}