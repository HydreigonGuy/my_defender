/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** get_txt.c
*/

#include "header.h"

text_t *get_text(char *str, unsigned int char_size, int x, int y)
{
    text_t *s_txt = NULL;
    sfVector2f pos = {x, y};

    s_txt = malloc(sizeof(text_t));
    if (!s_txt || !str)
        return NULL;
    s_txt->text = sfText_create();
    s_txt->f = sfFont_createFromFile("/usr/share/fonts/dejavu/DejaVuSans.ttf");
    sfText_setString(s_txt->text, str);
    sfText_setFont(s_txt->text, s_txt->f);
    sfText_setCharacterSize(s_txt->text, char_size);
    sfText_setPosition(s_txt->text, pos);
    return s_txt;
}

void destroy_text(text_t *text)
{
    sfFont_destroy(text->f);
    sfText_destroy(text->text);
    free(text);
}