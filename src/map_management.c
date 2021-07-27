/*
** EPITECH PROJECT, 2021
** map_managment
** File description:
** .
*/

#include <matchstick.h>

int check_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}

void remove_stick(int x, int n, map_t *map_struct)
{
    int k = map_struct->biggest_line;

    for (int i = 0; i != n; i++) {
        while (map_struct->map[x][k] && map_struct->map[x][k] != '|') {
            k--;
        }
        if (map_struct->map[x][k] == '|') {
            map_struct->map[x][k] = ' ';
            k--;
        }
    }
}

int len_map(char **map)
{
    int i = 0;
    for (; map[i]; i++);

    return (i - 2);
}

int stick_line(int x, char **map)
{
    int n = 0;
    for (int i = 0; map[x][i] != '\0'; i++) {
        if (map[x][i] == '|')
            n++;
    }
    return n;
}

int check_error(map_t *map_struct, int x, int n)
{
    int s = map_struct->stick;
    if (n > s) {
        my_printf("Error: you cannot remove more than %d matches per turn", s);
        return 1;
    }
    else if (x > len_map(map_struct->map)) {
        my_printf("Error: this line is out of range");
        return 1;
    }
    else if (n > stick_line(x, map_struct->map)) {
        my_printf("Error: not enough matches on this line");
        return 1;
    }
    return 0;
}