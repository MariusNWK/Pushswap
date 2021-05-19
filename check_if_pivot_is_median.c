/*
** EPITECH PROJECT, 2020
** check_if_pivot_is_median
** File description:
** pushswap
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void create_lists(Pivot_t *p, list_t *list)
{
    p->lenlist = length_list(list);
    p->lenleft_list = 0;
    p->same = 0;
    p->left_list = empty_list();
    p->right_list = empty_list();
    for (int i = 0, cur = 0; i < p->lenlist; i++) {
        cur = get_at(list, i);
        if (cur < p->pivot) {
            p->left_list = add_at(p->left_list, cur, 0);
        }
        else if (cur == p->pivot) {
            p->same = p->same + 1;
        }
        else {
            p->right_list = add_at(p->right_list, cur, 0);
        }
        if (p->same > 1 && cur == p->pivot) {
            p->left_list = add_at(p->left_list, cur, 0);
        }
    }
    p->lenleft_list = length_list(p->left_list);
}

int check_if_pivot_is_median(list_t *list, int index)
{
    Pivot_t p;

    p.pivot = find_pivot(list);
    create_lists(&p, list);
    if (p.lenleft_list == index) {
        p.left_list = free_list(p.left_list);
        p.right_list = free_list(p.right_list);
        list = free_list(list);
        return (p.pivot);
    }
    if (p.lenleft_list < index) {
        p.left_list = free_list(p.left_list);
        list = free_list(list);
        return (check_if_pivot_is_median(p.right_list,
                                        index - (p.lenleft_list + 1)));
    }
    else if (p.lenleft_list > index) {
        p.right_list = free_list(p.right_list);
        list = free_list(list);
        return (check_if_pivot_is_median(p.left_list, index));
    }
}