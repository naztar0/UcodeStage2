#include "pathfinder.h"

static int cmp(t_path *bond, t_path *fast) {
    while (bond && fast) {
        if (bond->id_path > fast->id_path)
            return 1;
        if (bond->id_path < fast->id_path)
            return 0;
        bond = bond->next_connect;
        fast = fast->next_connect;
    }
    if (bond && !fast)
        return 1;
    return 0;
}

static void swpD(t_path **disp, t_path **bond, t_path **fast) {
    t_path *temp = (*fast)->next_path;
    t_path *cur = *disp;

    while(cur->next_path != *fast)
        cur = cur->next_path;
    mx_add_link(&cur, &(*bond));
    cur = *disp;
    if (*disp == *bond)
        *disp = *fast;
    else {
        while (cur && cur->next_path != *bond)
            cur = cur->next_path;
        mx_add_link(&cur, &(*fast));
    }
    mx_add_link(&(*fast), &(*bond)->next_path);
    mx_add_link(&(*bond), &temp);
}

static void swap(t_path **disp, t_path **bond, t_path **fast) {
    t_path *temp = (*fast)->next_path;
    t_path *curr = *disp;

    if ((*bond)->next_path == *fast) {
            mx_add_link(&(*fast), &(*bond));
            mx_add_link(&(*bond), &temp);
        if (*disp == *bond)
            *disp = *fast;
        else {
            while (curr && curr->next_path != *bond)
                curr = curr->next_path;
            mx_add_link(&curr, &(*fast));
        }
    }
    else
        swpD(&(*disp), &(*bond), &(*fast));
}

void mx_sort_path(t_path **disp, int sizeP) {
    t_path *bond = *disp;
    t_path *fast = (*disp)->next_path;

    for (int i = 0; i < sizeP; i++) {
        bond = *disp;
        fast = bond->next_path;
        for (; bond->index != i; bond = bond->next_path)
            fast = bond->next_path;

        while (fast) {
            if (cmp(bond, fast) == 1) {
                swap(&(*disp), &bond, &fast);
                for (bond = *disp; bond->index != i; bond = bond->next_path)
                    fast = bond->next_path;
            }
            else
                fast = fast->next_path;
        }
    }
}
