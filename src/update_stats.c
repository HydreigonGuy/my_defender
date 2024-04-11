/*
** EPITECH PROJECT, 2021
** update_stats.c
** File description:
** my defender
*/

#include "header.h"

void rerect_score(sfIntRect *rect, int score)
{
    if (score == 0)
        rect->left = 360;
    else
        rect->left = 40 * (score - 1);
}

void new_score(sprite_t **nums, int score, int start, int end)
{
    int c = 1;

    for (int i = start; i < end; i++, c = 1) {
        for (int j = i + 1; j < end; j++)
            c = c * 10;
        rerect_score(&nums[i]->r, score / c);
        score = score % c;
        sfSprite_setTextureRect(nums[i]->spr, nums[i]->r);
    }
}

void update_stats(gs_t *gs, game_t *game)
{
    new_score(gs->nums, game->currency, 0, 2);
    new_score(gs->nums, gs->wave, 2, 4);
    new_score(gs->nums, game->score, 4, 9);
}