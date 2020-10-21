#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	int p = 1, swaps = 0;
	while (p == 1) {
		p = 0;
		for (int i = 0; i < size - 1; i++)
			if (mx_strcmp(arr[i], arr[i + 1]) > 0) {
				char* tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				p = 1;
				swaps++;
			}
	}

	return swaps;
}
