/*
** EPITECH PROJECT, 2021
** input
** File description:
** .
*/

#include <matchstick.h>

int choose_matches(map_t *map_struct, int *line)
{
    char *matches = NULL;
    size_t len = 0;

    my_printf("Matches: ");
    if (getline(&matches, &len, stdin) == -1)
        return -1;
    while (check_errors_matches(matches, (*line), map_struct) == 1) {
        (*line) = choose_lines(map_struct);
        if ((*line) == -1)
            return -1;
        my_printf("Matches: ");
        if (getline(&matches, &len, stdin) == -1)
            return -1;
    }
    return my_getnbr(matches);
}

int choose_lines(map_t *map_struct)
{
    char *line = NULL;
    size_t len = 0;

    my_printf("\nLine: ");
    if (getline(&line, &len, stdin) == -1)
        return -1;
    while (check_errors_line(line, map_struct) == 1) {
        my_printf("\nLine: ");
        if (getline(&line, &len, stdin) == -1)
            return -1;
    }
    return my_getnbr(line);
}