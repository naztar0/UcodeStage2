#include "libmx.h"

void mx_print_unicode(wchar_t c) {
	if (c < 128) {
		char out[1]; /* 1 bytes  */

		out[0] = (c >> 0 & 127) | 0;

		write(1, out, 1);
	} else if (c < 2048) {
		char out[2]; /* 2 bytes  */

		out[0] = (c >> 6 & 127) | 192;
		out[1] = (c >> 0 & 63) | 128;

		write(1, out, 2);
	} else if (c < 65536) {
		char out[3]; /* 3 bytes  */

		out[0] = (c >> 12 & 15) | 224;
		out[1] = (c >> 6 & 63) | 128;
		out[2] = (c >> 0 & 63) | 128;

		write(1, out, 3);
	} else if (c < 0x110000) {
		char out[4]; /* 4 bytes  */

		out[0] = (c >> 18 & 7) | 240;
		out[1] = (c >> 12 & 63) | 128;
		out[2] = (c >> 6 & 63) | 128;
		out[3] = (c >> 0 & 63) | 128;

		write(1, out, 4);
	}
}
