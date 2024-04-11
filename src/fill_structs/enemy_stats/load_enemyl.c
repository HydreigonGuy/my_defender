/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** load_enemyl.c
*/

#include "header.h"

void fill_new_node(enemy_t *new, sfVector2f pos, int stat[])
{
    new->spd = stat[2];
    new->hp = stat[3];
    sfSprite_setPosition(new->img->spr, pos);
    new->spot = pos.x;
}

static void add_node(enemy_t **head, char *filepath, sfVector2f pos, int stat[])
{
    enemy_t *curr = *head;
    enemy_t *new = NULL;

    pos.y = 100 - stat[1] / 2;
    if (!filepath)
        return;
    for (; curr != NULL && curr->next != NULL; curr = curr->next);
    new = malloc(sizeof(enemy_t));
    if (!new)
        return;
    new->img = fill_sprite(filepath, pos.x, pos.y);
    rect_fill(&(new->img->r), stat[0], stat[1]);
    fill_new_node(new, pos, stat);
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else
        curr->next = new;
}

static void fill_ce_stat(int *stat, int id, int n)
{
    stat[0] = 150;
    stat[2] = enemy_spd(id, n);
    stat[3] = enemy_hp(id, n);
    if (id == 0)
        stat[0] = 100;
    stat[1] = stat[0];
}

enemy_t *create_enemy_list(int nb_wave)
{
    enemy_t *list = NULL;
    sfVector2f pos = {-300, 100};
    int c = 0;
    int stat[4] = {0, 0, 0, 0};

    for (int j = 3; j >= 0; j--) {
        c = enemy_count(j, nb_wave);
        fill_ce_stat(stat, j, nb_wave);
        for (int i = 0 ; i < c ; i++) {
            pos.x -= 150;
            add_node(&list, enemy_f_name(j), pos, stat);
        }
    }
    return list;
}