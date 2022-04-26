/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu management
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void destroy_menu(struct menu *menu)
{
    destroy_button_game(menu->b_game);
    destroy_size_map(menu->s_m);
    destroy_frame_rate(menu->f_r);
    destroy_button(menu->b_start);
    destroy_button(menu->b_vol);
    sfFont_destroy(menu->font);
    sfText_destroy(menu->title);
    sfSprite_destroy(menu->background);
    sfTexture_destroy(menu->t_back);
    sfSprite_destroy(menu->panel);
    sfTexture_destroy(menu->t_panel);
    if (menu->if_gate == 1) {
        sfSprite_destroy(menu->gate);
        sfTexture_destroy(menu->t_gate);
    }
    sfRenderWindow_destroy(menu->window);
    destroy_music(menu->music);
    free(menu);
}

sfRenderWindow *create_window(sfRenderWindow *window, int framerate)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfUint32 flag = sfDefaultStyle | sfResize;

    window = sfRenderWindow_create(video_mode, "Window", flag, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

void if_gate(int gate, struct menu *m)
{
    if (gate == 1) {
        m->if_gate = 1;
        m->gate = sfSprite_create();
        m->t_gate = sfTexture_createFromFile("sprite/gate.png", NULL);
        sfSprite_setTexture(m->gate, m->t_gate, sfFalse);
        sfSprite_setPosition(m->gate, vect(0, 0));
    } else
        m->if_gate = 0;
}

void help_create_menu(struct menu *m, int gate)
{
    m->font = sfFont_createFromFile("sprite/police.TTF");
    m->title = create_text(m->font, vect(450, 150), "My_world", 200);
    m->background = sfSprite_create();
    m->t_back = sfTexture_createFromFile("sprite/forest.png", NULL);
    sfSprite_setTexture(m->background, m->t_back, sfFalse);
    sfSprite_setPosition(m->background, vect(0, 0));
    m->window = create_window(m->window, 60);
    m->nb_menu = 1;
    m->panel = sfSprite_create();
    m->t_panel = sfTexture_createFromFile("sprite/big_pannel.png", NULL);
    sfSprite_setTexture(m->panel, m->t_panel, sfFalse);
    sfSprite_setPosition(m->panel, vect(120, 100));
    sfSprite_setScale(m->panel, vect(0.88, 0.8));
    if_gate(gate, m);
}

struct menu *create_menu(struct menu *m, int gate)
{
    m = malloc(sizeof(struct menu) * 2);
    if (m == NULL)
        return NULL;
    m->music = create_music(m->music);
    m->b_start = create_button(vect(270, 90), vect(825, 650), "Start", TRANS);
    m->b_vol = create_button(vect(420, 105), vect(750, 770), "Settings",
    TRANS);
    m->m_vol = create_music_volume();
    m->f_r = create_frame_rate();
    m->s_m = create_size_map();
    m->b_game = create_button_game();
    if (m->b_start == NULL || m->b_vol == NULL || m->m_vol == NULL ||
        m->music == NULL || m->f_r == NULL || m->b_game == NULL)
        return NULL;
    help_create_menu(m, gate);
    return m;
}
