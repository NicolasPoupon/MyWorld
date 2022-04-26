/*
** EPITECH PROJECT, 2021
** world
** File description:
** timer.c
*/

#include "../include/my.h"
#include "../include/p.h"

void move_timer(sfClock *cl_two, sfRenderWindow *w, sfEvent ev)
{
    if (sfClock_getElapsedTime(cl_two).microseconds / 1000000.0 > 0.01) {
        sfClock_restart(cl_two);
    }
}

void timer_actions(sfClock *cl, sfRenderWindow *w)
{
    if (sfClock_getElapsedTime(cl).microseconds / 1000000.0 > 0.08) {
        sfClock_restart(cl);
    }
    sfRenderWindow_display(w);
}
