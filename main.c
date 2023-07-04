/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** main.c
*/

#include "include/my_hunter.h"

void put(char *str, int line)
{
    my_putstr(str);
    for (int i = 0; i < line; i++)
        my_putstr("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");

}

void print_info(void)
{
    put("\n**************************************************** GAME INFOS ",0);
    put("*********************************************************\n", 1);
    put("*\t=> LORE:\t\t\t\t\t\t\t\t\t\t\t\t\t*\n", 1);
    put("*\t\tfo tirez (notamment) (faire attention a vous)", 0);
    put("\t\t\t\t\t\t\t\t*\n", 2);
    put("*\t=> CONTROLES:\t\t\t\t\t\t\t\t\t\t\t\t\t*\n", 1);
    put("*\t\t-CLICK GAUCHE:\tTire une balle\t\t\t\t\t\t\t\t\t\t*\n", 0);
    put("*\t\t-ECHAP:\tPause le jeu\t\t\t\t\t\t\t\t\t\t\t*\n", 2);
    put("*\t=> COMMENT JOUER AU JEU:\t\t\t\t\t\t\t\t\t\t\t*\n", 1);
    put("*\t\t-Un ennemi veut votre peau !!", 0);
    put(" Tirez-lui dessus avant qu'il ne vous touche !\t\t\t\t*\n", 0);
    put("*\t\t-Si vous le ratez, un de ses copain viendra en renfort !", 0);
    put("\t\t\t\t\t\t*\n", 0);
    put("*\t\t-N'essayez pas d'abuser de la pause, conseil d'ami !", 0);
    put(" (je ne vous connais pas.)\t\t\t\t*\n", 2);
    put("*\t=> CHANGER LA DIFFICULTE:\t\t\t\t\t\t\t\t\t\t\t*\n", 1);
    put("*\t\t-Avant de tirer sur START, tirez en dehors de l'ecran pour", 0);
    put(" augmenter le nombre d'ennemi de départ\t*\n", 1);
    put("******************************************************************",0);
    put("*******************************************************\n\n", 0);
}

void game_engine(sfRenderWindow *window, sfEvent event,
    game_source_t *game_src, int *started)
{
    check_all_sprite_pos(window, game_src, started);
    roll_all_sprites(game_src->g_spr, &move_sprite);
    while (sfRenderWindow_pollEvent(window, &event))
        analyse_events(window, event, game_src, started);
    sfRenderWindow_clear(window, sfBlack);
    draw_all_sprites(window, game_src->g_spr);
}

void window_display(sfRenderWindow *window, game_source_t *game_src)
{
    sfEvent event;
    sfClock *m_clock = sfClock_create();
    sfTime m_time;
    int started = 0;
    while (sfRenderWindow_isOpen(window)) {
        m_time = sfClock_getElapsedTime(m_clock);
        if (m_time.microseconds > 16666) {
            sfClock_restart(m_clock);
            game_engine(window, event, game_src, &started);
        }
        sfRenderWindow_display(window);
    }
    destroy_all(game_src, m_clock, window);
    my_putstr("\n");
    my_putstr(game_src->title);
    my_putstr("\n\n");
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WD_WIDTH, WD_HEIGHT, 8};
    sfRenderWindow *window;
    game_source_t *game_src;
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0 && ac == 2)
            print_info();
        else {
            my_putstr("Try './my_hunter -h' for help\n");
            return 84;
        }
    } else {
    game_src = create_game_source();
    window = sfRenderWindow_create(mode, game_src->title, sfClose, NULL);
    if (!window)
        return 0;
    sfRenderWindow_setFramerateLimit(window, 60);
    window_display(window, game_src);
    }
    return 0;
}
