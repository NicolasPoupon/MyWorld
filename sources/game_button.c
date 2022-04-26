/*
** EPITECH PROJECT, 2021
** game_button.c
** File description:
** game button management
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void draw_button_game(struct menu *m, struct b_game *b)
{
    draw_button_s(b->color, m->window, m->mouse);
    draw_button_s(b->minus, m->window, m->mouse);
    draw_button_s(b->plus, m->window, m->mouse);
    draw_button_s(b->turn, m->window, m->mouse);
    draw_button_s(b->up_down, m->window, m->mouse);
    draw_button_s(b->arrow_up, m->window, m->mouse);
    draw_button_s(b->arrow_down, m->window, m->mouse);
    draw_button_s(b->arrow_right, m->window, m->mouse);
    draw_button_s(b->arrow_left, m->window, m->mouse);
    draw_button_s(b->zoom, m->window, m->mouse);
    draw_button_s(b->dezoom, m->window, m->mouse);
    draw_button_s(b->press, m->window, m->mouse);
    draw_button_s(b->shovel, m->window, m->mouse);
    draw_button_s(b->settings, m->window, m->mouse);
    draw_button_s(b->exit, m->window, m->mouse);
}

void destroy_button_game(struct b_game *b)
{
    destroy_button_s(b->color);
    destroy_button_s(b->minus);
    destroy_button_s(b->plus);
    destroy_button_s(b->turn);
    destroy_button_s(b->up_down);
    destroy_button_s(b->arrow_up);
    destroy_button_s(b->arrow_down);
    destroy_button_s(b->arrow_right);
    destroy_button_s(b->arrow_left);
    destroy_button_s(b->zoom);
    destroy_button_s(b->dezoom);
    destroy_button_s(b->press);
    destroy_button_s(b->shovel);
    destroy_button_s(b->settings);
    destroy_button_s(b->exit);
    free(b);
}

struct b_game *create_button_game(void)
{
    struct b_game *b = malloc(sizeof(struct b_game) * 1);

    if (b == NULL)
        return NULL;
    b->color = create_button_s("sprite/color.png", vect(1820, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->minus = create_button_s("sprite/minus.png", vect(1720, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->plus = create_button_s("sprite/plus.png", vect(1620, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->turn = create_button_s("sprite/turn.png", vect(1520, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->up_down = create_button_s("sprite/up_down.png", vect(1420, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    if (b->color == NULL || b->minus == NULL || b->plus == NULL ||
        b->turn == NULL || b->up_down == NULL || create_other_button(b) == 84)
        return NULL;
    return b;
}
