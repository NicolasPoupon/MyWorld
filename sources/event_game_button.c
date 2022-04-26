/*
** EPITECH PROJECT, 2021
** event_game_button.c
** File description:
** event game button management
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static void fourth_help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->arrow_right, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->xoffset += (2 * vi->distance) + 1;
    }
    if (if_button_s_pressed(m->b_game->turn, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->angle += DEGTRAD(2);
    }
    if (if_button_s_pressed(m->b_game->press, m->window,
        m->mouse, event) == 1)
        sfSound_play(m->music->button);
    fifth_help_game_button_pressed(m, event, mi, vi);
}

static void third_help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->shovel, m->window,
    m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        mi->tool_ind = 1;
    }
    if (if_button_s_pressed(m->b_game->settings, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        m->nb_menu = 2;
        start_press(m->b_vol);
    }
    if (if_button_s_pressed(m->b_game->exit, m->window,
        m->mouse, event) == 1) {
        sfRenderWindow_close(m->window);
        sfSound_play(m->music->button);
    }
    fourth_help_game_button_pressed(m, event, mi, vi);
}

static void second_help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->arrow_left, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->xoffset -= (2 * vi->distance) + 1;
    }
    if (if_button_s_pressed(m->b_game->zoom, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->distance += 5;
    }
    if (if_button_s_pressed(m->b_game->dezoom, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        if (vi->distance - 5 > 0)
            vi->distance -= 5;
    }
    third_help_game_button_pressed(m, event, mi, vi);
}

static void help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->up_down, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->anglesin -= DEGTRAD(2);
    }
    if (if_button_s_pressed(m->b_game->arrow_up, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->yoffset -= (2 * vi->distance) + 1;
    }
    if (if_button_s_pressed(m->b_game->arrow_down, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        vi->yoffset += (2 * vi->distance) + 1;
    }
    second_help_game_button_pressed(m, event, mi, vi);
}

void if_game_button_pressed(struct menu *m, sfEvent event,
struct map_info *mi, struct view_info *vi)
{
    if (if_button_s_pressed(m->b_game->color, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        change_color_index(mi);
    }
    if (if_button_s_pressed(m->b_game->minus, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        mi->tool_size -= 1;
    }
    if (if_button_s_pressed(m->b_game->plus, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        mi->tool_size += 1;
    }
    help_game_button_pressed(m, event, mi , vi);
}
