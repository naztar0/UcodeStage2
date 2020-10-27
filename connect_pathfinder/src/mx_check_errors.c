#include "pathfinder.h"

static void print_line_error(int nline) {
    char *index = NULL;

    nline++;
    index = mx_itoa(nline);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr(" is not valid\n");
    exit(-1);
}

static void test_lines(char **lines, int nline) {
    int i = 0;
    int copy_i = 0;

    for (int n = 1; n <= nline; n++) {
        i = 0;
        copy_i = 0;

        while (mx_isalpha(lines[n][i])) 
            i++;
        if (i == 0 || lines[n][i] != '-')
            print_line_error(n);
        i++;

        copy_i = i;
        while (mx_isalpha(lines[n][copy_i])) 
            copy_i++;
        if (copy_i - i == 0 || lines[n][copy_i] != ',')
            print_line_error(n);
        copy_i++;
        i = copy_i;

        while (mx_isdigit(lines[n][copy_i]))
            copy_i++;
        if (copy_i - i == 0 || lines[n][copy_i] != '\0')
            print_line_error(n);
    }
}

static void get_error(char *file) {
    char **lines = mx_strsplit(file, '\n');
    int nline = 0;
    int at = 0;

    while (lines[nline]) 
        nline++;
    if (lines[0][0] == '0') {
        mx_printerr("error: zero is not allowed\n");
        exit(-1);
    }
    for (; lines[0][at]; at++) {
        if (!mx_isdigit(lines[0][at])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
    }
    test_lines(lines, nline - 1);
    mx_check_spaces(lines, file);
    mx_del_strarr(&lines);
}

void mx_check_errors(int argc, char **argv, char *file) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    if (!file) {
         mx_printerr("error: file ");
         mx_printerr(argv[1]);
         mx_printerr(" does not exist\n");
        exit(-1);
    }
    if (mx_strlen(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(-1);
    }
    get_error(file);
}
