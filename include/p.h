/*
** EPITECH PROJECT, 2021
** p.h
** File description:
** prototypes fct
*/

#ifndef _P_H
    #define _P_H

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <math.h>

    #define _XOPEN_SOURCE 700
    #define X_OFFSET = 500;
    #define Y_OFFSET = 500;

    #define H_TOOL 1
    #define FLAT_TOOL 2
    #define TEX_TOOL 3

    #define CTI(x) (x - '0')
    #define ITC(x) (x + '0')
    #define GREATER(x, y) ((my_strlen(x)) > (my_strlen(y)) ? (x) : (y))
    #define SMALLER(x, y) ((my_strlen(x)) < (my_strlen(y)) ? (x) : (y))
    #define EQUAL_LEN(x, y) ((my_strlen(x)) == (my_strlen(y))) ? (1) : (0)
    #define SYNTAX_ERROR_MSG ("syntax error")
    #define ERROR_MSG ("error")
    #define DEGTRAD(x) (x * 3.1415926535 / 180)

    #define RED 1
    #define GREEN 2
    #define BLUE 3
    #define TRANS 4
    #define MAGENTA 5
    #define CYAN 6
    #define BLACK 7
    #define SIZE_MAX_MAP 50
    #define SIZE_MIN_MAP 2
    #define JUMP_SIZE_MAP 1

struct music {
    sfSound *button;
    sfSoundBuffer *buff_button;
    sfMusic *menu;
};

struct info_button {
    sfText *text;
    sfFont *font;
    sfSprite *info;
    sfTexture *t_info;
    sfVector2f pos_info;
};

struct button_s {
    struct info_button *info;
    sfSprite *sign;
    sfSprite *panel;
    sfTexture *t_sign;
    sfTexture *t_panel;
    sfVector2f pos_sign;
    sfVector2f pos_panel;
    sfVector2f size_panel;
    sfVector2f scale_sign;
    sfVector2f scale_panel;
    sfClock *clock;
    sfTime time;
    int is_pressed;
};

struct button {
    sfText *text;
    sfFont *font;
    sfRectangleShape *rect;
    sfVector2f pos_t;
    sfVector2f pos;
    sfVector2f size;
    sfClock *clock;
    sfTime time;
    int is_pressed;
};

struct size_map {
    int size_int;
    char *size_str;
    struct button *b_up;
    struct button *b_down;
    sfText *text;
    sfText *title;
    sfFont *font;
};

struct frame_rate {
    int frame_rate;
    char *nb_frame_rate;
    struct button *b_up;
    struct button *b_down;
    sfText *text;
    sfText *title;
    sfFont *font;
};

struct music_vol {
    int vol;
    struct button *b_ret;
    struct button *b_up;
    struct button *b_down;
    sfText *title;
    sfFont *font;
    sfRectangleShape **rect;
};

struct b_game {
    struct button_s *color;
    struct button_s *plus;
    struct button_s *minus;
    struct button_s *turn;
    struct button_s *up_down;
    struct button_s *arrow_up;
    struct button_s *arrow_down;
    struct button_s *arrow_right;
    struct button_s *arrow_left;
    struct button_s *zoom;
    struct button_s *dezoom;
    struct button_s *press;
    struct button_s *shovel;
    struct button_s *settings;
    struct button_s *exit;
};

struct menu {
    struct size_map *s_m;
    struct music *music;
    struct music_vol *m_vol;
    struct frame_rate *f_r;
    struct button *b_start;
    struct button *b_vol;
    sfText *title;
    sfFont *font;
    sfSprite *background;
    sfTexture *t_back;
    sfSprite *panel;
    sfTexture *t_panel;
    sfSprite *gate;
    sfTexture *t_gate;
    sfRenderWindow *window;
    sfVector2i mouse;
    int nb_menu;
    int if_gate;
    struct b_game *b_game;
};

typedef struct view_info {
    int distance;
    float angle;
    float anglesin;
    int xoffset;
    int yoffset;
} view_info;

typedef struct map_info {
    float **h_map;
    int *size;
    int tool_size;
    int tool_ind;
    int cur_color;
    int press_bool;
    char *map_name;
    sfVector2f **map;
    sfColor **color_map;
    sfConvexShape ***c_map;
} map_info;

map_info setup_map_info(int size[2], struct view_info *vi);
view_info setup_view_info(void);

// my_world
int my_world(int gate);
sfConvexShape ***map_cs(struct view_info *vi, struct map_info *mi);
int shape_draw_map(struct map_info *mi, sfRenderWindow *win);
sfColor **create_col_map(struct map_info *mi);
sfColor current_color_info(struct map_info *mi);
void change_color_index(struct map_info *mi);
void ev_color_change(sfEvent event, struct map_info *mi, sfRenderWindow *w);
sfColor get_tool_col(struct map_info *mi);
void check_music_fr(struct menu *m, sfEvent event, struct music_vol *v);

// my_event
void my_event(struct menu *m, sfEvent event);

// event_game_button
void if_game_button_pressed(struct menu *m, sfEvent event,
struct map_info *mi, struct view_info *vi);
void fifth_help_game_button_pressed(struct menu *m,
sfEvent event, struct map_info *mi, struct view_info *vi);

