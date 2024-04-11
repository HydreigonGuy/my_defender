/*
** EPITECH PROJECT, 2021
** enemy_f_name.c
** File description:
** my defender
*/

#include "header.h"

char *enemy_f_name(int type)
{
    if (type == 0)
        return ("images/mosquito.png");
    if (type == 1)
        return ("images/fly.png");
    if (type == 2)
        return ("images/spider.png");
    if (type == 3)
        return ("images/cockroach.png");
    return (0);
}