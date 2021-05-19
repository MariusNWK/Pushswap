/*
** EPITECH PROJECT, 2020
** main
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_sorted_list(int ac, char **av)
{
    int sup = 0;

    if (ac == 2) {
        write(1, "No changes to do\n", 17);
        return (1);
    }
    for (int i = 1, j = 2; j < ac && sup == 0; i++, j++) {
        if (my_getnbr(av[i]) > my_getnbr(av[j])) {
            sup = 1;
        }
        if (j + 1 == ac && sup == 0) {
            write(1, "No changes to do\n", 17);
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        write(2, "Not enough arguments\n", 21);
        return (84);
    }
    if (is_sorted_list(ac, av) == 1)
        return (0);
    sort_list(ac, av);
    return (0);
}