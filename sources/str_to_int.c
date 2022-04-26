/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-pushswap-guillaume.clement-bonniel-veyron
** File description:
** str_to_int.c
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>

int str_to_int(char *str)
{
    int r = 0;
    int i = 0;
    int m = 1;
    int size = my_strlen(str);

    if (str[0] == '-') {
        r *= -1;
        i = 1;
        m = -1;
    }
    for (i = i; i < size; i ++)
        if (str[i] >= '0' && str[i] <= '9')
            r = (r * 10) + CTI(str[i]);
    return r * m;
}

char *int_to_str(int nb)
{
    char *str;
    int cpnb = nb;
    int len_nb = 1;

    for (int i = 0; cpnb > 9; i++) {
        cpnb = cpnb / 10;
        len_nb ++;
    }
    str = malloc(len_nb + 1);
    for (int i = 0; i < len_nb; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    str[len_nb] = '\0';
    return (my_revstr(str));
}
