/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** create_game_source.c
*/

#include "../include/my_hunter.h"

sound_t create_sound(char *name)
{
    sound_t new_sound;
    new_sound.sound = sfSound_create();
    new_sound.s_buf = sfSoundBuffer_createFromFile(name);
    sfSound_setBuffer(new_sound.sound, new_sound.s_buf);
    return new_sound;
}

sound_t *create_g_sound(void)
{
    sound_t *g_sound = malloc(sizeof(sound_t) * NB_SOUND);
    g_sound[0] = create_sound("audio/bullet.ogg");
    return g_sound;
}

game_source_t *create_game_source(void)
{
    game_source_t *game_src = malloc(sizeof(game_source_t));
    game_src->g_spr = create_all_sprites();
    game_src->g_sound = create_g_sound();
    my_strcpy(game_src->title, "score: 00000");
    game_src->score = 0;
    return game_src;
}
