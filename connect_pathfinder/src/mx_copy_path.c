#include "pathfinder.h"

static t_path *add_one(t_path **previous) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    res = mx_create_path(last->id_path, last->dist_path);
    new = res;
    last = last->next_connect;
    while (last) {
        new->next_connect = mx_create_path(last->id_path, last->dist_path);
        last = last->next_connect;
        new = new->next_connect;
    }
    return res;
}

t_path *mx_copy_path(t_path **data) {
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*data)
        cur = *data;
    res = add_one(&cur);
    fast = res;
    cur = cur->next_path;
    while (cur) {
        new = add_one(&cur);
        mx_add_link(&fast, &new);
        fast = fast->next_path;
        cur = cur->next_path;
    }
    return res;
}
