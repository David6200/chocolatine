/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Shell Boostrap
** File description:
** bootstrap.h
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct rooms_s {
    char *name;
    int x;
    int y;
    int start;
    int end;
    struct rooms_s *next;
}room_t;

typedef struct tunnel_s {
    char *room1;
    char *room2;
    int nb_lign;
    struct tunnel_s *next;
}tunnel_t;

typedef struct amaze_s {
    int nbr_robot;
    room_t *room;
    tunnel_t *tunnel;
}amaze_t;

typedef struct parse_room {
    char *name;
    char *x;
    char *y;
    room_t *new;
}parse_t;

typedef struct output {
    char *line;
    size_t len;
    int flag[2];
    room_t *room;
    tunnel_t *tunnel;
    int nb_lign;
}output_t;

typedef struct start {
    room_t *tmp;
    int has_start;
    int has_end;
}start_t;

typedef struct path {
    char *room_name;
    struct path *next;
}path_t;

typedef struct principale {
    tunnel_t *tunnel;
    room_t *room;
    size_t len;
    char *line;
    int robots;
    char **from;
    amaze_t maze;
}principale_t;

typedef struct boucle_bfs {
    char *start;
    char *end;
    int count;
    char **from;
    char *name;
    tunnel_t *tmp;
    char *voisin;
    int index;
    path_t *file;
    tunnel_t *tunnel;
}boucle_bfs_t;

typedef struct recons_s {
    path_t *chemin_inverse;
    path_t *chemin_final;
    path_t *tmp;
    path_t *prev;
    path_t *next;
    path_t *affiche;
    int index;
    char *name;
}recons_t;

char *my_strdup(char *src);
char **main_boucle_bfs(room_t *room, tunnel_t *tunnel);
void *add_end_room(room_t **head, room_t *new);
void *add_end_tunnel(tunnel_t **head, tunnel_t *new);
int my_getnbr(char *av);
int my_strlen(char const *str);
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strdup(char *src);
int my_strlen(char const *str);
int my_strcmp(char *a, char *b);
void *my_strstr(char *line, char c);
void print_rooms(room_t *room);
void print_tunnels(tunnel_t *tunnel);
char *my_strtok(char *str, char *delim);
int room_exists(room_t *room, char *name);
int index_line(room_t *room, tunnel_t *tunnel);
int check_start_end(room_t *room, int flag[]);
void path_reconstruction(room_t *room, char **from, char *end);
void add_end(path_t **head, char *room_name);
void *del_first(path_t **head);
char *check_room_end(room_t *room);
int count_rooms(room_t *rooms);
#endif
