#include "pathfinder.h"

static void pop_all(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) 
        return;
    while ((*head)->next_connect) {
        p = (*head)->next_connect;
        free(*head);
        *head = p;
    }
    if (!(*head)->next_connect && !(*head)->next_path) {
        free(*head);
        *head = NULL;
        return;
    }
}

static void pop_next_path(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) 
        return;
    if ((*head)->next_path == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = (*head)->next_path;
        free(*head);
        *head = p;
    }
}

void mx_free_path(t_path **head) {
    if (!head || !(*head)) 
        return;
    while(*head) {
        pop_all(&(*head));
        pop_next_path(&(*head));
    }
}
