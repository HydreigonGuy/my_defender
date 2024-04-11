/*
** EPITECH PROJECT, 2021
** mouse_fill.c
** File description:
** my_defender
*/

#include "header.h"

mouse_t *mouse_fill(void)
{
    mouse_t *mouse = NULL;

    mouse = malloc(sizeof(mouse_t));
    mouse->x = 0;
    mouse->y = 0;
    mouse->p_x = 0;
    mouse->p_y = 0;
    mouse->r_x = 0;
    mouse->r_y = 0;
    return (mouse);
}