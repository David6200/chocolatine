/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "my.h"

int room_exists(room_t *room, char *name)
{
    room_t *tmp = room;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int index_line(room_t *room, tunnel_t *tunnel)
{
    tunnel_t *tmp = tunnel;
    char *s = "A room in the tube doesn't exist.";

    while (tmp != NULL) {
        if (!room_exists(room, tmp->room1) || !room_exists(room, tmp->room2)) {
            mini_printf("amazed, line %d: %s\n", tmp->nb_lign, s);
            mini_printf("There is no valid path from start to exit.");
            return 84;
        }
        mini_printf("%s-%s\n", tmp->room1, tmp->room2);
        tmp = tmp->next;
    }
    return 0;
}

int my_return(int i, char *str)
{
    mini_printf("%s", str);
    return i;
}

int check_start_end(room_t *room, int flag[])
{
    start_t a = {room, 0, 0};

    if (room == NULL)
        return my_return(84, "amazed: You didn't define any rooms.\n");
    while (a.tmp != NULL) {
        if (a.tmp->start == 1)
            a.has_start = 1;
        if (a.tmp->end == 1)
            a.has_end = 1;
        a.tmp = a.tmp->next;
    }
    if (a.has_start == 0)
        return my_return(84, "amazed: You didn't define any start room.\n");
    if (a.has_end == 0) {
        mini_printf("amazed: You didn't define any end room.\n");
        return 84;
    }
    return 0;
}
