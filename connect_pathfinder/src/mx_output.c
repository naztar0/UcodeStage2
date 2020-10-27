#include "pathfinder.h"

static void print_line(t_char **prd) {
    char *string = mx_strdup("========================================");

    mx_printstr(string);
    mx_printchar('\n');
    mx_printstr((*prd)->p);
    mx_printstr((*prd)->r);
    mx_printstr((*prd)->d);
    mx_printstr(string);
    mx_printchar('\n');
    mx_strdel(&(*prd)->p);
    mx_strdel(&(*prd)->r);
    mx_strdel(&(*prd)->d);
    mx_strdel(&string);
    free(*prd);
    *prd = NULL;
}

static t_char *create_prd(t_path *bond, char **set) {
    t_char *prd = malloc(1 * sizeof(t_char));
    int i = 0;

    prd->p = mx_strdup("Path: ");
    mx_join(&(*prd).p, set[bond->id_path]);
    prd->r = mx_strdup("Route: ");
    mx_join(&(*prd).r, set[bond->id_path]);
    prd->d = mx_strdup("Distance: ");
    for (; bond; bond = bond->next_connect, i++);
    prd->s = i;
    return prd;
}

static void add_next_bond(t_char **prd, t_path *bond, char *distTo, char **set) {
    char *dist = mx_itoa(bond->dist_path);
    
    mx_join(&(*prd)->r, " -> ");
    mx_join(&(*prd)->r, set[bond->id_path]);
    if (mx_strlen((*prd)->d) != 10)
        mx_join(&(*prd)->d, " + ");
    mx_join(&(*prd)->d, dist);
    mx_strdel(&dist);
    if (bond->next_connect == NULL) {
        mx_join(&(*prd)->p, " -> ");
        mx_join(&(*prd)->p, set[bond->id_path]);
        if ((*prd)->s != 2) {
            mx_join(&(*prd)->d, " = ");
            mx_join(&(*prd)->d, distTo);
        }
        mx_join(&(*prd)->r, "\n");
        mx_join(&(*prd)->p, "\n");
        mx_join(&(*prd)->d, "\n");
    }
}

static void display_path(t_path **disp, int dist_to, char **set) {
    t_path *bond = *disp;
    t_char *prd = NULL;
    char *dist = mx_itoa(dist_to);

    while (bond) {
        prd = create_prd(bond, set);
        bond = bond->next_connect;
        while (bond->next_connect) {
            add_next_bond(&prd, bond, dist, set);
            bond = bond->next_connect;
        }
        add_next_bond(&prd, bond, dist, set);
        print_line(&prd);
        bond = bond->next_path;
    }
    mx_strdel(&dist);
}

void mx_output(t_island **visited, int root, int size, char **set) {
    t_island *current = NULL;
    int sizeP;

    for (; root < size; root++) {
        current = *visited;
        while (current->index != root)
            current = current->next;
        sizeP = mx_add_index_pathes(&current->path);
        mx_sort_path(&current->path, sizeP);
        display_path(&current->path, current->dist_to, set);
    }
}
