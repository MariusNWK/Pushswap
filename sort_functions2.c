/*
** EPITECH PROJECT, 2020
** sort_functions2
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void ra(Sorting_t *k)
{
    int save = 0;
    int len = length_list(k->list_a);

    if (len > 1) {
        save = get_at(k->list_a, 0);
        k->list_a = free_at(k->list_a, 0);
        k->list_a = add_at(k->list_a, save, len - 1);
    }
    if (k->space == 1) {
        write(1, " ra", 3);
    }
    else {
        write(1, "ra", 2);
    }
    k->space = 1;
}

void rb(Sorting_t *k)
{
    int save = 0;
    int len = length_list(k->list_b);

    if (len > 1) {
        save = get_at(k->list_b, 0);
        k->list_b = free_at(k->list_b, 0);
        k->list_b = add_at(k->list_b, save, len - 1);
    }
    if (k->space == 1) {
        write(1, " rb", 3);
    }
    else {
        write(1, "rb", 2);
    }
    k->space = 1;
}

void rra(Sorting_t *k)
{
    int save = 0;
    int len = length_list(k->list_a);

    if (len > 1) {
        save = get_at(k->list_a, len - 1);
        k->list_a = free_at(k->list_a, len - 1);
        k->list_a = add_at(k->list_a, save, 0);
    }
    if (k->space == 1) {
        write(1, " rra", 4);
    }
    else {
        write(1, "rra", 3);
    }
    k->space = 1;
}

void rrb(Sorting_t *k)
{
    int save = 0;
    int len = length_list(k->list_b);

    if (len > 1) {
        save = get_at(k->list_b, len - 1);
        k->list_b = free_at(k->list_b, len - 1);
        k->list_b = add_at(k->list_b, save, 0);
    }
    if (k->space == 1) {
        write(1, " rrb", 4);
    }
    else {
        write(1, "rrb", 3);
    }
    k->space = 1;
}