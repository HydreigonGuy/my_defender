/*
** EPITECH PROJECT, 2021
** rect_fill.c
** File description:
** my_defender
*/

#include "header.h"

void rect_fill(sfIntRect *rect, int x, int y)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = x;
    rect->height = y;
}