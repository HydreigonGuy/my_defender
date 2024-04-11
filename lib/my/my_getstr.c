/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_getstr.c
*/

#include <stdlib.h>

void restart_str(char *str, int size);

char *my_getstr(unsigned int nb)
{
    char *str = NULL;
    int tens = 0;
    long unsigned int n = 1;

    for (; n - 1 < nb ; n *= 10, tens++);
    n /= 10;
    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        restart_str(str, 2);
        str[0] = '0';
    } else {
        str = malloc(sizeof(char) * (tens + 1));
        restart_str(str, tens + 1);
        for (int i = 0 ; i < tens ; i++, n /= 10) {
        str[i] = nb / n;
        nb -= str[i] * n;
        str[i] += '0';
        }
    }
    return str;
}