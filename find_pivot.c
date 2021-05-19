/*
** EPITECH PROJECT, 2020
** find_pivot
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void separate_in_chunks_of_five(Median_t *m, int len_tab, int *tab)
{
    m->dbtab = malloc(sizeof(int) * len_tab);
    m->sizetab = malloc(sizeof(int) * m->lines_tab);
    for (int i = 0, k = 0; i < m->lines_tab; i++) {
        if (i + 1 == m->lines_tab && len_tab % 5 > 0) {
            m->sizetab[i] = len_tab % 5;
        }
        else {
            m->sizetab[i] = 5;
        }
        for (int j = 0; j < 5; j++, k++) {
            if (k < len_tab) {
                m->dbtab[i * 5 + j] = tab[k];
            }
        }
    }
}

void create_tab_of_medians(Median_t *m, int *tab)
{
    for (int i = 0; i < m->lines_tab; i++) {
        while (is_tab_sorted(m->dbtab, i, m->sizetab[i]) == 0) {
            m->dbtab = sort_tab(m->dbtab, i, m->sizetab[i]);
        }
    }
    m->new_tab = malloc(sizeof(int) * m->lines_tab);
    for (int i = 0; i < m->lines_tab; i++) {
        m->new_tab[i] = median_tab(m->dbtab, i, m->sizetab[i]);
    }
    free(m->dbtab);
    free(m->sizetab);
    free(tab);
}

int find_median_tab(int *tab, int len_tab)
{
    Median_t m;
    m.lines_tab = len_tab / 5;
    m.median = 0;

    if (len_tab % 5 > 0) {
        m.lines_tab = m.lines_tab + 1;
    }
    separate_in_chunks_of_five(&m, len_tab, tab);
    create_tab_of_medians(&m, tab);
    if (m.lines_tab == 1) {
        m.median = m.new_tab[0];
        free(m.new_tab);
        return (m.median);
    }
    else {
        return (find_median_tab(m.new_tab, m.lines_tab));
    }
}

int find_pivot(list_t *list)
{
    int len_tab = length_list(list);
    int *tab = malloc(sizeof(int) * len_tab);
    int pivot = 0;

    for (int i = 0; i < len_tab; i++) {
        tab[i] = get_at(list, i);
    }
    pivot = find_median_tab(tab, len_tab);
    return (pivot);
}