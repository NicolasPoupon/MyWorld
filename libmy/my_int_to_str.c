/*
** EPITECH PROJECT, 2021
** int_to_str.c
** File description:
** return str of int
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_int_to_str(int nb)
{
    int len_nb = count_len_int(nb);
    char *str;
    int i = 0;
    int m10 = 1;

    if (nb == 0)
        return my_strdup("0");
    str = malloc(sizeof(char) * (len_nb + 1));
    if (str == NULL)
        return NULL;
    for (int j = 0; j != len_nb - 1; j++)
        m10 *= 10;
    while (i != len_nb) {
        str[i] = (nb / m10) + '0';
        nb = nb % m10;
        m10 = m10 / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_int_to_str_for_float(int nb, char *str)
{
    int len_nb = count_len_int(nb);
    int i = 0;
    int m10 = 1;

    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    for (int j = 0; j != len_nb - 1; j++)
        m10 *= 10;
    while (i != len_nb) {
        str[i] = (nb / m10) + '0';
        nb = nb % m10;
        m10 = m10 / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *fill_after_point(char *str, int len, float nb, int num)
{
    int i = 0;

    for (; i != 6; i++) {
        num = nb *10;
        str[len + i + 1] = num + '0';
        nb *= 10;
        nb -= num;
        num = 0;
    }
    str[len + i + 1] = '\0';
    return str;
}

char *float_to_str(float nb)
{
    char *str;
    int num = nb;
    int len_int = count_len_int(num);
    int len_nb = len_int + 6;
    int len = 0;

    str = malloc(sizeof(char) * (len_nb + 2));
    if (str == NULL)
        return NULL;
    str = my_int_to_str_for_float(num, str);
    len = my_strlen(str);
    str[len] = '.';
    str[len + 1] = '\0';
    nb -= num;
    str = fill_after_point(str, len, nb, num);
    my_putstr(str);
    return (str);
}
