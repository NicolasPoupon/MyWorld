/*
** EPITECH PROJECT, 2021
** world
** File description:
** map.c
*/

#include "../include/my.h"
#include "../include/p.h"

int iso_draw_map_s(struct map_info *mi, sfRenderWindow *w, int pos[2])
{
    if (pos[0] + 1 == mi->size[0] && pos[1] + 1 == mi->size[1])
        return 0;
    else if (pos[0] + 1 == mi->size[0])
        render_line_j(mi->map, pos[0], pos[1], w);
    else if (pos[1] + 1 == mi->size[1])
        render_line_i(mi->map, pos[0], pos[1], w);
    if (pos[0] + 1 != mi->size[0] && pos[1] + 1 != mi->size[1]) {
        render_line_i(mi->map, pos[0], pos[1], w);
        render_line_j(mi->map, pos[0], pos[1], w);
    }
    return 0;
}

int iso_draw_map(sfRenderWindow *win, struct map_info *mi)
{
    int pos[2];

    for (int i = 0; i < mi->size[0]; ++i) {
        for (int j = 0; j < mi->size[1]; ++j) {
            pos[0] = i;
            pos[1] = j;
            iso_draw_map_s(mi, win, pos);
        }
    }
    return 0;
}
