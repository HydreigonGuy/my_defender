/*
** EPITECH PROJECT, 2021
** bullet_stats.c
** File description:
** my defender
*/

#include "header.h"

int bullet_size(int t)
{
    if (t > 10)
        t = t % 10;
    if (t == 2)
        return (10);
    return (30);
}

int bullet_dmg(int type)
{
    int ret = 0;

    if (type == 23)
        return (1);
    if (type > 10) {
        if (type >= 30)
            ret += 2;
        type = type % 10;
    }
    if (type == 1 || type == 2)
        ret += 1;
    else if (type == 3)
        ret += 3;
    else
        ret += 2;
    return (ret);
}

int bullet_range(int type)
{
    if (type == 21)
        return (200);
    if (type == 24)
        return (1001);
    if (type > 10)
        type = type % 10;
    if (type == 2 || type == 3)
        return (1000);
    if (type == 4)
        return (101);
    return (75);
}

int bullet_speed(int type)
{
    return (10);
}
