/*
** EPITECH PROJECT, 2021
** display_enemy.c
** File description:
** my defender
*/

#include "header.h"

void display_enemy(game_t *g, enemy_t *e, bullet_t *b, int r)
{
    enemy_t *curr = e;
    bullet_t *currr = b;

    for ( ; curr != NULL ; curr = curr->next) {
        if (curr->img->crds.x > -150) {
            curr->img->r.left = r * curr->img->r.width;
            sfSprite_setPosition(curr->img->spr, curr->img->crds);
            sfSprite_setTextureRect(curr->img->spr, curr->img->r);
            sfRenderWindow_drawSprite(g->window, curr->img->spr, NULL);
        }
    }
    for ( ; currr != NULL ; currr = currr->next) {
        sfSprite_setPosition(currr->img->spr, currr->img->crds);
        sfRenderWindow_drawSprite(g->window, currr->img->spr, NULL);
    }
}