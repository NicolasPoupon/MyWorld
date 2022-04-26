/*
** EPITECH PROJECT, 2021
** music_volume.c
** File description:
** fct music_volume mangament
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void draw_music_volume(struct menu *m, struct music_vol *m_vol)
{
    draw_button(m_vol->b_ret, m->window, m->mouse);
    draw_button(m_vol->b_up, m->window, m->mouse);
    draw_button(m_vol->b_down, m->window, m->mouse);
    sfRenderWindow_drawText(m->window, m_vol->title, NULL);
    for (int i = 0; i != 20; i++)
        sfRenderWindow_drawRectangleShape(m->window, m_vol->rect[i], NULL);
}

void destroy_music_vol(struct music_vol *m)
{
    destroy_button(m->b_ret);
    destroy_button(m->b_up);
    destroy_button(m->b_down);
    sfFont_destroy(m->font);
    sfText_destroy(m->title);
    for (int i = 0; i != 20; i++)
        sfRectangleShape_destroy(m->rect[i]);
    free(m->rect);
    free(m);
}

void refresh_vol(struct music_vol *mv, int up, struct music *music)
{
    int nbu = 100 / 20;

    sfSound_play(music->button);
    if (up == 0 && mv->vol != 100) {
        sfRectangleShape_setFillColor(mv->rect[mv->vol / nbu], sfGreen);
        mv->vol += nbu;
    }
    if (up == 1 && mv->vol != 0) {
        mv->vol -= nbu;
        sfRectangleShape_setFillColor(mv->rect[mv->vol / nbu], sfRed);
    }
    sfSound_setVolume(music->button, mv->vol);
    sfMusic_setVolume(music->menu, mv->vol);
}

struct music_vol *create_music_volume(void)
{
    struct music_vol *mv = malloc(sizeof(struct music_vol) * 1);
    int up = 0;
    int x = 0;

    if (mv == NULL)
        return NULL;
    mv->rect = malloc(sizeof(sfRectangleShape*) * (20 + 1));
    mv->b_ret = create_button(vect(360, 90), vect(200, 200), "Return", TRANS);
    mv->b_down = create_button(vect(70, 70), vect(900, 450), "-", TRANS);
    mv->b_up = create_button(vect(70, 70), vect(1500, 450), "+", TRANS);
    if (mv->b_down == NULL || mv->b_up == NULL || mv->rect == NULL)
        return NULL;
    mv->vol = 100;
    for (int i = 0; i != 20; i++, up += 4, x += 20)
        mv->rect[i] = create_rect(vect(15, 10 + up),
        vect(1050 + x, 520 - up), GREEN);
    mv->font = sfFont_createFromFile("sprite/police.TTF");
    mv->title = create_text(mv->font, vect(470, 440), "Volume :", 70);
    return mv;
}
