/*
** EPITECH PROJECT, 2021
** boostrap
** File description:
** .
*/

#include <matchstick.h>

int check_string(char *str)
{
    if (str[0] == '\n')
        return 1;
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 1;
    }
    return 0;
}

int check_errors_matches(char *matches, int line, map_t *map_struct)
{
    if (check_string(matches) == 1) {
        my_printf("Error: invalid input (positive number expected)");
        return 1;
    }
    if (my_getnbr(matches) <= 0) {
        my_printf("Error: you have to remove at least one match");
        return 1;
    }
    if (my_getnbr(matches) > map_struct->stick) {
        my_printf("Error: you cannot remove more than %d matches per turn",
        map_struct->stick);
        return 1;
    }
    else if (my_getnbr(matches) > stick_line(line, map_struct->map)) {
        my_printf("Error: not enough matches on this line");
        return 1;
    }
    return 0;
}

int check_errors_line(char *line, map_t *map_struct)
{
    int x = my_getnbr(line);

    if (check_string(line) == 1) {
        my_printf("Error: invalid input (positive number expected)");
        return 1;
    }
    if (x > len_map(map_struct->map) || x < 1) {
        my_printf("Error: this line is out of range");
        return 1;
    }
    return 0;
}

int check_errors_matches_ia(int n, int line, map_t *map_struct)
{
    if (n > map_struct->stick)
        return 1;
    else if (n > stick_line(line, map_struct->map))
        return 1;
    return 0;
}

int check_errors_line_ia(int x, map_t *map_struct)
{
    if (x > len_map(map_struct->map) || x < 0)
        return 1;
    else if (1 > stick_line(x, map_struct->map))
        return 1;
    return 0;
}