/*
** EPITECH PROJECT, 2021
** victory.c
** File description:
** my defender
*/

#include "header.h"

void function_call1_win(button_t **btn, sprite_t *win)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(btn[i]->spr->spr, btn[i]->spr->crds);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
    }
    sfSprite_setPosition(win->spr, win->crds);
}

void function_call2_win(sprite_t *bg, button_t **btn, game_t *g, sprite_t *w)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, w->spr, NULL);
    for (int i = 0; i < 3; i++) {
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, btn[i]->spr->spr, NULL);
    }
}

void victory(game_t *game)
{
    sprite_t *win_bg = fill_sprite("images/back_ground_pause.png", 0, 0);
    sprite_t *win = fill_sprite("images/victory.png", 450, 100);
    button_t **btn = NULL;
    text_t *score = get_text(my_strcat("Score: ", my_getstr(game->score)), \
    50, 0, 550);

    btn = fill_win_btn();
    mouse_reset(game->mouse);
    function_call1_win(btn, win);
    game->game_state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_start(game->window, game->mouse);
        mouse_check(game->mouse, btn, game, 3);
        function_call2_win(win_bg, btn, game, win);
        display_score(game->window, score);
    }
    free_ele(btn, win_bg, win, score);
    game->game_state = end_set_new(game->game_state);
}