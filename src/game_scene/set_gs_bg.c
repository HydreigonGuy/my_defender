/*
** EPITECH PROJECT, 2021
** set_gs_bg.c
** File description:
** my_defender
*/

#include "header.h"

sprite_t **set_gs_bg(void)
{
    sprite_t  **bg = NULL;

    bg = malloc(sizeof(sprite_t *) * 3);
    bg[0] = fill_sprite("images/battleground.png", 0, 0);
    bg[1] = fill_sprite("images/statsbar.png", 0, 550);
    bg[2] = fill_sprite("images/castle.png", 1050, 100);
    return (bg);
}