#include "project04.h"

int main(int argc, char **argv)
{
	if (argc < 3 || argc > 7)
		goto arg_err;

	char expr[SCAN_INPUT_LEN + 1];
	int base = DEFAULT_BASE;
	int width = DEFAULT_WIDTH;
	for (int i = 1; i < argc; i++) {
		if (!strncmp(argv[i], "-e", 3)) {
			if (!argv[i + 1])
				goto arg_err;
			memset(expr, 0, SCAN_INPUT_LEN + 1);
			strncpy(expr, argv[i + 1], SCAN_INPUT_LEN);
			i++;
		} else if (!strncmp(argv[i], "-b", 3)) {
			if (!argv[i + 1])
				goto arg_err;
			base = atoi(argv[i + 1]);
			i++;
		} else if (!strncmp(argv[i], "-w", 3)) {
			if (!argv[i + 1])
				goto arg_err;
			width = atoi(argv[i + 1]);
			i++;
		}
	}

	struct scan_table_st scan_table; /* table of tokens */
	struct parse_table_st parse_table; /* table of parse nodes */
	struct parse_node_st *parse_tree; /* tree (pointers only) of parse nodes */

	scan_table_init(&scan_table);
	scan_table_scan(&scan_table, expr, strnlen(expr, SCAN_INPUT_LEN));

	parse_table_init(&parse_table);
	parse_tree = parse_program(&scan_table);
	eval_res_print(parse_tree, base, width);

	return 0;

arg_err:
	printf("usage: ./lab06 -e \"expr\" -b \"base\"\n");
	printf("  example: ./lab06 -e \"1 + 2\" -b 10\n");
	exit(-1);
}
