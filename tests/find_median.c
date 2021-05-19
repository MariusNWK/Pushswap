/*
** EPITECH PROJECT, 2020
** find_median
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

List_t *copy_list(List_t *list)
{
    List_t *copy = empty_list();
    int lenlist = length_list(list);

    for (int i = 0; i < lenlist; i++) {
        copy = add_at(copy, get_at(list, i), i);
    }
    return (copy);
}

int sort_and_find(List_t *list, int lenlist)
{
    int median = 0;
    int *tab = malloc(sizeof(int) * lenlist);

    for (int i = 0; i < lenlist; i++) {
        tab[i] = get_at(list, i);
    }
    while (is_tab_sorted(tab, 0, lenlist) == 0) {
        sort_tab(tab, 0, lenlist);
    }
    median = median_tab(tab, 0, lenlist);
    free(tab);
    return (median);
}

int find_median(Sorting_t *k)
{
    int median = 0;
    int lenlist = length_list(k->list);
    int index = lenlist / 2;
    List_t *copy_klist = copy_list(k->list);

    if (lenlist <= 5) {
        median = sort_and_find(k->list, lenlist);
        copy_klist = free_list(copy_klist);
    }
    else
        median = check_if_pivot_is_median(copy_klist, index);
    k->del_klist = 0;
    for (int i = 0, n = 0; i < lenlist; i++) {
        if (get_at(k->list, n) < median) {
            k->list = free_at(k->list, n);
            k->del_klist++;
        }
        else
            n++;
    }
    return (median);
}