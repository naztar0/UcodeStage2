#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_path {
    int id_path;
    int dist_path;
    int index;
    struct s_path *next_connect;
    struct s_path *next_path;
}		t_path;

typedef struct s_island {
    int index;
    int dist_to;
    struct s_path *path;
    struct s_island *next;
}		t_island;

typedef struct s_char {
    char *p;
    char *r;
    char *d;
    int s;
}		t_char;

typedef struct s_int {
    int size;
    int root;
}		t_int;

typedef struct s_md {
    int isl1;
    int isl2;
    int mat;
}		t_md;

typedef struct s_li {
    t_island *un;
    t_island *v;
    t_island *cur;
    t_island *sh;
}		t_li;

void mx_algorithm(int**, char**);
void mx_check_errors(int, char**, char*);
void mx_check_spaces(char**, char*);
void mx_parse_matrix(char*, int***, char***);
int **mx_create_matrix(char**, char***);
void mx_create_set(char***, char***, char*);
void mx_create_arr(char**, char***);
t_island *mx_create_island(int, int);
void mx_pbi(t_island**, t_path**, int, int);
t_path *mx_copy_path(t_path**);
t_path *mx_create_path(int, int);
t_path *mx_add_path(t_path**, int, int);
t_path *mx_add_single_path(t_path**, int, int);
void mx_pop_first_island(t_island **);
void mx_pop_second_island(t_island**, int);
void mx_push_back_path(t_path**, t_path**, int, int);
int mx_uniq_path(t_path**, t_path**);
void mx_add_link(t_path**, t_path**);
t_li *create_l();
t_island *mx_short_dist(t_island**);
void mx_join(char**, char*);
void mx_sort_path(t_path**, int);
void mx_output(t_island**, int, int, char**);
int mx_add_index_pathes(t_path**);
void mx_free_path(t_path**);
void mx_free_matrix(int***, char**);

#endif
