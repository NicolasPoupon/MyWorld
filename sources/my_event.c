/*
** EPITECH PROJECT, 2021
** my_event.c
** File description:
** my event in game
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void my_event(struct menu *m, sfEvent event)
{
    if (m->nb_menu == 2)
        check_music_fr(m, event, m->m_vol);
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(m->mouse, m->m_vol->b_ret->size,
        m->m_vol->b_ret->pos) == 1 && m->nb_menu == 2) {
        start_press(m->m_vol->b_ret);
        sfSound_play(m->music->button);
        m->nb_menu = 1;
    }
}
