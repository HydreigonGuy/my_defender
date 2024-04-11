/*
** EPITECH PROJECT, 2020
** getnbr
** File description:
** returns a int sent as a str
*/

static int is_num(char c)
{
    if (c <= '9' && c >= '0')
        return 1;
    else
        return 0;
}

static int is_neg(char c)
{
    if (c == '-')
        return 1;
    else
        return 0;
}

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int n = 0;

    while (!is_num(str[i]))
        i++;
    j = i;
    while (is_num(str[j])) {
        n += str[j] - '0';
        if (is_num(str[j + 1]))
            n *= 10;
        j++;
    }
    if (is_neg(str[i - 1]))
        n *= -1;
    return n;
}