#include "pathfinder.h"

static void firs_if(t_island *temp, t_island *left, int index) {
    if (temp && temp->index == index) {
        if (temp->next)
            left->next = temp->next;
        else
            left->next = NULL;
        mx_free_path(&temp->path);
        free(temp);
        temp = NULL;
    }
}

void mx_pop_second_island(t_island **unvisited, int index) {
    t_island *temp = NULL;
    t_island *left = NULL;

    if (!unvisited || !(*unvisited)) 
        return;
    if ((*unvisited)->index == index) {
        mx_free_path(&((*unvisited)->path));
        mx_pop_first_island(&(*unvisited));
    }
    else {
        temp = *unvisited;
        left = temp;
        while (temp != NULL && temp->index != index) {
            left = temp;
            temp = temp->next;
        }
        firs_if(temp, left, index);
    }
}
