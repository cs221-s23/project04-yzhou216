#include "project04.h"

float eval(struct parse_node_st *node)
{
	if (node->type == EX_INTVAL) {
		return node->intval.value;
	} else if (node->type == EX_OPER2) {
		float l = eval(node->oper2.left);
		float r = eval(node->oper2.right);
		switch (node->oper2.oper) {
			case OP_PLUS:
				return (l + r);
			case OP_MINUS:
				return (l - r);
			case OP_MULT:
				return (l * r);
			case OP_DIV:
				return (l / r);
			case OP_LSHIFT:
				return ((int) l << (int) r);
			case OP_RSHIFT:
				return ((int) l >> (int) r);
			case OP_BITAND:
				return ((int) l & (int) r);
			case OP_BITOR:
				return ((int) l | (int) r);
			case OP_BITXOR:
				return ((int) l ^ (int) r);
		}
	} else if (node->type == EX_OPER1) {
		float operand_val = eval(node->oper1.operand);
		switch (node->oper1.oper) {
			case OP_MINUS:
				return (-1 * operand_val);
			case OP_BITNOT:
				return (~ (int) operand_val);
		}
	}
}

void eval_res_print(struct parse_node_st *node, int base, int width)
{
	char bin_str[width + 1];
	char hex_str[(width / 8) + 1];

	switch (base) {
		case 2:
			int_to_bin(bin_str, (int) eval(node), width);
			printf("0b%s\n", bin_str);
			break;
		case 10:
			printf("%d\n", (int) eval(node));
			break;
		case 16:
			int_to_hex(hex_str, (int) eval(node), width);
			printf("0x%s\n", hex_str);
			break;
	}
}
