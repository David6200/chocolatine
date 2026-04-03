/*
** EPITECH PROJECT, 2025
** algo
** File description:
** bfs
*/

#include "my.h"

int check_index(room_t *rooms, char *name)
{
    int i = 0;
    room_t *tmp = rooms;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            return i;
        i++;
        tmp = tmp->next;
    }
    return -1;
}

char *check_room_start(room_t *room)
{
    room_t *tmp = room;

    while (tmp != NULL) {
        if (tmp->start == 1)
            return tmp->name;
        tmp = tmp->next;
    }
    return NULL;
}

char *check_room_end(room_t *room)
{
    room_t *tmp = room;

    while (tmp != NULL) {
        if (tmp->end == 1)
            return tmp->name;
        tmp = tmp->next;
    }
    return NULL;
}

static void process_voisin(boucle_bfs_t *a, room_t *room, int *if_vis)
{
    a->index = check_index(room, a->voisin);
    if (a->index == -1 || if_vis[a->index] != 0)
        return;
    if (my_strcmp(a->voisin, a->name) == 0)
        return;
    if_vis[a->index] = 1;
    a->from[a->index] = a->name;
    add_end(&a->file, a->voisin);
}

static void process_tunnels(boucle_bfs_t *a, room_t *room, int *if_vis)
{
    a->tmp = a->tunnel;
    while (a->tmp != NULL) {
        a->voisin = NULL;
        if (my_strcmp(a->tmp->room1, a->name) == 0)
            a->voisin = a->tmp->room2;
        if (my_strcmp(a->tmp->room2, a->name) == 0)
            a->voisin = a->tmp->room1;
        if (a->voisin != NULL)
            process_voisin(a, room, if_vis);
        a->tmp = a->tmp->next;
    }
}

char **main_boucle_bfs(room_t *room, tunnel_t *tunnel)
{
    boucle_bfs_t a = {check_room_start(room), check_room_end(room),
        count_rooms(room), NULL, NULL, NULL, NULL, 0, NULL, tunnel};
    int if_vis[a.count];

    a.from = malloc(sizeof(char *) * a.count);
    for (int i = 0; i < a.count; i++) {
        if_vis[i] = 0;
        a.from[i] = NULL;
    }
    if (a.start == NULL || a.end == NULL)
        return a.from;
    add_end(&a.file, a.start);
    if_vis[check_index(room, a.start)] = 1;
    while (a.file != NULL) {
        a.name = del_first(&a.file);
        if (my_strcmp(a.name, a.end) == 0)
            break;
        process_tunnels(&a, room, if_vis);
    }
    return a.from;
}

static void reverse_list(recons_t *a)
{
    a->tmp = a->chemin_inverse;
    a->prev = NULL;
    a->next = NULL;
    while (a->tmp != NULL) {
        a->next = a->tmp->next;
        a->tmp->next = a->prev;
        a->prev = a->tmp;
        a->tmp = a->next;
    }
    a->chemin_final = a->prev;
}

void path_reconstruction(room_t *room, char **from, char *end)
{
    recons_t a = {NULL, NULL, NULL, NULL, NULL, NULL, 0};

    a.name = end;
    while (a.name != NULL) {
        add_end(&a.chemin_inverse, a.name);
        a.index = check_index(room, a.name);
        if (a.index == -1)
            break;
        a.name = from[a.index];
    }
    reverse_list(&a);
    a.affiche = a.chemin_final;
    mini_printf("#moves\n");
    while (a.affiche != NULL) {
        mini_printf("%s\n", a.affiche->room_name);
        a.affiche = a.affiche->next;
    }
}
