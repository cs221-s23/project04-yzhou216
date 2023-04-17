#include "project04.h"

float eval(struct parse_node_st *node)
{
	if (node->type == EX_INTVAL) {
		return node->intval.value;
	} else if (node->type == EX_OPER2) {
		float l = eval(node->oper2.left);
		float r = eval(node->oper2.right);
		if (node->oper2.oper == OP_PLUS)
			return l + r;
		else if (node->oper2.oper == OP_MINUS)
			return l - r;
		else if (node->oper2.oper == OP_MULT)
			return l * r;
		else if (node->oper2.oper == OP_DIV)
			return l / r;
		else if (node->oper2.oper == OP_LSHIFT)
			return (int) l << (int) r;
		else if (node->oper2.oper == OP_RSHIFT)
			return (int) l >> (int) r;
		else if (node->oper2.oper == OP_BITAND)
			return (int) l & (int) r;
		else if (node->oper2.oper == OP_BITOR)
			return (int) l | (int) r;
		else if (node->oper2.oper == OP_BITXOR)
			return (int) l ^ (int) r;
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

void eval_res_print(struct parse_node_st *node)
{
	printf("%d\n", (int) eval(node));
}