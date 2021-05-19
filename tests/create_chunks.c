/*
** EPITECH PROJECT, 2020
** algo1
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void lower_than_median_in_list_b(Sorting_t *k)
{
    int lenlist = length_list(k->list_a);
    int cur = 0;
    int len_chunk = 0;

    for (int i = 0; i < lenlist && len_chunk < lenlist / 2; i++) {
        cur = get_at(k->list_a, 0);
        if (cur < k->median) {
            pb(k);
            len_chunk = len_chunk + 1;
        }
        else {
            ra(k);
        }
    }
    k->chunk = add_at(k->chunk, len_chunk, 0);
}

void create_chunks(Sorting_t *k)
{
    k->median = find_median(k);
    lower_than_median_in_list_b(k);
    if (length_list(k->list) > 2) {
        create_chunks(k);
        return;
    }
    sort_two_last_nbr_list_a(k);
    free_list(k->list);
}