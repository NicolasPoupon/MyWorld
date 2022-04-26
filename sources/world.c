/*
** EPITECH PROJECT, 2021
** world
** File description:
** my_world.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <math.h>
#include <stdlib.h>

void window_funcs(sfRenderWindow *win, struct map_info *mi, struct menu *m)
{
    sfRenderWindow_clear(win, sfColor_fromRGB(70, 140, 200));
    shape_draw_map(mi, win);
    iso_draw_map(win, mi);
    tool_size(win, mi);
    if (m->nb_menu == 1)
    draw_button_game(m, m->b_game);
    if (m->nb_menu == 2) {
        sfRenderWindow_drawSprite(m->window, m->panel, NULL);
        draw_music_volume(m, m->m_vol);
        draw_frame_rate(m, m->f_r);
    }
}

sfVertexArray *create_line(sfVector2f *po, sfVector2f *pt)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *po, .color = sfWhite};
    sfVertex vertex2 = {.position = *pt, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

float **create_hmap(int x, int y)
{
    int size[2] = {x, y};
    float **h_map = malloc(size[0] * sizeof(float*));

    for (int i = 0; i < size[0]; ++i)
        h_map[i] = malloc(size[1] * sizeof(float));
    for (int i = 0; i < size[0]; ++i) {
        for (int j = 0; j < size[1]; ++j)
            h_map[i][j] = 0.0;
    }
    return h_map;
}

void create_game(sfRenderWindow *window, struct menu *menu)
{
    int size[2] = {menu->s_m->size_int, menu->s_m->size_int};
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfClock *cl_two = sfClock_create();
    struct view_info vi = setup_view_info();
    struct map_info mi = setup_map_info(size, &vi);

    while (sfRenderWindow_isOpen(window)) {
        menu->mouse = sfMouse_getPositionRenderWindow(menu->window);
        mi.map = iso_map(mi.h_map, size, &vi);
        mi.c_map = map_cs(&vi, &mi);
        move_timer(cl_two, window, event);
        analyse_events(menu, event, &vi, &mi);
        window_funcs(window, &mi, menu);
        timer_actions(clock, window);
    }
}
