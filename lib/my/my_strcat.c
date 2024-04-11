/*
** EPITECH PROJECT, 2020
** my strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int nbr_char_dest = my_strlen(dest);
    int nbr_char_src = my_strlen(src);
    char *str = NULL;
    int j = 0;

    str = malloc(sizeof(char) * (nbr_char_dest + nbr_char_src + 1));
    if (!str)
        return  NULL;
    for (int i = 0 ; i <= nbr_char_dest + nbr_char_src ; i++)
        str[i] = 0;
    for (int i = 0 ; dest[i] != 0 ; i++, j++)
        str[j] = dest[i];
    for (int i = 0 ; src[i] != 0 ; i++)
        str[j++] = src[i];
    return str;
}