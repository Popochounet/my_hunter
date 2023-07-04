/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_
    #define MY_HUNTER_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    #define WD_WIDTH 1000
    #define WD_HEIGHT 1000
    #define CTR_X (WD_WIDTH / 2)
    #define CTR_Y (WD_HEIGHT / 2)

    #define NB_SPRITE 6
    #define NB_SOUND 1

    #define PI 3.141592653589793238462643383279

    typedef struct {
        char name[50];
        sfSprite *spr;
        sfTexture *tx;
        sfVector2f pos_ini;
        sfVector2f pos;
        sfVector2f dir;
        sfVector2f vect;
        sfIntRect rect;
        int speed;
        int wdt;
        int hgt;
    } moving_sprite_t;

    typedef struct list_sprite {
        moving_sprite_t *m_spt;
        struct list_sprite *next;
    } list_sprite_t;

    typedef struct {
        sfSound *sound;
        sfSoundBuffer *s_buf;
    } sound_t;

    typedef struct {
        list_sprite_t **g_spr;
        sound_t *g_sound;
        char title[15];
        int score;
    } game_source_t;

    game_source_t *create_game_source(void);

    void change_sprite_texture(moving_sprite_t *spr_to_set, char *name,
        int width, int height);
    void set_sprite_p_v(moving_sprite_t *spr_to_set, sfVector2f pos,
        sfVector2f go_to, int speed);
    void set_all_sprites(list_sprite_t **all_s);
    list_sprite_t *create_sprite(char* name, int width, int height,
        list_sprite_t *next_enemy);
    list_sprite_t **create_all_sprites(void);

    void check_all_bullet(sfRenderWindow *window, list_sprite_t *bullet,
        game_source_t *g_s, int *started);

    void draw_list_sprite(sfRenderWindow *window, list_sprite_t *begin);
    void draw_all_sprites(sfRenderWindow *window, list_sprite_t **all_s);


    sfVector2f e_spwn_pos(void);
    int create_enemy(list_sprite_t **all_s, sfSprite *bullet, int started);
    void set_enemy_speed(moving_sprite_t *spr);
    void check_all_enemies(sfRenderWindow *window, list_sprite_t *enemy,
        list_sprite_t **all_s);

    void analyse_events(sfRenderWindow *window, sfEvent event,
        game_source_t *g_src, int *started);


    int is_sprite_clicked(sfSprite *spr, sfVector2f coord);

    void manage_mouse_release(list_sprite_t **all_s);
    void manage_mouse_click(sfRenderWindow *window, sfMouseButtonEvent event,
        game_source_t *g_src, int *started);

    void pause_game(list_sprite_t **all_s, int *started);
    void start_game(list_sprite_t **all_s);
    void set_menu_box(list_sprite_t **all_s, int start_game);
    int menu_box_clicked(sfRenderWindow *window, list_sprite_t **all_s,
        sfVector2f coord);

    void start_sprite_move(moving_sprite_t *spr);
    void stop_sprite_move(moving_sprite_t *spr);
    void stop_if(moving_sprite_t *spr);
    void move_sprite(moving_sprite_t *sprite_to_move);

    int on_sprite(sfFloatRect contain_bd, sfSprite *spr_on);
    int on_screen_roll(list_sprite_t *bgn);
    int on_sprite_roll(sfSprite *spr, list_sprite_t *bgn);

    void set_rect(moving_sprite_t *spr, int width, int height,
        sfVector2i offset);
    void set_all_rect(list_sprite_t **all_s);

    int cmp_vectf(sfVector2f vect1, sfVector2f vect2, int prc);
    sfVector2f vectf(float x, float y);
    sfVector2i vecti(int x, int y);

    list_sprite_t roll_list(list_sprite_t *begin, void (*fct)());
    void roll_all_sprites(list_sprite_t **all_s, void (*fct)());
    void check_all_sprite_pos(sfRenderWindow *window, game_source_t *game_src,
        int *started);
    void change_list_texture(list_sprite_t *bgn, char *name, int width,
        int height);

    void update_score_title(sfRenderWindow *window, game_source_t *game_src);

    void destroy_all(game_source_t *g_src, sfClock *m_clock,
        sfRenderWindow *window);

    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_putstr(char const *str);

    void print_info(void);

#endif /* MY_HUNTER_ */
