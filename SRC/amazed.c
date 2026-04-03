/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "my.h"

void parse_input_for_tunnel(tunnel_t **tunnel, char *line, int nb_lign)
{
    tunnel_t *new = NULL;
    char *r1 = NULL;
    char *r2 = NULL;

    if (my_strstr(line, '-')) {
        r1 = my_strtok(line, "-\n");
        r2 = my_strtok(NULL, "-\n");
        if (r1 && r2) {
            new = malloc(sizeof(tunnel_t));
            new->room1 = my_strdup(r1);
            new->room2 = my_strdup(r2);
            new->nb_lign = nb_lign;
            new->next = NULL;
            add_end_tunnel(tunnel, new);
        }
    }
}

static int fill_room(room_t **room, parse_t *a, int *flag)
{
    a->new = malloc(sizeof(room_t));
    a->new->name = my_strdup(a->name);
    a->new->x = my_getnbr(a->x);
    a->new->y = my_getnbr(a->y);
    if (a->new->x == -1 || a->new->y == -1) {
        free(a->new->name);
        free(a->new);
        return 84;
    }
    a->new->start = flag[0];
    a->new->end = flag[1];
    a->new->next = NULL;
    add_end_room(room, a->new);
    flag[0] = 0;
    flag[1] = 0;
    return 0;
}

int parse_input_for_room(room_t **room, char *line, int *flag)
{
    parse_t a = {NULL, NULL, NULL, NULL};

    if (my_strstr(line, '-') != NULL)
        return 0;
    a.name = my_strtok(line, "- \n");
    a.x = my_strtok(NULL, "- \n");
    a.y = my_strtok(NULL, "- \n");
    if (a.name && a.x && a.y)
        return fill_room(room, &a, flag);
    return 0;
}

int process_line(output_t *a)
{
    if (my_strcmp(a->line, "##start") == 0) {
        a->flag[0] = 1;
        a->nb_lign++;
        return 1;
    }
    if (my_strcmp(a->line, "##end") == 0) {
        a->flag[1] = 1;
        a->nb_lign++;
        return 1;
    }
    if (a->line[0] == '#') {
        a->nb_lign++;
        return 1;
    }
    return 0;
}

int parse_line(output_t *a)
{
    if (my_strstr(a->line, '-'))
        parse_input_for_tunnel(&a->tunnel, a->line, a->nb_lign);
    else if (parse_input_for_room(&a->room, a->line, a->flag) == 84)
        return 84;
    a->nb_lign++;
    return 0;
}

static int output_maze(amaze_t *maze)
{
    output_t a = {NULL, 0, {0, 0}, NULL, NULL, 2};

    while (getline(&a.line, &a.len, stdin) != -1) {
        if (process_line(&a))
            continue;
        if (parse_line(&a) == 84) {
            free(a.line);
            return 84;
        }
    }
    if (check_start_end(a.room, a.flag) == 84) {
        free(a.line);
        return 84;
    }
    print_rooms(a.room);
    if (index_line(a.room, a.tunnel) == 84)
        return 84;
    maze->room = a.room;
    maze->tunnel = a.tunnel;
    return 0;
}

int main(int ac, char **av)
{
    principale_t a = {NULL, NULL, 0, NULL, 0, NULL};

    if (ac != 1)
        return 84;
    getline(&a.line, &a.len, stdin);
    a.robots = my_getnbr(a.line);
    if (a.robots == -1 || a.robots == 0) {
        mini_printf("amazed, line 1: The number of ");
        mini_printf("robots you entered is invalid.\n");
        return 84;
    }
    mini_printf("#number_of_robots\n%d\n#rooms\n", a.robots);
    if (output_maze(&a.maze) == 84)
        return 84;
    a.from = main_boucle_bfs(a.maze.room, a.maze.tunnel);
    path_reconstruction(a.maze.room, a.from, check_room_end(a.maze.room));
}
