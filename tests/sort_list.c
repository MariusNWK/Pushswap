/*
** EPITECH PROJECT, 2020
** sort_list
** File description:
** push_swap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void sort_list(int ac, char **av)
{
    Sorting_t k;
    k.list_a = empty_list();
    k.list_b = empty_list();
    k.list = empty_list();
    k.chunk = empty_list();
    k.space = 0;

    for (int i = 1, nbr = 0; i < ac; i++) {
        nbr = my_getnbr(av[i]);
        k.list_a = add_at(k.list_a, nbr, i - 1);
        k.list = add_at(k.list, nbr, i - 1);
    }
    algo(&k);
    if (is_list_sorted_min_to_max(k.list_a) == 1) {
        write(1, "The list is sorted\n", 19);
    }
    else {
        write(1, "The list isn't sorted\n", 22);
    }
    k.list_a = free_list(k.list_a);
    k.list_b = free_list(k.list_b);
}