/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 2
*/
typedef struct Cell
{
    int data;
    struct Cell *next;
}List_t, Cell_t;

List_t *empty_list(void);
int is_empty_list(List_t *);
long length_list(List_t *);
List_t *add_at(List_t *, int, int);
int get_at(List_t *, int);
void set_at(List_t *, int, int);
List_t *free_at(List_t *, int);
List_t *free_list(List_t *);
void print_list(List_t *);

//////////////////////////////////////////

void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);

//////////////////////////////////////////

typedef struct Sorting
{
    List_t *list_a;
    List_t *list_b;
    List_t *list;
    List_t *chunk;
    int median;
    int size_sent;
    int count_rb;
    int count_ra;
    int del_klist;
    int last_chunk;
    int space;
}Sorting_t;

void sort_list(int, char **);
void sa(Sorting_t *);
void sb(Sorting_t *);
void sc(Sorting_t *);
void pa(Sorting_t *);
void pb(Sorting_t *);
void ra(Sorting_t *);
void rb(Sorting_t *);
void rr(Sorting_t *);
void rra(Sorting_t *);
void rrb(Sorting_t *);
void rrr(Sorting_t *);

//////////////////////////////////////////

void algo(Sorting_t *);
void create_chunks(Sorting_t *);
void move_chunks(Sorting_t *);
void chunks_sorter(Sorting_t *);
void sort_sent(Sorting_t *);
int find_median(Sorting_t *);
void send_or_swap_and_send_to_list_A(Sorting_t *);
void sort_two_last_nbr_list_a(Sorting_t *);
void lower_than_median_in_list_b(Sorting_t *);
int is_list_sorted_min_to_max(List_t *);
int is_list_sorted_max_to_min(List_t *);

//////////////////////////////////////////

typedef struct Median
{
    int lines_tab;
    int *dbtab;
    int *new_tab;
    int *sizetab;
    int median;
}Median_t;

//////////////////////////////////////////

typedef struct Pivot
{
    int pivot;
    int lenlist;
    int lenleft_list;
    int same;
    List_t *left_list;
    List_t *right_list;
}Pivot_t;

int check_if_pivot_is_median(List_t *, int);
int find_pivot(List_t *);
int is_tab_sorted(int *, int, int);
int *sort_tab(int *, int, int);
int median_tab(int *, int, int);