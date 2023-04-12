#include <math.h>
#include "lab06.h"

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
