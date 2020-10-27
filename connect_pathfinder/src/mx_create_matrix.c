#include "pathfinder.h"

static void crfill(char **set, char **p, int ***matrix, t_int *integer) {
    int **mat = *matrix;
    int k = 0;
    int i = integer->size;
    int j = integer->root;

    if (mx_isdigit(p[j + 1][0])) {
        while (mx_strcmp(set[k], p[j - 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(p[j + 1]))
            mat[i][k] = mx_atoi(p[j + 1]);
    }
    else {
        while (mx_strcmp(set[k], p[j + 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(p[j + 2]))
            mat[i][k] = mx_atoi(p[j + 2]);
    }
}

static void mx_mat(char **set, char **p, int ***matrix) {
    t_int *i = malloc(sizeof(t_int));

    i->size = 0;
    while (set[i->size]) {
        i->root = 0;
        while (p[i->root]) {
            if (mx_strcmp(set[i->size], p[i->root]) == 0)
                crfill(set, p, &(*matrix), i);
            i->root += 1;
        }
        i->size += 1;
    }
    free(i);
    i = NULL;
}

int **mx_create_matrix(char **set, char ***p) {
    int **matrix = NULL;
    int i = 0;
    int k = 0;

    while (set[i])
        i++;
    k = i;
    matrix = malloc(sizeof(int*) * i);
    while (k >= 0) {
        matrix[k] = malloc(sizeof(int) * i);
        k--;
    }
    mx_mat(set, *p, &matrix);
    return matrix;
}
