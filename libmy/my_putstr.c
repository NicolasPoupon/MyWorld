/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** put str
*/

#include "../include/my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void put_error(char const *str)
{
    write(2, str, my_strlen(str));
}

void my_putstr_e(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            my_putchar('$');
        else if (str[i] == ' ')
            my_putchar('*');
        else
            my_putchar(str[i]);
    }
    my_putchar('\n');
}

int print_array_char_e(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        my_putstr_e(array[i]);
    return (0);
}
