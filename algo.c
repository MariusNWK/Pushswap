/*
** EPITECH PROJECT, 2020
** algo
** File description:
** push_swap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_list_sorted_min_to_max(list_t *list)
{
    int len_list = length_list(list);
    int n = 0;

    for (int i = 0, j = 1; j < len_list; i++, j++) {
        if (get_at(list, i) > get_at(list, j)) {
            return (0);
        }
    }
    return (1);
}

int is_list_sorted_max_to_min(list_t *list)
{
    int len_list = length_list(list);

    for (int i = 0, j = 1; j < len_list; i++, j++) {
        if (get_at(list, i) < get_at(list, j)) {
            return (0);
        }
    }
    return (1);
}

void sort_list_of_3(Sorting_t *k)
{
    if (get_at(k->list_a, 0) > get_at(k->list_a, 2) &&
        get_at(k->list_a, 2) > get_at(k->list_a, 1)) {
            ra(k);
        }
    if (get_at(k->list_a, 0) > get_at(k->list_a, 1)) {
        sa(k);
    }
    if (get_at(k->list_a, 0) > get_at(k->list_a, 2)) {
        rra(k);
    }
    if (get_at(k->list_a, 1) > get_at(k->list_a, 2)) {
        sa(k);
        ra(k);
    }
}

void sort_two_last_nbr_list_a(Sorting_t *k)
{
    int nb0 = get_at(k->list_a, 0);
    int nb1 = get_at(k->list_a, 1);

    if (nb0 > nb1) {
        sa(k);
    }
}

void algo(Sorting_t *k)
{
    int len_list = length_list(k->list_a);

    if (len_list == 2) {
        sort_two_last_nbr_list_a(k);
        return;
    }
    if (len_list == 3) {
        sort_list_of_3(k);
        return;
    }
    create_chunks(k);
    move_chunks(k);
}
