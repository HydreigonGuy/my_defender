/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** run_tuto.c
*/

#include "header.h"

static void get_str_tuto(sfText *text)
{
    char string[] = "\
The world has fallen under the controle of bugs and only one bug free zone\n\
remains. You must defend it at all cost. For that you can hire mercenaries\n\
through the shop and place them on the emplacements. All of them have their\n\
specialities: one slows down the enemies, one is a mele expert and the two\n\
others are long distance fighters. To hire or upgrade them you need coins,\n\
you can earn them by clearing waves. If a bug manages to go to the zone, you\n\
lose. But if you can survive 13 waves, you win. If you want to take a break,\n\
press 'escape' to pause the game. You can also get to the settings menu, the\n\
\t\t\t  starting menu or quit the game from the pause menu.\n\
\t\t\t\t\t\t\t\t\t\t\t\t\t  Good luck!";

    sfText_setString(text, string);
}

static sfText *get_txt_tuto(void)
{
    sfText *text = sfText_create();
    sfFont *f = sfFont_createFromFile("/usr/share/fonts/dejavu/DejaVuSans.ttf");

    if (!text)
        return NULL;
    get_str_tuto(text);
    sfText_setFont(text, f);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 25);
    sfText_setPosition(text, (sfVector2f){100, 20});
    return text;
}

button_t **tuto_buttons_fill(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 2);
    for (int i = 0; i < 2; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->status = 0;
    }
    btn[0]->spr = fill_sprite("images/start_button.png", 400, 350);
    rect_fill(&btn[0]->spr->r, 400, 200);
    btn[1]->spr = fill_sprite("images/back_to_start.png", 500, 575);
    rect_fill(&btn[1]->spr->r, 200, 100);
    sfSprite_setPosition(btn[0]->spr->spr, btn[0]->spr->crds);
    sfSprite_setPosition(btn[1]->spr->spr, btn[1]->spr->crds);
    return (btn);
}

void tuto_game_state(game_t *game)
{
    if (game->game_state == 10)
        game->game_state = 8;
    if (game->game_state == 11)
        game->game_state = 9;
}

void run_tuto(game_t *game)
{
    sprite_t *bg = fill_sprite("images/back_ground_pause.png", 0, 0);
    button_t **btn = tuto_buttons_fill();
    sfText *text = get_txt_tuto();

    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->game_state == 0) {
        event_check_start(game->window, game->mouse);
        mouse_check(game->mouse, btn, game, 2);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, bg->spr, NULL);
        sfRenderWindow_drawText(game->window, text, NULL);
        for (int i = 0; i < 2; i++) {
            sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
            sfRenderWindow_drawSprite(game->window, btn[i]->spr->spr, NULL);
        }
        sfRenderWindow_display(game->window);
    }
    tuto_game_state(game);
    sfText_destroy(text);
    free_sprite(bg);
}