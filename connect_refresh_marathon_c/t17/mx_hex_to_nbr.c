#include <stdbool.h>

bool mx_isdigit(int c) {
    return c >= 48 && c <= 57;
}

bool mx_islower(int c) {
    return c >= 97 && c <= 122;
}

bool mx_isupper(int c) {
    return c >= 65 && c <= 90;
}

static int mx_strlen(const char *s) {
	int count = 0;
	while (*s != 0) {
		count++;
		++s;
	}
	return count;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long base = 1;
    unsigned long result = 0;

    if (!hex)
        return 0;
    for (int i = mx_strlen(hex) - 1; i >= 0; i--) {
        if (mx_isdigit(hex[i])) {
            result += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (mx_isupper(hex[i])) {
            result += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (mx_islower(hex[i])) {
            result += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return result;
}
