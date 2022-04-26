/*
** EPITECH PROJECT, 2021
** sprite.c
** File description:
** create destroy sprite
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfTexture *create_sprite(sfSprite *sprite, sfTexture *texture, sfVector2f pos,
char *path_sprite) {
    texture = sfTexture_createFromFile(path_sprite, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return texture;
}

void destroy_sprite(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}
