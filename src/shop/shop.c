/*
** EPITECH PROJECT, 2021
** shop.c
** File description:
** my defender
*/

#include "header.h"

static void free_shop(shop_t *shop)
{
    free_sprite(shop->shop);
    for (int i = 0; i < 7; i++)
        free_sprite(shop->btn[i]->spr);
}

static void shop_f_call(shop_t *shop)
{
    sfSprite_setPosition(shop->shop->spr, shop->shop->crds);
    for (int i = 0; i < 7; i++) {
        sfSprite_setTextureRect(shop->btn[i]->spr->spr, shop->btn[i]->spr->r);
        sfSprite_setPosition(shop->btn[i]->spr->spr, shop->btn[i]->spr->crds);
    }
}

static void shop_bg_display(sprite_t **bg, game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg[0]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, bg[1]->spr, NULL);
}

sprite_t **fill_shop_prices(void)
{
    sprite_t **ret = NULL;

    ret = malloc(sizeof(sprite_t *) * 4);
    ret[0] = fill_sprite("images/1coin.png", 1175, 100);
    sfSprite_setPosition(ret[0]->spr, ret[0]->crds);
    ret[1] = fill_sprite("images/2coins.png", 1175, 225);
    sfSprite_setPosition(ret[1]->spr, ret[1]->crds);
    ret[2] = fill_sprite("images/3coins.png", 1175, 350);
    sfSprite_setPosition(ret[2]->spr, ret[2]->crds);
    ret[3] = fill_sprite("images/1coin.png", 1175, 475);
    sfSprite_setPosition(ret[3]->spr, ret[3]->crds);
    return (ret);
}

int shop(game_t *game, gs_t *gs)
{
    shop_t *shop = fill_shop_display();
    int delta = 0;
    sprite_t **prices = fill_shop_prices();

    mouse_reset(game->mouse);
    shop_f_call(shop);
    game->game_state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_gs(game, game->mouse);
        mouse_check(game->mouse, shop->btn, game, 7);
        if (game->game_state > 10) {
            shop->id = game->game_state - 10;
            game->game_state = 0;
        }
        delta = enemy_handeling(gs->enemy, game);
        bullet_handeling(game, gs, delta);
        tower_change(gs, game, shop);
        shop_bg_display(gs->bg, game);
        shop_display(shop, game, gs, prices);
    }
}