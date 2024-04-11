/*
** EPITECH PROJECT, 2021
** fill_shop_display.c
** File description:
** my defender
*/

#include "header.h"

static void fill_shop_btn(shop_t *ret)
{
    ret->btn[0]->spr = fill_sprite("images/shop_btn_2.png", 1050, 550);
    rect_fill(&ret->btn[0]->spr->r, 150, 150);
    ret->btn[1]->spr = fill_sprite("images/knife_splash.png", 1075, 25);
    rect_fill(&ret->btn[1]->spr->r, 100, 100);
    ret->btn[2]->spr = fill_sprite("images/gun_splash.png", 1075, 150);
    rect_fill(&ret->btn[2]->spr->r, 100, 100);
    ret->btn[3]->spr = fill_sprite("images/bomb_splash.png", 1075, 275);
    rect_fill(&ret->btn[3]->spr->r, 100, 100);
    ret->btn[4]->spr = fill_sprite("images/freeze_splash.png", 1075, 400);
    rect_fill(&ret->btn[4]->spr->r, 100, 100);
    ret->btn[5]->spr = fill_sprite("images/upgrade.png", 610, 575);
    rect_fill(&ret->btn[5]->spr->r, 200, 100);
    ret->btn[6]->spr = fill_sprite("images/upgrade.png", 820, 575);
    rect_fill(&ret->btn[6]->spr->r, 200, 100);
}

shop_t *fill_shop_display(void)
{
    shop_t *ret = NULL;

    ret = malloc(sizeof(shop_t *));
    ret->shop = fill_sprite("images/shop.png", 1050, 0);
    ret->btn = malloc(sizeof(button_t *) * 7);
    ret->s = -1;
    for (int i = 0; i < 7; i++) {
        ret->btn[i] = malloc(sizeof(button_t));
        ret->btn[i]->status = 0;
    }
    fill_shop_btn(ret);
    ret->id = 0;
    return (ret);
}