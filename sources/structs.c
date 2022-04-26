/*
** EPITECH PROJECT, 2021
** world
** File description:
** structs.c
*/

#include "../include/my.h"
#include "../include/p.h"

view_info setup_view_info(void)
{
    struct view_info vi;

    vi.angle = DEGTRAD(45);
    vi.anglesin = DEGTRAD(35);
    vi.distance = 50;
    vi.xoffset = 0;
    vi.yoffset = 0;
    return vi;
}

map_info setup_map_info(int size[2], struct view_info *vi)
{
    struct map_info mi;

    mi.size = size;
    mi.tool_size = 30;
    mi.tool_ind = 1;
    mi.cur_color = 1;
    mi.press_bool = 0;
    mi.h_map = create_hmap(mi.size[0], mi.size[1]);
    mi.map = iso_map(mi.h_map, mi.size, vi);
    mi.color_map = create_col_map(&mi);
    mi.c_map = map_cs(vi, &mi);
    return mi;
}
