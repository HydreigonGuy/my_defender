/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** my_defender
*/

#include "header.h"

int main(int ac, char **av)
{
    game_t *game = NULL;

    game = fill_game();
    start_menu(game);
    free_game(game);
}