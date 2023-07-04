/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** score.c
*/

#include "../include/my_hunter.h"

void update_score_title(sfRenderWindow *window, game_source_t *game_src)
{
    int score = game_src->score;
    game_src->title[11] = score % 10 + '0';
    score /= 10;
    game_src->title[10] = score % 10 + '0';
    score /= 10;
    game_src->title[9] = score % 10 + '0';
    score /= 10;
    game_src->title[8] = score % 10 + '0';
    score /= 10;
    game_src->title[7] = score % 10 + '0';
    sfRenderWindow_setTitle(window, game_src->title);
}
