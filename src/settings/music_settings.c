/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** music_settings.c
*/

#include "header.h"

void play_stop_music(sfMusic *music, mouse_t *mouse)
{
    switch (sfMusic_getStatus(music)) {
        case sfPlaying:
            sfMusic_stop(music);
            break;
        case sfStopped:
            sfMusic_play(music);
            break;
        default:
            return;
    }
    mouse->r_x = 0;
}

void play_stop_sound(sounds_t *sounds, mouse_t *mouse)
{
    if (sounds->l_sounds == NULL)
        return;
    if (sfSound_getStatus(sounds->l_sounds->sound) == sfPaused) {
        for (sound_t *curr = sounds->l_sounds; curr != NULL; curr = curr->next)
            sfSound_stop(curr->sound);
            mouse->r_x = 0;
        return;
    }
    if (sfSound_getStatus(sounds->l_sounds->sound) == sfStopped) {
        for (sound_t *curr = sounds->l_sounds; curr != NULL; curr = curr->next)
            sfSound_play(curr->sound);
    }
    for (sound_t *curr = sounds->l_sounds; curr != NULL; curr = curr->next)
        sfSound_pause(curr->sound);
    mouse->r_x = 0;
}

void set_volume(sounds_t *sounds, char ope)
{
    float volume = 0;

    if (ope != '+' && ope != '-')
        return;
    volume = sfMusic_getVolume(sounds->music);
    volume = (ope == '+' ? volume + 10 : volume - 10);
    if (volume > 100 || volume < 0)
        return;
    sfMusic_setVolume(sounds->music, volume);
    for (sound_t *curr = sounds->l_sounds; curr != NULL; curr = curr->next)
        sfSound_setVolume(curr->sound, volume);
}

void play_sound(sound_t *sound)
{
    if (sfSound_getStatus(sound->sound) == sfPaused)
        return;
    sfSound_play(sound->sound);
}