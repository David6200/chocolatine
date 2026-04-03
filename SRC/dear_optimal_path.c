/*
** EPITECH PROJECT, 2025
** path
** File description:
** optimal_path
*/

#include "my.h"

void add_end(path_t **head, char *room_name)
{
    path_t *tmp = NULL;
    path_t *new = malloc(sizeof(path_t));

    new->room_name = my_strdup(room_name);
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
        return;
    }
    tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

void *del_first(path_t **head)
{
    path_t *tmp = NULL;
    char *name = NULL;

    if (*head == NULL)
        return NULL;
    tmp = *head;
    name = tmp->room_name;
    *head = tmp->next;
    free(tmp);
    return name;
}
