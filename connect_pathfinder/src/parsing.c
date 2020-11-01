#include "../inc/pathfinder.h"

void parsing(char *fd, int ***matrix, char ***set) {
    char **p = NULL;
    char **src = mx_strsplit(fd, '\n');

    create_arr(src, &p);
    create_set(&(*set), &p, src[0]);
    *matrix = create_matrix(*set, &p);
    mx_del_strarr(&src);
    mx_del_strarr(&p);
}
