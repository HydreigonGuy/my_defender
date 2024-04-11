/*
** EPITECH PROJECT, 2021
** change_upgrade_btn.c
** File description:
** my defender
*/

#include "header.h"

char *slctspr2(int x)
{
    if (x == 1)
        return ("images/ug_k2.png");
    if (x == 2)
        return ("images/ug_g2.png");
    if (x == 3)
        return ("images/ug_b3.png");
    if (x == 4)
        return ("images/ug_f2.png");
    return ("images/upgrade.png");
}

char *slctspr3(int x)
{
    if (x == 1)
        return ("images/ug_k3.png");
    if (x == 2)
        return ("images/ug_g3.png");
    if (x == 3)
        return ("images/ug_b2.png");
    if (x == 4)
        return ("images/ug_f3.png");
    return ("images/upgrade.png");
}

void change_upgrade_btn(shop_t *shop, int type)
{
    int x = shop->btn[5]->spr->crds.x;
    int y = shop->btn[5]->spr->crds.y;

    shop->btn[5]->spr = fill_sprite(slctspr2(type), x, y);
    rect_fill(&shop->btn[5]->spr->r, 200, 100);
    x = shop->btn[6]->spr->crds.x;
    y = shop->btn[6]->spr->crds.y;
    shop->btn[6]->spr = fill_sprite(slctspr3(type), x, y);
    rect_fill(&shop->btn[6]->spr->r, 200, 100);
    sfSprite_setPosition(shop->btn[5]->spr->spr, shop->btn[5]->spr->crds);
    sfSprite_setPosition(shop->btn[6]->spr->spr, shop->btn[6]->spr->crds);
    sfSprite_setTextureRect(shop->btn[5]->spr->spr, shop->btn[5]->spr->r);
    sfSprite_setTextureRect(shop->btn[6]->spr->spr, shop->btn[6]->spr->r);
}