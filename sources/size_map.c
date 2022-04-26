/*
** EPITECH PROJECT, 2021
** size_map.c
** File description:
** fct size map management
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void event_size_map(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (m->nb_menu == 1) {
        if (event.type == sfEvtMouseButtonPressed &&
            pos_is_inrect(m->mouse, m->s_m->b_down->size,
            m->s_m->b_down->pos) == 1) {
            refresh_size_map(-JUMP_SIZE_MAP, m, m->music);
            start_press(m->s_m->b_down);
        }
        if (event.type == sfEvtMouseButtonPressed &&
            pos_is_inrect(m->mouse, m->s_m->b_up->size,
            m->s_m->b_up->pos) == 1) {
            refresh_size_map(JUMP_SIZE_MAP, m, m->music);
            start_press(m->s_m->b_up);
        }
    }
}

void draw_size_map(struct menu *m, struct size_map *sm)
{
    draw_button(sm->b_up, m->window, m->mouse);
    draw_button(sm->b_down, m->window, m->mouse);
    sfRenderWindow_drawText(m->window, sm->text, NULL);
    sfRenderWindow_drawText(m->window, sm->title, NULL);
}

void destroy_size_map(struct size_map *sm)
{
    free(sm->size_str);
    destroy_button(sm->b_up);
    destroy_button(sm->b_down);
    sfFont_destroy(sm->font);
    sfText_destroy(sm->title);
    sfText_destroy(sm->text);
    free(sm);
}

void refresh_size_map(int up, struct menu *m, struct music *music)
{
    sfSound_play(music->button);
    m->s_m->size_int += up;
    if (m->s_m->size_int < SIZE_MIN_MAP)
        m->s_m->size_int = SIZE_MIN_MAP;
    if (m->s_m->size_int > SIZE_MAX_MAP)
        m->s_m->size_int = SIZE_MAX_MAP;
    free(m->s_m->size_str);
    m->s_m->size_str = my_int_to_str(m->s_m->size_int);
    sfText_setString(m->s_m->text, m->s_m->size_str);
    sfRenderWindow_setFramerateLimit(m->window, m->s_m->size_int);
}

struct size_map *create_size_map(void)
{
    struct size_map *sm = malloc(sizeof(struct size_map) * 1);
    int up = 0;
    int x = 0;

    if (sm == NULL)
        return NULL;
    sm->b_down = create_button(vect(70, 70), vect(770, 480), "-", TRANS);
    sm->b_up = create_button(vect(70, 70), vect(1060, 480), "+", TRANS);
    if (sm->b_down == NULL || sm->b_up == NULL)
        return NULL;
    sm->size_int = 20;
    sm->size_str = my_int_to_str(sm->size_int);
    if (sm->size_str = NULL)
        return NULL;
    sm->font = sfFont_createFromFile("sprite/police.TTF");
    sm->text = create_text(sm->font, vect(900, 460), "20", 80);
    sm->title = create_text(sm->font, vect(370, 460), "Map size :", 70);
    return sm;
}
