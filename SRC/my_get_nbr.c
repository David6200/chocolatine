/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Shell Boostrap
** File description:
** my_get_nbr
*/

#include "my.h"

int my_getnbr(char *av)
{
    int i = 0;
    int nb = 0;

    for (i = 0; av[i] != '\0'; i++){
        if (av[i] == '\n')
            break;
        if (av[i] < '0' || av[i] > '9')
            return -1;
        if (av[i] >= '0' && av[i] <= '9')
            nb = (nb * 10) + av[i] - '0';
    }
    return nb;
}
