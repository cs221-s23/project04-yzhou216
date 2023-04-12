#include "lab06.h"

int main(int argc, char **argv)
{
	struct scan_table_st scan_table; /* table of tokens */
	struct parse_table_st parse_table; /* table of parse nodes */
	struct parse_node_st *parse_tree; /* tree (pointers only) of parse nodes*/

	if (argc < 3 || argc > 5)
		goto arg_err;

	char expr[SCAN_INPUT_LEN];
	int len;
	bool bflag = false;
	int base;
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-e")) {
			if (!argv[i + 1])
				goto arg_err;
			strncpy(expr, argv[i + 1], SCAN_INPUT_LEN);
		} else if (!strcmp(argv[i], "-b")) {
			if (!argv[i + 1])
				goto arg_err;
			bflag = true;
			base = atoi(argv[i + 1]);
		}
	}

	strncpy(expr, argv[2], SCAN_INPUT_LEN);
	len = strnlen(expr, SCAN_INPUT_LEN);

	scan_table_init(&scan_table);
	scan_table_scan(&scan_table, expr, len);
	/*
	 * You may uncomment this if you need to debug the scanner but leave it
	 * commented for "grade test" since scanner output is not part of the
	 * expected output for lab06 scan_table_print(&scan_table);
	 */

	parse_table_init(&parse_table);
	parse_tree = parse_program(&scan_table);
	parse_tree_print(parse_tree);

	return 0;

arg_err:
	printf("usage: ./lab06 -e \"expr\" -b \"base\"\n");
	printf("  example: ./lab06 -e \"1 + 2\" -b 10\n");
	exit(-1);
}
