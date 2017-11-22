#pragma once

enum expr_type{
	ref,
	abs,
	app,
};

//a variable is a variable in an abstraction or a lambda expression 
struct Variable {
	// Abstraction does not need an index
	Variable(const std::string& n, int l)
	       : name(n), level(l)
	{}
	// Variable for Lambda Expression
	Variable(const std::string& n, int l, int n)
		: name(n), level(l), index(n)
	{}
	
	std::string name;
	int level;
	int index;
};

struct Expr {
	Expr(expr_type t)
		: type(t)
	{}
	expr_type type;
}

struct Abstraction : Expr {
	Abstraction(Variable* v, Expr* e)
		: Expr(abs), param(v), body(e)
	{}
	Variable* param;
	Expr* body;
};
