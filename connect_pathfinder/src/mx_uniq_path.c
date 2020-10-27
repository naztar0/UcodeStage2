#include "pathfinder.h"

static void compare(t_path **new, t_path **cur, int *flag) {
    if (*new && *cur) {
        if ((*new)->id_path != (*cur)->id_path)
            *flag = 1;
        if ((*new)->dist_path != (*cur)->dist_path)
            *flag = 1;
    }
    if (!(*new) || !(*cur))
        *flag = 1;
}

static void step(t_path **old, t_path **path, t_path **new) {
    *path = *new;
    *old = (*old)->next_path;
}

int mx_uniq_path(t_path **new, t_path **current) {
    t_path *path = *new;
    t_path *old = *current;
    int flag = -1;

    while (old) {
        if (old->next_connect == NULL || !path) {
            compare(&path, &old, &flag);
            step(&old, &path, &(*new));
            if (flag == -1)
                return -1;
            if (old)
                flag = -1;
            continue;
        }
        compare(&path, &old, &flag);
        path = path->next_connect;
        old = old->next_connect;
    }
    return flag;
}
