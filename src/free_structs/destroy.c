/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** destroy_enemy.c
*/

#include "header.h"

void free_sprite(sprite_t *img)
{
    sfSprite_destroy(img->spr);
    sfTexture_destroy(img->txtr);
    free(img);
}

bullet_t *destroy_bullet(bullet_t **head, int nb)
{
    bullet_t *del = *head;
    bullet_t *prev = *head;

    if (!head || *head == NULL)
        return NULL;
    if (nb == 0) {
        *head = del->next;
        free_sprite(del->img);
        free(del);
        return *head;
    }
    for (int i = 0 ; i < nb && del->next != NULL; i++, del = del->next);
    for (int i = 0 ; i < nb - 1 && prev->next->next != NULL; i++, \
    prev = prev->next);
    prev->next = del->next;
    free_sprite(del->img);
    free(del);
    return prev->next;
}

void destroy_enemy(enemy_t **head, int nb)
{
    enemy_t *to_del = *head;
    enemy_t *prev = *head;

    if (nb == 0) {
        *head = (*head)->next;
        free_sprite(to_del->img);
        free(to_del);
        return;
    }
    for (int i = 0 ; i < nb ; i++, to_del = to_del->next);
    for (int i = 0 ; i < nb - 1 ; i++, prev = prev->next);
    prev->next = to_del->next;
    free_sprite(to_del->img);
    free(to_del);
}