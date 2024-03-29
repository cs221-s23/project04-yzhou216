#include "project04.h"

int string_to_int(char *str, int base)
{
	int sum = 0;

	if (str == NULL) {
		printf("invalid string\n");
		exit(-1);
	}

	for (int i = 0; i < strlen(str); i++) {
		int digit;
		if (str[i] >= '0' && str[i] <= '9') {
			digit = str[i] - '0';
		} else if (str[i] >= 'a' && str[i] <= 'f') {
			digit = str[i] - 'a' + 10;
		} else if (str[i] >= 'A' && str[i] <= 'F') {
			digit = str[i] - 'A' + 10;
		} else {
			printf("invalid character\n");
			exit(-1);
		}

		if (digit >= base) {
			printf("invalid character\n");
			exit(-1);
		}

		sum += digit * pow(base, strlen(str) - i - 1);
	}

	return sum;
}

void int_to_bin(char *bin_str, int num, int width)
{
	memset(bin_str, 0, strlen(bin_str));
	for (int i = width - 1; i >= 0; i--) {
		int j = num >> i;
		if (j & 1)
			*(bin_str++) = '1';
		else
			*(bin_str++) = '0';
	}
	*bin_str = '\0';
}

void int_to_hex(char *hex_str, int num, int width)
{
	memset(hex_str, 0, strlen(hex_str));
	for (int i = width - 4; i >= 0; i -= 4) {
		int j = (num >> i) & 0xF;
		if (j <= 9)
			*(hex_str++) = '0' + j;
		else
			*(hex_str++) = 'A' + (j - 10);
	}
	*hex_str = '\0';
}
