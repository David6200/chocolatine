/*
** EPITECH PROJECT, 2025
** room
** File description:
** count_room
*/

#include "my.h"

int count_rooms(room_t *rooms)
{
    int count = 0;
    room_t *tmp = rooms;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
