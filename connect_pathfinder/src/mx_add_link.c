#include "pathfinder.h"

void mx_add_link(t_path **cur, t_path **new) {
    t_path *current = *cur;

    while (current->next_connect) {
        current->next_path = *new;
        current = current->next_connect;
    }
    current->next_path = *new;
}
