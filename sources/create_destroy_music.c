/*
** EPITECH PROJECT, 2021
** create_destroy_music.c
** File description:
** create or destroy music
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <time.h>

void destroy_music(struct music *music)
{
    sfMusic_destroy(music->menu);
    sfSound_destroy(music->button);
    sfSoundBuffer_destroy(music->buff_button);
    free(music);
}

struct music *create_music(struct music *m)
{
    m = malloc(sizeof(struct music) * 2);
    if (m == NULL)
        return NULL;
    m->menu = sfMusic_createFromFile("sprite/music_menu.ogg");
    m->button = sfSound_create();
    m->buff_button = sfSoundBuffer_createFromFile("sprite/sound_button.ogg");
    sfSound_setBuffer(m->button, m->buff_button);
    return m;
}
