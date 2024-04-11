/*
** EPITECH PROJECT, 2021
** free_game.c
** File description:
** my_defender
*/

#include "header.h"

static void destroy_node(sound_t **head)
{
    sound_t *to_del = *head;

    *head = (*head)->next;
    sfSound_destroy(to_del->sound);
    sfSoundBuffer_destroy(to_del->buff);
    to_del->next = NULL;
    free(to_del);
}

static void destroy_sounds(sounds_t *sounds)
{
    sound_t *tmp = NULL;

    sfMusic_destroy(sounds->music);
    for (sound_t *s = sounds->l_sounds; s != NULL; ) {
        tmp = s;
        s = s->next;
        sfSound_stop(tmp->sound);
        sfSound_destroy(tmp->sound);
        sfSoundBuffer_destroy(tmp->buff);
        free(tmp);
    }
    free(sounds);
}

void free_game(game_t *b)
{
    sfRenderWindow_destroy(b->window);
    sfClock_destroy(b->clock);
    destroy_sounds(b->sounds);
    free(b->mouse);
    free(b);
}