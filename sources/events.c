/*
** EPITECH PROJECT, 2021
** world
** File description:
** events.c
*/

#include "../include/my.h"
#include "../include/p.h"

static void move_keys(sfEvent event, struct view_info *vi)
{
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyDown))
        vi->yoffset -= (2 * vi->distance) + 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyUp))
        vi->yoffset += (2 * vi->distance) + 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyRight))
        vi->xoffset -= (2 * vi->distance) + 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyLeft))
        vi->xoffset += (2 * vi->distance) + 1;
}

static void move_angle(sfEvent event, struct view_info *vi)
{
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyZ))
        vi->anglesin -= DEGTRAD(2);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyS))
        vi->anglesin += DEGTRAD(2);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyQ))
        vi->angle += DEGTRAD(2);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyD))
        vi->angle -= DEGTRAD(2);
    if (event.type == sfEvtMouseWheelScrolled && event.mouseWheel.x > 0)
        vi->distance += 5;
    if (event.type == sfEvtMouseWheelScrolled && event.mouseWheel.x < 0) {
        if (vi->distance - 5 > 0)
            vi->distance -= 5;
    }
}

static void change_tool(sfEvent event, struct map_info *mi)
{
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyT))
        mi->tool_size += 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyG))
        mi->tool_size -= 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyY))
        if (mi->tool_ind < 3)
            mi->tool_ind += 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyH))
        if (mi->tool_ind > 1)
            mi->tool_ind -= 1;
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseRight && mi->tool_ind == TEX_TOOL)
        change_color_index(mi);
}

static void t_keys(sfEvent event, struct map_info *mi, sfRenderWindow *w)
{
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft && mi->tool_ind == H_TOOL)
        mi->press_bool = 1;
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseRight && mi->tool_ind == H_TOOL)
        mi->press_bool = 2;
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft && mi->tool_ind == FLAT_TOOL)
        mi->press_bool = 3;
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft && mi->tool_ind == TEX_TOOL)
        mi->press_bool = 4;
    if (event.type == sfEvtMouseButtonReleased)
        mi->press_bool = 0;
}

void analyse_events(struct menu *m, sfEvent ev, struct view_info *vi,
struct map_info *mi)
{
    while (sfRenderWindow_pollEvent(m->window, &ev)) {
        if (ev.type == sfEvtClosed)
            sfRenderWindow_close(m->window);
        if (ev.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_close(m->window);
        if (m->nb_menu == 1) {
            t_keys(ev, mi, m->window);
            change_tool(ev, mi);
            move_angle(ev, vi);
            move_keys(ev, vi);
            check_bool_key(m->window, mi);
            if_game_button_pressed(m, ev, mi, vi);
        }
        my_event(m, ev);
    }
}
