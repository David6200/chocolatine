/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "my.h"

void *add_end_room(room_t **head, room_t *new)
{
    room_t *tmp;

    if (*head == NULL) {
        *head = new;
        return NULL;
    }
    tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return NULL;
}

void *add_end_tunnel(tunnel_t **head, tunnel_t *new)
{
    tunnel_t *tmp;

    if (*head == NULL) {
        *head = new;
        return NULL;
    }
    tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return NULL;
}
