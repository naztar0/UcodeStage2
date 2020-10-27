#include "pathfinder.h"

t_li *create_l() {
    t_li *l = malloc(sizeof(t_li));

    l->un = NULL;
    l->v = NULL;
    l->cur = NULL;
    l->sh = NULL;
    return l;
}

t_island *mx_short_dist(t_island **unvisited) {
    t_island *head = NULL;
    t_island *shortest = NULL;

    if (unvisited || *unvisited) {
        head = *unvisited;
        shortest = *unvisited;
        while (head) {
            if (head->dist_to != 0) {
                if (shortest->dist_to > head->dist_to || !shortest->dist_to)
                    shortest = head;
            }
            head = head->next;
        }
    }
    return shortest;
}
