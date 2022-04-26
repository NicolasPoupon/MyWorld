/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myworld-guillaume.clement-bonniel-veyron
** File description:
** tool_event.c
*/

#include "../include/my.h"
#include "../include/p.h"

void check_bool_key(sfRenderWindow *w, struct map_info *mi)
{
    if (mi->press_bool == 1)
        for (int i = 0; i < mi->size[0]; ++i)
            t_keys_s(w, mi, i, 0.2);
    if (mi->press_bool == 2)
        for (int i = 0; i < mi->size[0]; ++i)
            t_keys_s(w, mi, i, -0.2);
    if (mi->press_bool == 3)
        for (int i = 0; i < mi->size[0]; ++i)
                t_keys_f(w, mi, i);
    if (mi->press_bool == 4)
        for (int i = 0; i < (mi->size[0] - 1); ++i)
            t_keys_t(w, mi, i);
}
