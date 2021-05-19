/*
** EPITECH PROJECT, 2020
** chunks_sorter
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int loop(int lenlist_b, int add, int numbers_moved, Sorting_t *k)
{
    int cur = 0;
    int limit = get_at(k->chunk, 0);

    for (int i = 0; i < lenlist_b &&
        numbers_moved < limit / 2 - add; i++) {
        cur = get_at(k->list_b, 0);
        if (cur > k->median) {
            pa(k);
            numbers_moved = numbers_moved + 1;
        }
        else {
            rb(k);
            k->count_rb++;
        }
    }
    return (numbers_moved);
}

void higher_than_median_in_list_a(Sorting_t *k)
{
    int lenlist_b = length_list(k->list_b);
    int numbers_moved = 0;
    int add = 0;

    k->count_rb = 0;
    if (get_at(k->chunk, 0) % 2 == 0) {
        add = 1;
    }
    numbers_moved = loop(lenlist_b, add, numbers_moved, k);
    k->size_sent = numbers_moved;
    set_at(k->chunk, get_at(k->chunk, 0) - k->size_sent, 0);
    while (k->count_rb > 0 && k->last_chunk == 0) {
        rrb(k);
        k->count_rb--;
    }
}

int is_median_biggest_nbr_in_klist(int median, List_t *list)
{
    int lenlist = length_list(list);

    for (int i = 0; i < lenlist ; i++) {
        if (get_at(list, i) > median) {
            return (0);
        }
    }
    return (1);
}

void chunks_sorter(Sorting_t *k)
{
    while (get_at(k->chunk, 0) > 2) {
        k->list = empty_list();
        for (int i = 0; i < get_at(k->chunk, 0); i++) {
            k->list = add_at(k->list, get_at(k->list_b, i), i);
        }
        if (is_list_sorted_max_to_min(k->list) == 1) {
            for (int i = 0; i < get_at(k->chunk, 0); i++) {
                pa(k);
            }
            k->list = free_list(k->list);
            k->chunk = free_at(k->chunk, 0);
            return;
        }
        k->median = find_median(k);
        if (is_median_biggest_nbr_in_klist(k->median, k->list) == 1) {
            k->median = k->median - 1;
        }
        higher_than_median_in_list_a(k);
        k->list = free_list(k->list);
        sort_sent(k);
    }
}