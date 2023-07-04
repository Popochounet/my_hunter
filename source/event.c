/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** event.c
*/

#include "../include/my_hunter.h"

void move_cursor(sfMouseMoveEvent event, moving_sprite_t *player)
{
    sfVector2f coord = {.x = event.x - CTR_X, .y = event.y - CTR_Y};
    sfSprite_setRotation(player->spr, atan(coord.y / coord.x) / PI * 180);
    if (coord.x >= 0)
        sfSprite_rotate(player->spr, 180);
    if (coord.x == 0 && coord.y == 0)
        sfSprite_setRotation(player->spr, 0);
}

void manage_key_pressed(sfKeyEvent event_k, list_sprite_t **all_s, int *started)
{
    if (event_k.code == sfKeyEscape) {
        pause_game(all_s, started);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event,
    game_source_t *g_src, int *started)
{
    switch (event.type) {
        case sfEvtMouseButtonPressed:
            manage_mouse_click(window, event.mouseButton, g_src, started);
            break;
        case sfEvtMouseMoved:
            move_cursor(event.mouseMove, g_src->g_spr[5]->m_spt);
            break;
        case sfEvtMouseButtonReleased:
            manage_mouse_release(g_src->g_spr);
            break;
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            manage_key_pressed(event.key, g_src->g_spr, started);
            break;
        case sfEvtLostFocus:
            //pause_game(g_src->g_spr, started);
            break;
    }
}
