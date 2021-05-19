/*
** EPITECH PROJECT, 2020
** sort_sent.c
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sort_first_two_list_a_nbr(Sorting_t *k)
{
    if (get_at(k->list_a, 0) > get_at(k->list_a, 1)) {
        sa(k);
    }
}

void lower_than_klistmedian_in_list_b(Sorting_t *k)
{
    int lenlist = length_list(k->list) + k->del_klist;
    int cur = 0;
    int len_chunk = 0;

    k->count_ra = 0;
    for (int i = 0; i < lenlist && len_chunk < lenlist / 2; i++) {
        cur = get_at(k->list_a, 0);
        if (cur < k->median) {
            pb(k);
            len_chunk = len_chunk + 1;
        }
        else {
            ra(k);
            k->count_ra++;
        }
    }
    k->chunk = add_at(k->chunk, len_chunk, 0);
    while (k->count_ra > 0) {
        rra(k);
        k->count_ra--;
    }
}

void are_nbrs_equal_to_median(Sorting_t *k)
{
    int lenlist = length_list(k->list);

    for (int i = 0, same = 0, cur = 0; i < lenlist; i++) {
        cur = get_at(k->list, i);
        if (cur == k->median) {
            same++;
        }
        if (cur == k->median && same > 1) {
            set_at(k->list, cur - 1, i);
            k->del_klist++;
            set_at(k->list_a, cur - 1, i);
        }
    }
}

void create_chunks_two(Sorting_t *k)
{
    k->median = find_median(k);
    are_nbrs_equal_to_median(k);
    lower_than_klistmedian_in_list_b(k);
    if (length_list(k->list) > 2) {
        create_chunks_two(k);
        return;
    }
    sort_first_two_list_a_nbr(k);
    k->list = free_list(k->list);
}

void sort_sent(Sorting_t *k)
{
    if (k->size_sent == 2) {
        sort_first_two_list_a_nbr(k);
    }
    else if (k->size_sent > 2) {
        k->list = empty_list();
        for (int i = 0; i < k->size_sent; i++) {
            k->list = add_at(k->list, get_at(k->list_a, i), i);
        }
        if (is_list_sorted_min_to_max(k->list) == 0) {
            create_chunks_two(k);
        }
        else {
            k->list = free_list(k->list);
        }
    }
}