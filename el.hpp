enum arith_op{
	e_add,
	e_sub,
	e_mul,
	e_div,
	e_rem,
};

enum rel_op {
	lt,
	eq,
	gt,
};

enum logical_op {
	and_op,
	or_op,
};

enum numeric_expr_kind {
	e_int,
	e_arg,
	e_arith,
	e_if,
};

enum boolean_expr_kind {
	e_bool,
	e_rel,
	e_logic
};
struct Program;
struct NumericExpression;
struct BoolExpression;
struct IntegerLiteral;
struct ArgExpression;
struct ArithmeticExpression;
struct IfExpression;
struct BooleanExpression;
struct RelationalExpression;
struct LogicalExpression;

struct Program {
	int args;
	NumericExpression* body;

	Program(NumericExpression* n, int arg){
		args = arg;
		body = n;
	}
};

struct NumericExpression {
	numeric_expr_kind kind;

	NumericExpression(numeric_expr_kind k){
		kind = k;
	}
};
struct IntegerLiteral{
	int val;

	IntegerLiteral(int v){
		val = v;
	}
};

struct ArgExpression{
	int arg;

	ArgExpression(int args){
		arg = args;
	}
};

struct ArithmeticExpression{
	arith_op oper;
	NumericExpression* lhs;
	NumericExpression* rhs;

	ArithmeticExpression(arith_op o, NumericExpression* l, NumericExpression* r){
		oper = o;
		lhs = l;
		rhs = r;
	}
};


