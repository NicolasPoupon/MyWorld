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

int help_create_other_button(struct b_game *b)
{
    b->press = create_button_s("sprite/press.png", vect(1620, 50),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->shovel = create_button_s("sprite/shovel.png", vect(1520, 50),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->settings = create_button_s("sprite/settings.png", vect(1420, 50),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->exit = create_button_s("sprite/exit.png", vect(1320, 150),
    vect(0.1, 0.1), vect(0.1, 0.1));
    if (b->press == NULL || b->shovel == NULL || b->settings == NULL
        || b->settings == NULL || b->exit == NULL)
        return 84;
    return 0;
}

int create_other_button(struct b_game *b)
{
    b->arrow_up = create_button_s("sprite/up-arrow.png", vect(1720, 250),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->arrow_down = create_button_s("sprite/down-arrow.png", vect(1720, 350),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->arrow_right = create_button_s("sprite/right-arrow.png", vect(1820, 300),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->arrow_left = create_button_s("sprite/left-arrow.png", vect(1620, 300),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->zoom = create_button_s("sprite/zoom.png", vect(1820, 50),
    vect(0.1, 0.1), vect(0.1, 0.1));
    b->dezoom = create_button_s("sprite/dezoom.png", vect(1720, 50),
    vect(0.1, 0.1), vect(0.1, 0.1));
    if (b->arrow_up == NULL || b->arrow_down == NULL ||
        b->arrow_right == NULL || b->arrow_left == NULL ||
        b->zoom == NULL || b->dezoom == NULL ||
        help_create_other_button(b) == 84)
        return 84;
    add_text_button_game(b);
    return 0;
}
