/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** my defender
*/

#include "header.h"

void function_call1_go(button_t **btn, sprite_t *game_over)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(btn[i]->spr->spr, btn[i]->spr->crds);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
    }
    sfSprite_setPosition(game_over->spr, game_over->crds);
}

void function_call2_go(sprite_t *bg, button_t **btn, game_t *g, sprite_t *w)
{
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, w->spr, NULL);
    for (int i = 0; i < 3; i++) {
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, btn[i]->spr->spr, NULL);
    }
}

void game_over(game_t *game)
{
    sprite_t *go_bg = fill_sprite("images/back_ground_pause.png", 0, 0);
    sprite_t *game_over = fill_sprite("images/game_over.png", 350, 100);
    button_t **btn = NULL;
    text_t *score = get_text(my_strcat("Score: ", my_getstr(game->score)), \
    50, 0, 550);

    btn = fill_win_btn();
    mouse_reset(game->mouse);
    function_call1_go(btn, game_over);
    game->game_state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_start(game->window, game->mouse);
        mouse_check(game->mouse, btn, game, 3);
        display_score(game->window, score);
        function_call2_go(go_bg, btn, game, game_over);
    }
    free_ele(btn, go_bg, game_over, score);
    game->game_state = end_set_new(game->game_state);
}