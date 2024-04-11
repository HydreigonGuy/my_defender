/*
** EPITECH PROJECT, 2021
** shop_display.c
** File description:
** my defener
*/

#include "header.h"

static void shop_display_tower(tower_t *t, game_t *g, int new)
{
    if (t->type) {
        t->spr->r.left = new;
        sfSprite_setTextureRect(t->spr->spr, t->spr->r);
        sfRenderWindow_drawSprite(g->window, t->spr->spr, NULL);
    } else
        sfRenderWindow_drawSprite(g->window, t->hold->spr, NULL);
}

void shop_display(shop_t *s, game_t *g, gs_t *gs, sprite_t **p)
{
    int new = new_rect_set(sfClock_getElapsedTime(g->clock));

    display_enemy(g, gs->enemy, gs->bullet, new / 100);
    for (int i = 0; i < 12; i++) {
        shop_display_tower(gs->twr[i], g, new);
    }
    sfRenderWindow_drawSprite(g->window, s->shop->spr, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(g->window, p[i]->spr, NULL);
    for (int i = 0; i < 9; i++)
        sfRenderWindow_drawSprite(g->window, gs->nums[i]->spr, NULL);
    for (int i = 0; i < 7; i++) {
        if (s->id == i && i != 0)
            s->btn[i]->spr->r.left = 200;
        if (!(i == 0 && s->btn[i]->status == 2))
            sfSprite_setTextureRect(s->btn[i]->spr->spr, s->btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, s->btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}