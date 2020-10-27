#include "pathfinder.h"

t_path *mx_create_path(int isl, int dist) {
	t_path *node = (t_path*)malloc(1 * sizeof(t_path));

	node->id_path = isl;
	node->dist_path = dist;
	node->next_connect = NULL;
	node->next_path = NULL;
	return node;
}
