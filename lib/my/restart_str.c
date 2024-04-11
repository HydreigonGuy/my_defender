/*
** EPITECH PROJECT, 2020
** restart_str
** File description:
** after a malloc initialize all boxes at 0
*/

void restart_str(char *str, int size)
{
    for (int i = 0 ; i < size ; i++)
        str[i] = 0;
}