//info_button
void destroy_button_s(struct button_s *button);
struct info_button *create_info_button(sfVector2f pos, sfVector2f scale,
char *path_sprite);
void add_text_info(struct button_s *b, char *str, int size, sfVector2f pos);
void destroy_info_button(struct info_button *i);

// create_other_button_game
int create_other_button(struct b_game *b);

// add_text_button_game
void add_text_button_game(struct b_game *b);

// sprite
sfTexture *create_sprite(sfSprite *sprite, sfTexture *texture, sfVector2f pos,
char *path_sprite);
void destroy_sprite(sfSprite *sprite, sfTexture *texture);

// colli
int pos_is_inrect(sfVector2i pos, sfVector2f size_rec, sfVector2f pos_rec);

// button
void draw_button(struct button *b, sfRenderWindow *wind, sfVector2i mouse);
void destroy_button(struct button *button);
struct button *create_button(sfVector2f size, sfVector2f pos, char *s, int co);
void start_press(struct button *b);

// button sprite
int if_button_s_pressed(struct button_s *b, sfRenderWindow *wind,
sfVector2i mouse, sfEvent event);
void draw_button_s(struct button_s *b, sfRenderWindow *wind, sfVector2i mouse);
struct button_s *create_button_s(char *path_sprite, sfVector2f pos,
sfVector2f scale_sign, sfVector2f scale_panel);

// game button
struct b_game *create_button_game(void);
void destroy_button_game(struct b_game *b);
void draw_button_game(struct menu *m, struct b_game *b);

// create_text_rect_vect
sfText *create_text(sfFont *font, sfVector2f pos, char *str, int size);
sfVector2f vect(float x, float y);
sfRectangleShape *create_rect(sfVector2f size, sfVector2f pos, int color);
void set_sprite(sfSprite *sprite, sfTexture *texture, sfVector2f pos,
sfVector2f scale);
sfIntRect *create_int_rect(sfIntRect *rect, int x, int y);

// menu
void destroy_menu(struct menu *menu);
sfRenderWindow *create_window(sfRenderWindow *window, int framerate);
struct menu *create_menu(struct menu *m, int gate);

// sound_volume
struct music_vol *create_music_volume(void);
void destroy_music_vol(struct music_vol *m);
void draw_music_volume(struct menu *m, struct music_vol *m_vol);
void refresh_vol(struct music_vol *mv, int up, struct music *music);

// frame_rate
struct frame_rate *create_frame_rate(void);
void destroy_frame_rate(struct frame_rate *f_r);
void refresh_frame_rate(int up, struct menu *m, struct music *music);
void draw_frame_rate(struct menu *m, struct frame_rate *fr);
void check_fr(struct menu *m, sfEvent event, struct music_vol *v);

// size_map
void event_size_map(struct menu *m, sfEvent event, struct music_vol *v);
void draw_size_map(struct menu *m, struct size_map *sm);
void destroy_size_map(struct size_map *sm);
void refresh_size_map(int up, struct menu *m, struct music *music);
struct size_map *create_size_map(void);

// create_destroy_music
struct music *create_music(struct music *m);
void destroy_music(struct music *music);

// WINDOW FUNCS
void create_windows(int *arr, char *name, int diff);
void create_game(sfRenderWindow *window, struct menu *menu);
void window_funcs(sfRenderWindow *win, struct map_info *mi, struct menu *m);

// ANIMATIONS FUNCS
void move_rect(sfIntRect *rect, int offset, int max_value);

// -- clock related --
void clock_action(sfSprite *sp1, sfIntRect *rect);
void move_timer(sfClock *cl_two, sfRenderWindow *w, sfEvent ev);
void timer_actions(sfClock *cl, sfRenderWindow *w);

// TERRAIN FUNCS
float **create_map(int *size);
float **create_hmap(int x, int y);

// ISOMETRIC
sfVector2f iso_coord(int pos[3], struct view_info *vi);
sfVector2f **iso_map(float **h_map, int size[2], struct view_info *vi);
sfVertexArray *create_line(sfVector2f *po, sfVector2f *pt);
int iso_draw_map_s(struct map_info *mi, sfRenderWindow *w, int pos[2]);
int iso_draw_map(sfRenderWindow *win, struct map_info *mi);

// -- iso metric render --
int render_line_i(sfVector2f **map, int i, int j, sfRenderWindow *win);
int render_line_j(sfVector2f **map, int i, int j, sfRenderWindow *win);

// TOOLS
void tool_size(sfRenderWindow *w, struct map_info *mi);
void check_bool_key(sfRenderWindow *w, struct map_info *mi);
void t_keys_f(sfRenderWindow *w, struct map_info *mi, int i);
void t_keys_s(sfRenderWindow *w, struct map_info *mi, int i, float am);
void t_keys_t(sfRenderWindow *w, struct map_info *m, int i);

// SOUND FUNCS
sfSound *play_sound(char const *path, sfBool isloop, float volume);
void play_music(char const *path);

// EVENTS FUNCS
void analyse_events(struct menu *m, sfEvent ev, struct view_info *vi,
struct map_info *mi);

#endif
