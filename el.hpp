enum arith_op{
    add,
    sub,
    mul,
    div,
    rem,
};

enum rel_op {
    lt,
    eq,
    gt,
};

enum logical_op {
    and,
    or,
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
}
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
}

struct NumericExpression {
    numeric_expr_kind kind;

    NumberExpression(numeric_expr_kind k){
        kind = k;
    }

struct IntegerLiteral{
    int val;

    IntegerLiteral(int v){
        val = v;
    }
}

struct ArgExpression{
    int arg;
    
    ArgExpression(int args){
        arg = args;
    }
}

struct ArithmeticExpression{
    arith_op oper;
    NumberExpression* lhs;
    NumberExpression* rhs;

    ArithmeticExpression(arith_op o, NumberExpression* l, NumberExpression* r){
        oper = o;
        lhs = l;
        rhs = r;
    }
}


