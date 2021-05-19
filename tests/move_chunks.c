/*
** EPITECH PROJECT, 2020
** move_chunks
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void send_or_swap_and_send_to_list_a(Sorting_t *k)
{
    if (get_at(k->list_b, 0) < get_at(k->list_b, 1)) {
        sb(k);
        pa(k);
        pa(k);
    }
    else {
        pa(k);
        pa(k);
    }
}

void move_chunks(Sorting_t *k)
{
    k->last_chunk = 0;
    while (k->chunk) {
        if (k->chunk->next == NULL)
            k->last_chunk = 1;
        else
            k->last_chunk = 0;
        if (get_at(k->chunk, 0) == 1)
            pa(k);
        else if (get_at(k->chunk, 0) == 2)
            send_or_swap_and_send_to_list_a(k);
        else {
            chunks_sorter(k);
            if (get_at(k->chunk, 0) == 1)
                pa(k);
            else if (get_at(k->chunk, 0) == 2)
                send_or_swap_and_send_to_list_a(k);
        }
        if (get_at(k->chunk, 0) <= 2)
            k->chunk = free_at(k->chunk, 0);
    }
}