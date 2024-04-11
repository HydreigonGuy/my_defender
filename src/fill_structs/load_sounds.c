/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** load_sounds.c
*/

#include "header.h"

sfMusic *create_music(char *filepath)
{
    sfMusic *music = NULL;

    if (!filepath)
        return NULL;
    music = sfMusic_createFromFile(filepath);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 50);
    return music;
}

void add_sound(sound_t **head, char const *filepath)
{
    sound_t *tail = *head;
    sound_t *new = NULL;

    for ( ; tail != NULL && tail->next != NULL; tail = tail->next);
    new = malloc(sizeof(sound_t));
    if (!new)
        return;
    new->buff = sfSoundBuffer_createFromFile(filepath);
    new->sound = sfSound_create();
    sfSound_setBuffer(new->sound, new->buff);
    sfSound_setVolume(new->sound, 100);
    new->next = NULL;
    if (tail != NULL)
        tail->next = new;
    else
        *head = new;
}

sound_t *create_sound_list(char **filepath)
{
    sound_t *head = NULL;

    if (!filepath)
        return NULL;
    for (int i = 1 ; filepath[i] != NULL ; i++)
        add_sound(&head, filepath[i]);
    return head;
}

sounds_t *create_sounds(char **filepaths)
{
    sounds_t *sounds = NULL;

    if (!filepaths || !filepaths[0])
        return NULL;
    sounds = malloc(sizeof(sounds_t));
    if (!sounds)
        return NULL;
    sounds->music = create_music(filepaths[0]);
    sounds->l_sounds = create_sound_list(filepaths);
    if (!sounds->music || !sounds->l_sounds) {
        write(2, "Error loading music\n", 20);
        return NULL;
    }
    return sounds;
}