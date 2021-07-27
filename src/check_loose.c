/*
** EPITECH PROJECT, 2021
** check_loose
** File description:
** .
*/

#include <matchstick.h>

int cehck_more(char c, int count)
{
    if (c == '|')
        count++;
    return count;
}

int check_still_stick(map_t *map_struct)
{
    int count = 0;
    for (int i = 0; map_struct->map[i]; i++)
        for (int y = 0; map_struct->map[i][y]; y++)
            count = cehck_more(map_struct->map[i][y], count);
    if (count <= 0)
        return (1);
    else
        return 0;
}

int check_human_loose(map_t *map_struct)
{
    if (check_still_stick(map_struct) == 1) {
        print_map(map_struct->map);
        my_printf("You lost, too bad...\n");
        return (2);
    }
    return 0;
}

int check_ia_loose(map_t *map_struct)
{
    if (check_still_stick(map_struct) == 1) {
        print_map(map_struct->map);
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return 0;
}