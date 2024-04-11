/*
** EPITECH PROJECT, 2021
** header.h
** File description:
** my_defender
*/

#ifndef HEADER
#define HEADER

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

enum enemy {
    ONE,
    TWO,
    THREE,
    FOUR,
};

enum btn_settings {
    MUSIC = 10,
    SOUND,
    PLUS,
    MINUS,
    QUIT,
};

typedef struct {
    int x;
    int y;
    int p_x;
    int p_y;
    int r_x;
    int r_y;
} mouse_t;

typedef struct {
    sfTexture *txtr;
    sfSprite *spr;
    sfIntRect r;
    sfVector2f crds;
} sprite_t;

typedef struct bullet_s {
    sprite_t *img;
    int damage;
    int range;
    int speed;
    struct bullet_s *next;
} bullet_t;

typedef struct enemy_s {
    sprite_t *img;
    int spd;
    int spot;
    int hp;
    int type;
    struct enemy_s *next;
} enemy_t;

typedef struct {
    sprite_t *hold;
    sprite_t *spr;
    int damage;
    int range;
    int rchrg_time;
    int last_rchrg;
    int type;
} tower_t;

typedef struct sound_s {
    sfSoundBuffer *buff;
    sfSound *sound;
    struct sound_s *next;
} sound_t;

typedef struct sounds_s {
    sfMusic *music;
    sound_t *l_sounds;
} sounds_t;

typedef struct {
    mouse_t *mouse;
    sfRenderWindow *window;
    sfClock *clock;
    sounds_t *sounds;
    sfTime time;
    int game_state;
    int score;
    int currency;
} game_t;

typedef struct {
    sprite_t *spr;
    int status;
} button_t;

typedef struct shop_s {
    sprite_t *shop;
    button_t **btn;
    int id;
    int s;
} shop_t;

typedef struct gs_s{
    sprite_t **bg;
    tower_t **twr;
    button_t **btn;
    enemy_t *enemy;
    bullet_t *bullet;
    sprite_t **nums;
    int wave;
} gs_t;

typedef struct text_s {
    sfText *text;
    sfFont *f;
} text_t;

void start_menu(game_t *game);
button_t **fill_start_btn(void);
mouse_t *mouse_fill(void);
void event_check_start(sfRenderWindow *w, mouse_t *mc);

void free_sprite(sprite_t *img);
void free_game(game_t *b);

game_t *fill_game(void);
sprite_t *fill_sprite(char *file, int setx, int sety);
enemy_t *create_enemy(char *file, int type);
tower_t **towers_set(void);
int t_x(int i);
int t_y(int i);

void rect_fill(sfIntRect *rect, int x, int y);

int mouse_on_button(mouse_t *m, button_t *btn);
void mouse_check(mouse_t *mouse, button_t **btn, game_t *game, int c);
int mouse_released_on_button(mouse_t *m, button_t *btn);
int mouse_pressed_button(mouse_t *m, button_t *btn);
void mouse_reset(mouse_t *mouse);

void scene_pick(game_t *game);

int game_scene(game_t *game);
void gs_button_press(game_t *game, gs_t *gs);
void event_check_gs(game_t *, mouse_t *mc);
sprite_t **set_gs_bg(void);
int new_rect_set(sfTime t);
button_t **gs_btn_fill(void);
gs_t *gs_fill_struct(void);
void display_enemy(game_t *g, enemy_t *e, bullet_t *b, int r);
int enemy_handeling(enemy_t *enemy, game_t *game);

int shop(game_t *game, gs_t *gs);
shop_t *fill_shop_display(void);
void shop_display(shop_t *s, game_t *g, gs_t *gs, sprite_t **);
void tower_change(gs_t *gs, game_t *g, shop_t *shop);
int new_t(int id, int spot, tower_t *t, int);
void change_upgrade_btn(shop_t *shop, int type);
int upgrade_to_2(int id, int spot, tower_t *t);
int upgrade_to_3(int id, int spot, tower_t *t);
int upgrade_tower(int id, int spot, tower_t *t, int id2);

void pause_menu(game_t *game);
button_t **fill_pause_btn(void);
void pm_btn_handeling(game_t *game);

void set_volume(sounds_t *sounds, char ope);
void play_stop_sound(sounds_t *sounds, mouse_t *mouse);
void play_stop_music(sfMusic *music, mouse_t *mouse);
void play_sound(sound_t *sound);
sounds_t *create_sounds(char **filepaths);

void settings(game_t *game);
button_t **fill_settings_btn(void);
void stngs_button_handeling(game_t *game);

enemy_t *create_enemy_list(int nb_wave);
int enemy_spd(int type, int n);
int enemy_hp(int type, int round);
char *enemy_f_name(int type);
int enemy_count(int type, int n);
void destroy_enemy(enemy_t **head, int nb);

void victory(game_t *game);
void game_over(game_t *game);
button_t **fill_win_btn(void);
int end_set_new(int a);
void free_ele(button_t **btn, sprite_t *bg, sprite_t *win, text_t *s);

char *my_getstr(unsigned int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
int bullet_speed(int type);
int bullet_range(int type);
int bullet_dmg(int type);
int bullet_size(int t);
bullet_t *destroy_bullet(bullet_t **head, int nb);
void check_bullets(gs_t *gs, game_t *g);
void bullet_handeling(game_t *game, gs_t *gs, int delta);
void add_bullet(bullet_t **head, sfVector2f pos, int type);

void update_stats(gs_t *gs, game_t *game);

void run_tuto(game_t *game);

text_t *get_text(char *str, unsigned int char_size, int x, int y);
void destroy_text(text_t *text);
void display_score(sfRenderWindow *win, text_t *score);
char *my_strcat(char *dest, char const *src);

#endif /* !HEADER */