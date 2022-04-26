/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myworld-guillaume.clement-bonniel-veyron
** File description:
** shape_handler.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static sfConvexShape *map_cs_s(int i, int j, struct view_info *v,
struct map_info *m)
{
    sfConvexShape *shape = sfConvexShape_create();

    sfConvexShape_setFillColor(shape, m->color_map[i][j]);
    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, m->map[i][j]);
    sfConvexShape_setPoint(shape, 1, m->map[i + 1][j]);
    sfConvexShape_setPoint(shape, 2, m->map[i + 1][j + 1]);
    sfConvexShape_setPoint(shape, 3, m->map[i][j + 1]);
    return shape;
}

sfConvexShape ***map_cs(struct view_info *vi, struct map_info *mi)
{
    sfConvexShape ***cmap = malloc(mi->size[0] * sizeof(sfConvexShape**));

    for (int i = 0; i < mi->size[0]; ++i)
        cmap[i] = malloc(sizeof(sfConvexShape*) * (mi->size[1]));
    for (int i = 0; i < (mi->size[0] - 1); ++i) {
        for (int j = 0; j < (mi->size[1] - 1); ++j) {
            cmap[i][j] = map_cs_s(i, j, vi, mi);
        }
    }
    return cmap;
}

int shape_draw_map(struct map_info *mi, sfRenderWindow *win)
{
    int pos[2];

    for (int i = 0; i < (mi->size[0] - 1); ++i) {
        for (int j = 0; j < (mi->size[1] - 1); ++j) {
            sfRenderWindow_drawConvexShape(win, mi->c_map[i][j], NULL);
            sfConvexShape_destroy(mi->c_map[i][j]);
        }
    }
    return 0;
}
