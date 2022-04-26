/*
** EPITECH PROJECT, 2021
** frame_rate.c
** File description:
** fct frame_rate management
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void check_fr(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, m->f_r->b_down->size,
        m->f_r->b_down->pos) == 1) {
        refresh_frame_rate(-5, m, m->music);
        start_press(m->f_r->b_down);
    }
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, m->f_r->b_up->size,
        m->f_r->b_up->pos) == 1) {
        refresh_frame_rate(5, m, m->music);
        start_press(m->f_r->b_up);
    }
}

void draw_frame_rate(struct menu *m, struct frame_rate *fr)
{
    draw_button(fr->b_up, m->window, m->mouse);
    draw_button(fr->b_down, m->window, m->mouse);
    sfRenderWindow_drawText(m->window, fr->text, NULL);
    sfRenderWindow_drawText(m->window, fr->title, NULL);
}

void destroy_frame_rate(struct frame_rate *fr)
{
    free(fr->nb_frame_rate);
    destroy_button(fr->b_up);
    destroy_button(fr->b_down);
    sfFont_destroy(fr->font);
    sfText_destroy(fr->title);
    sfText_destroy(fr->text);
    free(fr);
}

void refresh_frame_rate(int up, struct menu *m, struct music *music)
{
    sfSound_play(music->button);
    m->f_r->frame_rate += up;
    if (m->f_r->frame_rate < 5)
        m->f_r->frame_rate = 5;
    if (m->f_r->frame_rate > 200)
        m->f_r->frame_rate = 200;
    free(m->f_r->nb_frame_rate);
    m->f_r->nb_frame_rate = my_int_to_str(m->f_r->frame_rate);
    sfText_setString(m->f_r->text, m->f_r->nb_frame_rate);
    sfRenderWindow_setFramerateLimit(m->window, m->f_r->frame_rate);
}

struct frame_rate *create_frame_rate(void)
{
    struct frame_rate *fr = malloc(sizeof(struct frame_rate) * 1);
    int up = 0;
    int x = 0;

    if (fr == NULL)
        return NULL;
    fr->b_down = create_button(vect(70, 70), vect(900, 700), "-", TRANS);
    fr->b_up = create_button(vect(70, 70), vect(1280, 700), "+", TRANS);
    if (fr->b_down == NULL || fr->b_up == NULL)
        return NULL;
    fr->frame_rate = 60;
    fr->nb_frame_rate = my_int_to_str(fr->frame_rate);
    if (fr->nb_frame_rate = NULL)
        return NULL;
    fr->font = sfFont_createFromFile("sprite/police.TTF");
    fr->text = create_text(fr->font, vect(1030, 670), "60", 120);
    fr->title = create_text(fr->font, vect(350, 690), "Frame rate :", 70);
    return fr;
}
