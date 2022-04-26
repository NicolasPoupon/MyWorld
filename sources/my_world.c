/*
** EPITECH PROJECT, 2021
** my_world.c
** File description:
** my world
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void check_music_fr(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, v->b_up->size, v->b_up->pos) == 1) {
        refresh_vol(v, 0, m->music);
        start_press(v->b_up);
    }
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, v->b_down->size, v->b_down->pos) == 1) {
        refresh_vol(v, 1, m->music);
        start_press(v->b_down);
    }
    check_fr(m, event, v);
}

void event_menu2(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, v->b_ret->size, v->b_ret->pos) == 1
        && m->nb_menu == 2) {
        start_press(v->b_ret);
        sfSound_play(m->music->button);
        m->nb_menu = 1;
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(m->window);
    if (m->nb_menu == 2)
        check_music_fr(m, event, v);
    event_size_map(m, event, v);
}

void event_menu(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, m->b_start->size, m->b_start->pos) == 1
        && m->nb_menu == 1) {
        sfSound_play(m->music->button);
        start_press(m->b_start);
        create_game(m->window, m);
    }
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, m->b_vol->size, m->b_vol->pos) == 1
        && m->nb_menu == 1) {
        start_press(m->b_vol);
        sfSound_play(m->music->button);
        m->nb_menu = 2;
    }
    event_menu2(m, event, v);
}

void display_menu(struct menu *m, sfEvent event)
{
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_drawSprite(m->window, m->background, NULL);
    sfRenderWindow_drawSprite(m->window, m->panel, NULL);
    if (m->nb_menu == 1) {
        sfRenderWindow_drawText(m->window, m->title, NULL);
        draw_button(m->b_start, m->window, m->mouse);
        draw_button(m->b_vol, m->window, m->mouse);
        draw_size_map(m, m->s_m);
    }
    if (m->nb_menu == 2) {
        draw_music_volume(m, m->m_vol);
        draw_frame_rate(m, m->f_r);
    }
    if (m->if_gate == 1)
        sfRenderWindow_drawSprite(m->window, m->gate, NULL);
    sfRenderWindow_display(m->window);
    while (sfRenderWindow_pollEvent(m->window, &event))
        event_menu(m, event, m->m_vol);
    sfRenderWindow_clear(m->window, sfBlack);
}

int my_world(int gate)
{
    struct menu *menu = create_menu(menu, gate);
    sfEvent event;

    if (menu == NULL)
        return 84;
    sfMusic_play(menu->music->menu);
    sfMusic_setLoop(menu->music->menu, sfTrue);
    while (sfRenderWindow_isOpen(menu->window)) {
        display_menu(menu, event);
    }
    sfMusic_stop(menu->music->menu);
    destroy_menu(menu);
    return (0);
}
