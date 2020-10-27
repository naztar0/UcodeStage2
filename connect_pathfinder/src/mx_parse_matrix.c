#include "pathfinder.h"

void mx_parse_matrix(char *file, int ***matrix, char ***set) {
    char **p = NULL;
    char **src = mx_strsplit(file, '\n');

    mx_create_arr(src, &p);
    mx_create_set(&(*set), &p, src[0]);
    *matrix = mx_create_matrix(*set, &p);
    mx_del_strarr(&src);
    mx_del_strarr(&p);
}
