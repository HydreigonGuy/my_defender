/*
** EPITECH PROJECT, 2021
** new_rect_set.c
** File description:
** my_defender
*/

#include "header.h"

int new_rect_set(sfTime t)
{
    int len = t.microseconds / 30000;

    if (len % 40 > 10 && len % 40 < 20)
        return (0);
    if (len % 40 > 30)
        return (200);
    return (100);
}