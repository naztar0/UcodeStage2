#include "pathfinder.h"

t_island *mx_create_island(int isl, int dist) {
    t_island *node = (t_island*)malloc(1 * sizeof(t_island));

    node->index = isl;
    node->dist_to = dist;
    node->path = NULL;
    node->next = NULL;
    return node;
}
