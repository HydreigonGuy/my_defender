/*
** EPITECH PROJECT, 2021
** enemy_count.c
** File description:
** my defender
*/

#include "header.h"

int enemy_count(int type, int n)
{
    if (type == 0)
        return (3 + 5 * (n / 3));
    if (type == 1)
        return (n);
    if (type == 2)
        return ((n / 4) * (1 + (n / 5) + (n % 3) * (n / 6)));
    if (type == 3)
        return ((n / 7) * ((n / 9) * (n % 2) + (n / 3)));
    return (0);
}