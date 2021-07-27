/*
** EPITECH PROJECT, 2021
** map_creation
** File description:
** .
*/

#include <matchstick.h>

void print_map(char **map)
{
    for (int i = 0; map[i]; i++)
        my_printf("%s\n", map[i]);
}

int biggest_line(int a)
{
    int result = 0;

    for (int i = 0; i != a; i++) {
        if (i == 1)
            result = 1;
        result += 2;
    }

    return result;
}

char *fill_string(int stick, int biggest)
{
    int space = ((biggest - stick) / 2);
    char *map = malloc(sizeof(char) * (biggest + 3));
    int n = 0;

    map[0] = '*';
    map[biggest + 1] = '*';
    for (int i = 1; i != biggest + 1; i++) {
        if (i < space + 1)
            map[i] = ' ';
        else if (n < stick) {
            map[i] = '|';
            n++;
        } else
            map[i] = ' ';
    }
    map[biggest + 2] = '\0';
    return map;
}

char *fill_star(int a)
{
    char *new = malloc(sizeof(char) * (a + 3));

    for (int i = 0; i != a + 2; i++)
        new[i] = '*';
    new[a + 2] = '\0';
    return new;
}

char **create_game_board(int a)
{
    char **map = malloc(sizeof(char *)* (a + 3));
    int character = 1;

    map[0] = fill_star(biggest_line(a));
    map[a + 1] = fill_star(biggest_line(a));
    for (int i = 1;i != a + 1; i++) {
        map[i] = fill_string(character, biggest_line(a));
        character += 2;
    }
    map[a + 2] = NULL;
    return map;
}