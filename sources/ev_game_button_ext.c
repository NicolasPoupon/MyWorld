/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myworld-guillaume.clement-bonniel-veyron
** File description:
** ev_game_button_ext.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void fifth_help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->press, m->window,
    m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        mi->tool_ind = 2;
    }
}
