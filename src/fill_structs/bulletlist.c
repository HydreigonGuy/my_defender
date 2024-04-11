/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** bulletlist.c
*/

#include "header.h"

char *bullet_filepath(int t)
{
    if (t == 1)
        return ("images/shot_1.png");
    if (t == 2)
        return ("images/shot_2.png");
    if (t == 3)
        return ("images/shot_3.png");
    if (t == 4)
        return ("images/shot_4.png");
}

void add_bullet(bullet_t **head, sfVector2f pos, int type)
{
    bullet_t *tail = *head;
    bullet_t *new = NULL;

    for ( ; tail != NULL && tail->next != NULL ; tail = tail->next);
    new = malloc(sizeof(bullet_t));
    if (!new)
        return;
    pos.y += 50 - (bullet_size(type) / 2);
    new->img = fill_sprite(bullet_filepath(type % 10), pos.x, pos.y);
    rect_fill(&new->img->r, bullet_size(type), bullet_size(type));
    sfSprite_setPosition(new->img->spr, pos);
    new->damage = bullet_dmg(type);
    new->range = bullet_range(type);
    new->speed = bullet_speed(type);
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else
        tail->next = new;
}