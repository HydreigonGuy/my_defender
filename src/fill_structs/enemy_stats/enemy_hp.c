/*
** EPITECH PROJECT, 2021
** enemy_hp.c
** File description:
** my defender
*/

#include "header.h"

int enemy_hp(int type, int round)
{
    if (type == 0)
        return (1);
    if (type == 1)
        return (3 + round / 3);
    if (type == 2)
        return (8);
    if (type == 3)
        return (8 + round / 2);
    return (0);
}