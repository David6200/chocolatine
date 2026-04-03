/*
** EPITECH PROJECT, 2025
** strstr
** File description:
** strstr
*/

#include "my.h"

void *my_strstr(char *line, char c)
{
    int i = 0;

    while (line[i] != '\0'){
        if (line[i] == c)
            return (line + i);
        i++;
    }
    return NULL;
}
