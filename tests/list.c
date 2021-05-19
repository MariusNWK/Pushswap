/*
** EPITECH PROJECT, 2020
** list
** File description:
** pushswap
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static Cell_t *create_cell(int data)
{
    Cell_t *cell = malloc(sizeof(Cell_t));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    return (cell);
}

List_t *empty_list(void)
{
    return (NULL);
}

int is_empty_list(List_t *list)
{
    return (list == NULL);
}

long length_list(List_t *list)
{
    long len = 0;
    while (list) {
        len++;
        list = list->next;
    }
    return (len);
}

List_t *add_at(List_t *list, int data, int pos)
{
    List_t *prec = list;
    List_t *cur = list;
    int i = 0;
    Cell_t *cell = create_cell(data);

    if (is_empty_list(list)) {
        return (cell);
    }
    if (pos == 0) {
        cell->next = list;
        return (cell);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cell;
    cell->next = cur;
    return (list);
}