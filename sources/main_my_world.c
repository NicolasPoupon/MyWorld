/*
** EPITECH PROJECT, 2021
** main_my_world.c
** File description:
** main for my_world
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"
#include "../include/p.h"

static void print_usage_h(void)
{
    my_putstr("USAGE\n    ./my_world [-gate]\n\nDESCRIPTION\n\n");
    my_putstr("    -gate    add a gate one the map\n\n");
    my_putstr("Edit your world with tools, let the mouse");
    my_putstr("over the buttons to see their uses\n");
    my_putstr("and keyboard shortcuts.\n\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage_h();
        return (0);
    }
    if (ac == 1) {
        if (my_world(0) == 84)
            return 84;
        return (0);
    }
    if (ac == 2 && compare_str(av[1], "-gate") == 0) {
        if (my_world(1) == 84)
            return 84;
        return (0);
    }
    my_putstr("Wrong number of arguments, try './my_world' ");
    my_putstr("to start the game or './my_world -h' to see the rules.\n");
    return (0);
}
