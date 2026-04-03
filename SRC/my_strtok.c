/*
** EPITECH PROJECT, 2025
** strtok
** File description:
** strtok
*/

#include "my.h"

static int is_delim(char c, char *delims)
{
    int i = 0;

    while (delims[i] != '\0') {
        if (c == delims[i])
            return 1;
        i++;
    }
    return 0;
}

char *my_strtok(char *str, char *delims)
{
    char *save = NULL;
    char *start;

    if (str != NULL)
        save = str;
    if (save == NULL)
        return NULL;
    while (*save != '\0' && is_delim(*save, delims))
        save++;
    if (*save == '\0')
        return NULL;
    start = save;
    while (*save != '\0' && !is_delim(*save, delims))
        save++;
    if (is_delim(*save, delims)) {
        *save = '\0';
        save++;
    }
    return start;
}
