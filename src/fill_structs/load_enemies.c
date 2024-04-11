/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** load_enemies.c
*/

#include "header.h"

static enemy_t *create_one(char *file, int type)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return NULL;
    enemy->hp = 0;
    enemy->spd = 0;
    enemy->type = type;
    enemy->img = fill_sprite(file, 0, 0);
    if (!enemy->img)
        return NULL;
    return enemy;
}

static enemy_t *create_two(char *file, int type)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return NULL;
    enemy->hp = 0;
    enemy->spd = 0;
    enemy->type = type;
    enemy->img = fill_sprite(file, 0, 0);
    if (!enemy->img)
        return NULL;
    return enemy;
}

static enemy_t *create_three(char *file, int type)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return NULL;
    enemy->hp = 0;
    enemy->spd = 0;
    enemy->type = type;
    enemy->img = fill_sprite(file, 0, 0);
    if (!enemy->img)
        return NULL;
    return enemy;
}

static enemy_t *create_four(char *file, int type)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return NULL;
    enemy->hp = 0;
    enemy->spd = 0;
    enemy->type = type;
    enemy->img = fill_sprite(file, 0, 0);
    if (!enemy->img)
        return NULL;
    return enemy;
}

enemy_t *create_enemy(char *file, int type)
{
    enemy_t *(*func[4])(char *f, int t) = {};

    return func[type](file, type);
}