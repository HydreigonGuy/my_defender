/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** displays the number of character inside a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
