/*
** EPITECH PROJECT, 2021
** world
** File description:
** iso_points.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <math.h>

sfVector2f iso_coord(int pos[3], struct view_info *vi)
{
    sfVector2f point;
    int i = pos[0];
    int j = pos[1];
    int h_map = pos[2];

    point.x = cos(vi->angle) * (i) - sin(vi->angle) * (j);
    point.y = sin(vi->anglesin) * (j) + sin(vi->anglesin) * (i) - (h_map);
    point.x += ((1920 / 2)) + vi->xoffset;
    point.y += ((1080 / 2) - 300) + vi->yoffset;
    return point;
}

sfVector2f **iso_map(float **h_map, int size[2], struct view_info *vi)
{
    int pos[3];
    sfVector2f **map = malloc(size[0] * sizeof(sfVector2f*));

    for (int i = 0; i < size[0]; ++i)
        map[i] = malloc(sizeof(sfVector2f) * size[1]);
    for (int i = 0; i < size[0]; ++i) {
        for (int j = 0; j < size[1]; ++j) {
            pos[0] = i * vi->distance;
            pos[1] = j * vi->distance;
            pos[2] = h_map[i][j] * vi->distance;
            map[i][j] = iso_coord(pos, vi);
        }
    }
    return map;
}

int render_line_i(sfVector2f **map, int i, int j, sfRenderWindow *win)
{
    sfVertexArray *vert_arr;

    if (map[i][j].x < 0.0 || map[i][j].x > 1920.0)
        return 0;
    if (map[i][j].y < 0.0 || map[i][j].y > 1080.0)
        return 0;
    vert_arr = sfVertexArray_create();
    vert_arr = create_line(&(map[i][j]), &(map[i + 1][j]));
    sfRenderWindow_drawVertexArray(win, vert_arr, NULL);
    sfVertexArray_destroy(vert_arr);
    return 0;
}

int render_line_j(sfVector2f **map, int i, int j, sfRenderWindow *win)
{
    sfVertexArray *vert_arr;

    if (map[i][j].x < 0.0 || map[i][j].x > 1920.0)
        return 0;
    if (map[i][j].y < 0.0 || map[i][j].y > 1080.0)
        return 0;
    vert_arr = sfVertexArray_create();
    vert_arr = create_line(&(map[i][j]), &(map[i][j + 1]));
    sfRenderWindow_drawVertexArray(win, vert_arr, NULL);
    sfVertexArray_destroy(vert_arr);
    return 0;
}
