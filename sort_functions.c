/*
** EPITECH PROJECT, 2020
** sort_functions
** File description:
** push_swap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void sa(Sorting_t *k)
{
    int save;

    if (length_list(k->list_a) > 1) {
        save = get_at(k->list_a, 0);
        set_at(k->list_a, get_at(k->list_a, 1), 0);
        set_at(k->list_a, save, 1);
    }
    if (k->space == 1) {
        write(1, " sa", 3);
    }
    else {
        write(1, "sa", 2);
    }
    k->space = 1;
}

void sb(Sorting_t *k)
{
    int save = 0;

    if (length_list(k->list_b) > 1) {
        save = get_at(k->list_b, 0);
        set_at(k->list_b, get_at(k->list_b, 1), 0);
        set_at(k->list_b, save, 1);
    }
    if (k->space == 1) {
        write(1, " sb", 3);
    }
    else {
        write(1, "sb", 2);
    }
    k->space = 1;
}

void pa(Sorting_t *k)
{
    int save = 0;

    if (length_list(k->list_b) > 0) {
        save = get_at(k->list_b, 0);
        k->list_b = free_at(k->list_b, 0);
        k->list_a = add_at(k->list_a, save, 0);
    }
    if (k->space == 1) {
        write(1, " pa", 3);
    }
    else {
        write(1, "pa", 2);
    }
    k->space = 1;
}

void pb(Sorting_t *k)
{
    int save = 0;

    if (length_list(k->list_a) > 0) {
        save = get_at(k->list_a, 0);
        k->list_a = free_at(k->list_a, 0);
        k->list_b = add_at(k->list_b, save, 0);
    }
    if (k->space == 1) {
        write(1, " pb", 3);
    }
    else {
        write(1, "pb", 2);
    }
    k->space = 1;
}