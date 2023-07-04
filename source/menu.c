/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** menu.c
*/

#include "../include/my_hunter.h"

void start_game(list_sprite_t **all_s)
{
    roll_list(all_s[0], &set_enemy_speed);
    roll_list(all_s[0], &start_sprite_move);
    change_sprite_texture(all_s[1]->m_spt, "sprites/resume.png", 335, 46);
    change_list_texture(all_s[0], "sprites/enemy.png", 50, 50);
}

void pause_game(list_sprite_t **all_s, int *started)
{
    if (on_screen_roll(all_s[1]) == 0) {
        roll_list(all_s[0], &stop_sprite_move);
        set_menu_box(all_s, 0);
        *started = 0;
    }
}

int menu_box_clicked(sfRenderWindow *wd, list_sprite_t **all_s,
    sfVector2f coord)
{
    if (is_sprite_clicked(all_s[1]->m_spt->spr, coord))
        return 1;
    if (is_sprite_clicked(all_s[2]->m_spt->spr, coord))
        return 3;
    if (is_sprite_clicked(all_s[3]->m_spt->spr, coord))
        sfRenderWindow_close(wd);
    return 0;
}

void set_menu_box(list_sprite_t **all_s, int start_game)
{
    if (start_game == 0) {
        change_list_texture(all_s[0], "sprites/enemy_paused.png", 50, 50);
        set_sprite_p_v(all_s[1]->m_spt, vectf(CTR_X, -24), vectf(CTR_X, 300),
            20);
        set_sprite_p_v(all_s[2]->m_spt, vectf(-81, 700), vectf(300, 700), 20);
        set_sprite_p_v(all_s[3]->m_spt, vectf(1103, 700), vectf(700, 700), 20);
    } else {
        set_sprite_p_v(all_s[1]->m_spt, vectf(CTR_X, 300), vectf(CTR_X, -24),
            45);
        set_sprite_p_v(all_s[2]->m_spt, vectf(300, 700), vectf(-106, 700), 45);
        set_sprite_p_v(all_s[3]->m_spt, vectf(700, 700), vectf(1103, 700), 45);
    }
}
