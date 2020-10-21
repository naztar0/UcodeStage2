void mx_printchar(char);

void mx_print_alphabet(void) {
	for (short i = 0; i <= 25; i++) {
		char c;
		if (i % 2 == 0) c = (char)i + 65;
		else c = (char)i + 97;
		mx_printchar(c);
	}
	mx_printchar('\n');
}
