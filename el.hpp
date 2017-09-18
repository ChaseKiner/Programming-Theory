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
struct BooleanLiteral;
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
struct IntegerLiteral : NumericExpression{
	int val;

	IntegerLiteral(int v) : NumericExpression(e_int){
		val = v;
	}
};

struct ArgExpression : NumericExpression{
	int arg;

	ArgExpression(int args) : NumericExpression(e_arg){
		arg = args;
	}
};

struct ArithmeticExpression : NumericExpression{
	arith_op oper;
	NumericExpression* lhs;
	NumericExpression* rhs;

	ArithmeticExpression(arith_op o, NumericExpression* l, NumericExpression* r) : NumericExpression(e_arith) {
		oper = o;
		lhs = l;
		rhs = r;
	}
};

struct ifExpression : NumericExpression{
	ifExpression(BoolExpression* c, NumericExpression* p, NumericExpression* f) : NumericExpression(e_if){
		condition = c;
		pass = p;
		fail = f;
	}
	BoolExpression* condition;
	NumericExpression* pass;
	NumericExpression* fail;
};	

struct BoolExpression{
	BoolExpression(boolean_expr_kind k){
		kind = k;
	}
	boolean_expr_kind kind;
};

struct BooleanLiteral : BoolExpression  {
	BooleanLiteral(bool b) : BoolExpression(e_bool){
		value = b;
	}
	bool value;
};

struct RelationalExpression : BoolExpression{
	RelationalExpression(rel_op oper, NumericExpression* l, NumericExpression* r) : BoolExpression(e_rel) {
		op = oper;
		lhs = l;
		rhs = r;
	}
	NumericExpression* lhs;
	NumericExpression* rhs;
	rel_op op;
};

struct LogicalExpression : BoolExpression {
	LogicalExpression(logical_op oper, BoolExpression* l, BoolExpression* r) : BoolExpression(e_logic) {
		op = oper;
		lhs = l;
		rhs = r;
	}
	logical_op op;
	BoolExpression* lhs;
	BoolExpression* rhs;
};

