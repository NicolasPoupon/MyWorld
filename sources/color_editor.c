/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myworld-guillaume.clement-bonniel-veyron
** File description:
** color_editor.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>

sfColor **create_col_map(struct map_info *mi)
{
    sfColor **color_map = malloc((mi->size[0] - 1) * sizeof(sfColor*));

    for (int i = 0; i < (mi->size[0] - 1); ++i)
        color_map[i] = malloc((mi->size[1] - 1) * sizeof(sfColor));
    for (int i = 0; i < (mi->size[0] - 1); ++i) {
        for (int j = 0; j < (mi->size[1] - 1); ++j) {
            color_map[i][j] = sfColor_fromRGB(102, 58, 19);
        }
    }
    return color_map;
}

sfColor current_color_info(struct map_info *mi)
{
    if (mi->cur_color == 1)
        return sfYellow;
    if (mi->cur_color == 2)
        return sfBlue;
    if (mi->cur_color == 3)
        return sfGreen;
    if (mi->cur_color == 4)
        return sfRed;
    if (mi->cur_color == 5)
        return sfColor_fromRGB(102, 58, 19);
}

sfColor get_tool_col(struct map_info *mi)
{
    if (mi->tool_ind == H_TOOL)
        return sfWhite;
    if (mi->tool_ind == FLAT_TOOL)
        return sfBlack;
    if (mi->tool_ind == TEX_TOOL)
        return sfBlue;
    return sfColor_fromRGB(250, 52, 247);
}

void change_color_index(struct map_info *mi)
{
    if (mi->cur_color == 5)
        mi->cur_color = 1;
    else
        ++mi->cur_color;
}
