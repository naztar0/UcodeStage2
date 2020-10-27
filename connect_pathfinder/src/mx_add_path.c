#include "pathfinder.h"

t_path *mx_add_path(t_path **previous, int isl, int dist) {
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*previous)
        cur = *previous;
    res = mx_add_single_path(&cur, isl, dist);
    fast = res;
    if (cur)
        cur = cur->next_path;
    while (cur) {
        new = mx_add_single_path(&cur, isl, dist);
        mx_add_link(&fast, &new);
        fast = fast->next_path;
        cur = cur->next_path;
    }
    return res;
}
