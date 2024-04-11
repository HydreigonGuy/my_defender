/*
** EPITECH PROJECT, 2021
** gs_fill_struct.c
** File description:
** my_defender
*/

#include "header.h"

sprite_t **gs_nums_set(void)
{
    sprite_t **nums = NULL;
    int x = -20;
    int y = 600;

    nums = malloc(sizeof(sprite_t *) * 9);
    for (int i = 0; i < 9; i++) {
        x += 40;
        if (i == 2 || i == 4)
            x += 110;
        nums[i] = fill_sprite("images/numbers.png", x, y);
        rect_fill(&nums[i]->r, 40, 40);
        sfSprite_setPosition(nums[i]->spr, nums[i]->crds);
        sfSprite_setTextureRect(nums[i]->spr, nums[i]->r);
    }
    return (nums);
}

gs_t *gs_fill_struct(void)
{
    gs_t *ret = NULL;

    ret = malloc(sizeof(gs_t));
    ret->wave = 1;
    ret->btn = gs_btn_fill();
    ret->twr = towers_set();
    ret->bg = set_gs_bg();
    ret->enemy = create_enemy_list(1);
    ret->bullet = NULL;
    ret->nums = gs_nums_set();
    return (ret);
}