#include "pathfinder.h"

void mx_push_back_path(t_path **path, t_path **previous, int isl, int dist) {
    t_path *last = *path;
    t_path *cur = *previous;
    t_path *new = NULL;
    
    while (last->next_path != NULL)
        last = last->next_path;
    while (cur) {
        new = mx_add_single_path(&cur, isl, dist);
        if (mx_uniq_path(&new, &(*path)) == 1) {
            mx_add_link(&last, &new);
            last = last->next_path;
        }
        cur = cur->next_path;
    }
}
