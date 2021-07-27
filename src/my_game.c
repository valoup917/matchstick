/*
** EPITECH PROJECT, 2021
** boostrap
** File description:
** .
*/

#include <matchstick.h>

int check_string2(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 1;
    }
    return 0;
}

int errors(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    if (check_string2(argv[1]) == 1 || check_string2(argv[2]) == 1)
        return 1;
    if (my_getnbr(argv[1]) <= 1 || my_getnbr(argv[1]) >= 100)
        return 1;
    return 0;
}

int my_input(map_t *map_struct)
{
    int line = choose_lines(map_struct);
    int matches = 0;

    if (line == -1)
        return -1;
    matches = choose_matches(map_struct, &line);
    if (matches == -1)
        return -1;
    remove_stick(line, matches, map_struct);
    my_printf("Player removed %d match(es) from line %d\n",
    matches, line);
    return 0;
}

map_t *fill_struct(int length, int stick)
{
    map_t *map_struct = malloc(sizeof(map_t));
    map_struct->map = create_game_board(length);
    map_struct->biggest_line = biggest_line(length);
    map_struct->stick = stick;
    map_struct->lines = length;
    return map_struct;
}

int my_game(int length, int stick)
{
    map_t *map_struct = fill_struct(length, stick);

    while (1) {
        print_map(map_struct->map);
        my_printf("\nYour turn:");
        if (my_input(map_struct) == -1)
            return 0;
        if (check_human_loose(map_struct) == 2)
            return 2;
        print_map(map_struct->map);
        the_ia(map_struct);
        if (check_ia_loose(map_struct) == 1)
            return 1;
    }
    return 0;
}