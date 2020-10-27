#include "pathfinder.h"

static void count_err(int count, char *island_count) {
    if (count == 0 || count != mx_atoi(island_count) || count == 1) {
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
}

static int count_set(char **arr, char *island_count) {
    int count = 0;
    int j = 0;

    if (arr && *arr) {
        if (arr[0])
            count++;
        for (int i = 1; arr[i] != NULL; i++) {
            if (mx_isdigit(arr[i][0])) 
                i++;
            if (arr[i] == NULL) 
                break;
            for (j = i - 1; j >= 0; j--) {
                if (mx_strcmp(arr[i], arr[j]) == 0) 
                    break;
                if (j == 0) 
                    count++;
            }
        }
    }
    count_err(count, island_count);
    return count;
}

static int crflag(char *arr, char **set1) {
    int j = 0;
    int flag = 0;

    while (set1[j]) {
        if (mx_strcmp(arr, set1[j]) == 0) {
            flag++;
            break;
        }
        j++;
    }
    return flag;
}


static void crset(char ***set, char ***p) {
    char **arr = *p;
    char **set1 = *set;
    int i = 0;

    for (int flag = 0; *arr; flag = 0) {
        if (mx_isdigit(**arr))
            arr++;
        if (*arr) {
            flag = crflag(*arr, set1);
            if (flag != 0) {
                arr++;
                continue;
            }
            if (flag == 0) {
                set1[i] = mx_strdup(*arr);
                set1[i + 1] = NULL;
                i++;
            }
            arr++;
        }
    }
}

void mx_create_set(char ***set, char ***p, char *island_count) {
    int count = count_set(*p, island_count);
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    crset(&(*set), &(*p));
}
