/*
While the C++ runtime does not have a feature analogous to pattern matching in a
language from the ML family, the C++ constexpr interpreter and template systems can
perform pattern matching computations. Each node type derives from a base class which
can be used to check a how to process each individual node.

This Gist expresses ML like pattern matching: where a standalone function is used
to evaluate the expression. However, with C++ templates and constexpr, the evaluation
function for the expression can be embedded within the type. Where every node type
has a static member function eval that performs its step of the expression. See the
link below for SQL WHERE predicate nodes implementing this pattern:
https://github.com/mkitzan/metaprogramming-optimization/blob/master/include/sql/predicate.hpp 

clang -std=c++17 -lstdc++ -o pm pattern_matching.cpp
g++ -std=c++17 -o pm pattern_matching.cpp

For reference this is the SML code implemented in C++17:
	datatype expr =
			Constant of int
		|	Negate of expr
		|	Add of expr * expr
		|	Multiply of expr * expr

	fun eval e =
		case e of
			Constant(value) => value
		|	Negate(subexpr) => ~(eval(subexpr))
		| 	Add(left,right) => eval(left) + eval(right)
		|	Multiply(left,right) => eval(left) * eval(right)

	eval(Add(Negate(Constant(10)), Multiply(Constant(2), Constant(26))))
*/

#include <iostream>

struct constant
{};
template <int Value>
struct Constant : constant
{
	static constexpr int value{ Value };
};

struct negate
{};
template <typename Subexpr>
struct Negate : negate
{
	using subexpr = Subexpr;
};

struct add
{};
template <typename Left, typename Right>
struct Add : add
{
	using left = Left;
	using right = Right;
};

struct multiply
{};
template <typename Left, typename Right>
struct Multiply : multiply
{
	using left = Left;
	using right = Right;
};

template <typename Expr>
int constexpr eval()
{
	if constexpr (std::is_base_of_v<negate, Expr>)
	{
		return -eval<typename Expr::subexpr>();
	}
	else if constexpr (std::is_base_of_v<add, Expr>)
	{
		return eval<typename Expr::left>() + eval<typename Expr::right>();
	}
	else if constexpr (std::is_base_of_v<multiply, Expr>)
	{
		return eval<typename Expr::left>() * eval<typename Expr::right>();
	}
	else
	{
		return Expr::value;
	}
}

int main()
{
	using Expression = Add<Negate<Constant<10>>, Multiply<Constant<2>, Constant<26>>>;
	constexpr int result{ eval<Expression>() };
	
	std::cout << result << '\n';
}
