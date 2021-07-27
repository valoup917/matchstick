/*
** EPITECH PROJECT, 2021
** main
** File description:
** .
*/

#include <matchstick.h>

int main(int argc, char **argv, char const **env)
{
    if (*env == NULL)
        return 84;
    if (errors(argc, argv) == 1)
        return 84;
    return (my_game(my_getnbr(argv[1]), my_getnbr(argv[2])));
}