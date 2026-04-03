/*
** EPITECH PROJECT, 2025
** display
** File description:
** display
*/

#include "my.h"

void print_rooms(room_t *room)
{
    room_t *tmp = room;

    while (tmp != NULL) {
        if (tmp->start)
            mini_printf("##start\n");
        if (tmp->end)
            mini_printf("##end\n");
        mini_printf("%s %d %d\n", tmp->name, tmp->x, tmp->y);
        tmp = tmp->next;
    }
}

void print_tunnels(tunnel_t *tunnel)
{
    tunnel_t *tmp = tunnel;

    mini_printf("#tunnels\n");
    while (tmp != NULL) {
        mini_printf("%s-%s\n", tmp->room1, tmp->room2);
        tmp = tmp->next;
    }
}
