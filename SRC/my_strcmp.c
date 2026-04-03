/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

int my_strcmp(char *a, char *b)
{
    int i = 0;

    for (; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] == '\n' && b[i] == '\n')
            break;
        if (a[i] == '\n' || b[i] == '\n')
            return 1;
        if (a[i] != b[i])
            return (a[i] != b[i]);
    }
    if (a[i] == '\0' && b[i] != '\0')
        return 1;
    return 0;
}
