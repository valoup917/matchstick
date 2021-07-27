/*
** EPITECH PROJECT, 2021
** boostrap
** File description:
** .
*/

#include <matchstick.h>
#include <math.h>

static int check_line_with_stick(map_t *map_struct)
{
    int count = 0;
    int j = 0;

    for (int i = 0; map_struct->map[i];) {
        if (!map_struct->map[i][j]) {
            i++;
            j = 0;
        }
        else if (map_struct->map[i][j] == '|') {
            count++;
            j = 0;
            i++;
        }
        else
            j++;
    }
    return count;
}

static int stick_last_line(char **map)
{
    int n = 0;
    for (int x = 0; map[x]; x++) {
        for (int i = 0; map[x][i] != '\0'; i++) {
            if (map[x][i] == '|')
                n++;
        }
    }
    return n;
}

static int find_last_line(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == '|')
                return i;
        }
    }
    return 0;
}

int handle_real_ia(map_t *map_struct)
{
    int nbr = check_line_with_stick(map_struct);
    int line = 0;
    int matches = 0;

    if (nbr > 1 || stick_last_line(map_struct->map) == 1)
        return 0;
    if (stick_last_line(map_struct->map) <= map_struct->stick + 1) {
        line = find_last_line(map_struct->map);
        matches = (stick_last_line(map_struct->map) - 1);
        remove_stick(line, matches, map_struct);
        my_printf("\nAI's turn...\n");
        my_printf("AI removed %d match(es) from line %d\n", matches, line);
        return 1;
    }
    return 0;
}

void the_ia(map_t *map_struct)
{
    int line = (rand() % (map_struct->lines)) + 1;
    int matches = (rand() % (map_struct->stick)) + 1;

    if (handle_real_ia(map_struct))
        return;
    while (check_errors_line_ia(line, map_struct) == 1)
        line = (rand() % map_struct->lines) + 1;
    while (check_errors_matches_ia(matches, line, map_struct) == 1)
        matches = (rand() % map_struct->stick) + 1;
    remove_stick(line, matches, map_struct);
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
}