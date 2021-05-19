/*
** EPITECH PROJECT, 2020
** tab_tools
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_tab_sorted(int *tab, int k, int size)
{
    for (int i = 0, j = 1; j < size; i++, j++) {
        if (tab[k * 5 + i] > tab[k * 5 + j]) {
            return (0);
        }
    }
    return (1);
}

int *sort_tab(int *tab, int k, int size)
{
    for (int i = 0, j = 1, swap = 0; j < size; i++, j++) {
        if (tab[k * 5 + i] > tab[k * 5 + j]) {
            swap = tab[k * 5 + i];
            tab[k * 5 + i] = tab[k * 5 + j];
            tab[k * 5 + j] = swap;
        }
    }
    return (tab);
}

int median_tab(int *tab, int k, int size)
{
    if (size == 5 || size == 4) {
        return (tab[k * 5 + 2]);
    }
    if (size == 3 || size == 2) {
        return (tab[k * 5 + 1]);
    }
    if (size == 1) {
        return (tab[k * 5 + 0]);
    }
}