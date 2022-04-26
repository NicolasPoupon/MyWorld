/*
** EPITECH PROJECT, 2021
** check_colli.c
** File description:
** check collision
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int pos_is_inrect(sfVector2i pos, sfVector2f size_rec, sfVector2f pos_rec)
{
    if (pos.x > pos_rec.x && pos.y > pos_rec.y &&
        pos.x < (pos_rec.x + size_rec.x) &&
        pos.y < (pos_rec.y + size_rec.y))
        return 1;
    return 0;
}
