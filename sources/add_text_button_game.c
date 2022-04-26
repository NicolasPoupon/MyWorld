/*
** EPITECH PROJECT, 2021
** add_text_button_game.c
** File description:
** fct add text button
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static void help_add_text_button(struct b_game *b)
{
    add_text_info(b->settings, "Change settings.\n\n\n\n\nShort cut :\nKey s",
    20, vect(0, 0));
    add_text_info(b->exit, "Exit the game.\n\n\n\n\nShort cut :\nKey e",
    20, vect(0, 0));
}

static void help_add_text_button_game(struct b_game *b)
{
    add_text_info(b->arrow_up,
    "Move up.\n\n\n\n\nShort cut :\nKey UP",
    20, vect(0, 0));
    add_text_info(b->arrow_down,
    "Move down.\n\n\n\n\nShort cut :\nKey DOWN",
    20, vect(0, 0));
    add_text_info(b->arrow_right, "Move right.\n\n\n\nShort cut :\nKey RIGHT",
    20, vect(0, 0));
    add_text_info(b->arrow_left, "Move left.\n\n\n\n\nShort cut :\nKey LEFT",
    20, vect(0, 0));
    add_text_info(b->zoom, "Zoom.\n\n\n\n\nShort cut :\nScroll up",
    20, vect(0, 0));
    add_text_info(b->dezoom, "Zoom out.\n\n\n\n\nShort cut :\nScroll down",
    20, vect(0, 0));
    add_text_info(b->press, "Flatten the map.\n\n\n\n\nShort cut :\nKey y",
    20, vect(0, 0));
    add_text_info(b->shovel, "Dig the map.\n\n\n\n\nShort cut :\nScroll up",
    20, vect(0, 0));
    help_add_text_button(b);
}

void add_text_button_game(struct b_game *b)
{
    add_text_info(b->color,
    "Change the color of\nthe ground.\n\n\nShort cut :\nKey y and right click",
    20, vect(0, 0));
    add_text_info(b->minus,
    "Decreases the hit box.\n\n\n\n\nShort cut :\nKey y and right click",
    20, vect(0, 0));
    add_text_info(b->plus,
    "Increases the hit box\n\n\n\n\nShort cut :\nKey t",
    20, vect(0, 0));
    add_text_info(b->turn,
    "Turn the map.\n\n\n\n\nShort cut :\nKey d and q",
    20, vect(0, 0));
    add_text_info(b->up_down,
    "Move the map vertically.\n\n\n\n\nShort cut :\nKey y and z",
    20, vect(0, 0));
    help_add_text_button_game(b);
}
