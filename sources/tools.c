/*
** EPITECH PROJECT, 2021
** world
** File description:
** tools.c
*/

#include "../include/my.h"
#include "../include/p.h"

void tool_size(sfRenderWindow *w, struct map_info *mi)
{
    sfCircleShape *circle = sfCircleShape_create();
    float x = sfMouse_getPositionRenderWindow(w).x * 1.0 - mi->tool_size;
    float y = sfMouse_getPositionRenderWindow(w).y * 1.0 - mi->tool_size;
    sfVector2f vec = {x, y};

    sfCircleShape_setRadius(circle, (mi->tool_size * 1.0));
    sfCircleShape_move(circle, vec);
    sfCircleShape_setOutlineColor(circle, get_tool_col(mi));
    sfCircleShape_setOutlineThickness(circle, 3.0);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfRenderWindow_drawCircleShape(w, circle, NULL);
    sfCircleShape_destroy(circle);
}

void t_keys_t(sfRenderWindow *w, struct map_info *m, int i)
{
    int t_size = m->tool_size;

    for (int j = 0; j < m->size[1]; ++j) {
        if (((sfMouse_getPositionRenderWindow(w).x + t_size) >= m->map[i][j].x)
        && (sfMouse_getPositionRenderWindow(w).x <= m->map[i][j].x + t_size)
        && ((sfMouse_getPositionRenderWindow(w).y + t_size) >= m->map[i][j].y)
        && (sfMouse_getPositionRenderWindow(w).y <=
        (m->map[i][j].y + t_size))) {
            m->color_map[i][j] = current_color_info(m);
        }
    }
}

void t_keys_s(sfRenderWindow *w, struct map_info *m, int i, float am)
{
    for (int j = 0; j < m->size[1]; ++j) {
        if (((sfMouse_getPositionRenderWindow(w).x + m->tool_size)
        >= m->map[i][j].x)
        && (sfMouse_getPositionRenderWindow(w).x <= m->map[i][j].x +
        m->tool_size)
        && ((sfMouse_getPositionRenderWindow(w).y + m->tool_size) >=
        m->map[i][j].y) && (sfMouse_getPositionRenderWindow(w).y <=
        (m->map[i][j].y + m->tool_size))) {
            m->h_map[i][j] += am;
        }
    }
}

void t_keys_f(sfRenderWindow *w, struct map_info *m, int i)
{
    int t_size = m->tool_size;

    for (int j = 0; j < m->size[1]; ++j) {
        if (((sfMouse_getPositionRenderWindow(w).x + t_size) >= m->map[i][j].x)
        && (sfMouse_getPositionRenderWindow(w).x <= m->map[i][j].x + t_size)
        && ((sfMouse_getPositionRenderWindow(w).y + t_size) >= m->map[i][j].y)
        && (sfMouse_getPositionRenderWindow(w).y <=
        (m->map[i][j].y + t_size))) {
            m->h_map[i][j] = 0;
        }
    }
}
