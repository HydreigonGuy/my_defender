/*
** EPITECH PROJECT, 2021
** fill_game.c
** File description:
** my_defender.c
*/

#include "header.h"

char **get_musics_name(void)
{
    char **musics = NULL;

    musics = malloc(sizeof(char *) * 4);
    if (!musics)
        return NULL;
    musics[0] = "musics/electronika.wav";
    musics[1] = "musics/cash.wav";
    musics[2] = "musics/wave_alert.wav";
    musics[3] = NULL;
    return musics;
}

game_t *fill_game(void)
{
    game_t *b;
    sfVideoMode m = {1200, 700, 32};
    char wn[] = "Defender";

    b = malloc(sizeof(game_t));
    b->window = sfRenderWindow_create(m, wn, sfResize | sfClose, NULL);
    b->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(b->window, 30);
    b->game_state = 0;
    b->score = 0;
    b->currency = 3;
    b->mouse = mouse_fill();
    b->sounds = create_sounds(get_musics_name());
    return (b);
}