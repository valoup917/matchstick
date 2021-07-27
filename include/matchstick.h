/*
** EPITECH PROJECT, 2021
** include
** File description:
** .
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct map_s
{
    char **map;
    int biggest_line;
    int stick;
    int lines;
    int tmp_sticks;
} map_t;

void my_printf(char *str, ...);
void convert(long number_to_convert, int base);
void convert2(long number_to_convert, int base);
int usigned(int nbri);
long my_put_long(long nb);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
int my_getnbr(char *str);

/*my_game.c*/
int errors(int argc, char **argv);
map_t *fill_struct(int length, int stick);
int my_input(map_t *map_struct);
int my_game(int length, int stick);

/*the_ia.c*/
void the_ia(map_t *map_struct);

/* map_creation.c*/
void print_map(char **map);
int biggest_line(int a);
char *fill_string(int stick, int biggest);
char *fill_star(int a);
char **create_game_board(int a);

/*map_organisatuion.c*/
int check_nbr(char *str);
void remove_stick(int x, int n, map_t *map_struct);
int len_map(char **map);
int stick_line(int x, char **map);
int check_error(map_t *map_struct, int x, int n);

/*check_loose.c*/
int check_human_loose(map_t *map_struct);
int check_ia_loose(map_t *map_struct);

/*check_errors.c*/
int check_string(char *str);
int check_errors_matches(char *matches, int line, map_t *map_struct);
int check_errors_line(char *line, map_t *map_struct);
int check_errors_matches_ia(int n, int line, map_t *map_struct);
int check_errors_line_ia(int x, map_t *map_struct);

int choose_matches(map_t *map_struct, int *line);
int choose_lines(map_t *map_struct);
int choose_lines(map_t *map_struct);

#endif /* !MATCHSTICK_H_ */