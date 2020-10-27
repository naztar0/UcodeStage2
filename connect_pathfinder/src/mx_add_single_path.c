#include "pathfinder.h"

t_path *mx_add_single_path(t_path **previous, int isl, int dist) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    if (!last)
        return mx_create_path(isl, dist);

    res = mx_create_path(last->id_path, last->dist_path);
    new = res;
    last = last->next_connect;
    while (last) {
        new->next_connect = mx_create_path(last->id_path, last->dist_path);
        last = last->next_connect;
        new = new->next_connect;
    }
    new->next_connect = mx_create_path(isl, dist);

    return res;
}
