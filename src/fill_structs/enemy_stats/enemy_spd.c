/*
** EPITECH PROJECT, 2021
** enemy_spd.c
** File description:
** my defender
*/

#include "header.h"

int enemy_spd(int type, int n)
{
    if (type == 0)
        return (n + 3);
    if (type == 1)
        return (5);
    if (type == 2)
        return (8);
    if (type == 3)
        return (4);
    return (0);
}