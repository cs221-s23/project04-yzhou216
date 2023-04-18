#include "project04.h"

int main(int argc, char **argv)
{
	int opt;
	char expr[SCAN_INPUT_LEN + 1];
	int base = DEFAULT_BASE;
	int width = DEFAULT_WIDTH;
	while ((opt = getopt(argc, argv, "e:b:w:")) != -1) {
		switch (opt) {
			case 'e':
				memset(expr, 0, SCAN_INPUT_LEN + 1);
				strncpy(expr, optarg, SCAN_INPUT_LEN);
				break;
			case 'b':
				base = atoi(optarg);
				break;
			case 'w':
				width = atoi(optarg);
				break;
			default:
				goto arg_err;
		}
	}

	if (optind < 3 || optind > 7) {
		goto arg_err;
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
	printf("usage: %s [-e expression] [-b base] [-w width]\n", argv[0]);
	printf("  example: %s -e \"0xA + 1\" -b 2 -w 8\n", argv[0]);
	exit(-1);
}
