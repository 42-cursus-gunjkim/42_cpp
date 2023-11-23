#include "RPN.hpp"
#include <iostream>

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool isValidChar(char c)
{
	if (isOperator(c) == true || (c >= '0' || c <= '9'))
		return true;
	return false;
}

Pair<int, int> RPN::Calculate(const std::string& expr)
{
	std::stack<int> stack;
	std::size_t expr_len = expr.length();
	for (size_t i = 0; i < expr_len; i++)
	{
		if (isspace(expr[i]) == true)
			continue;
		if (isValidChar(expr[i]) == false)
			return Pair<int, int>(0, CAL_FAILURE);
		if (isOperator(expr[i]) == true)
		{
			if (stack.size() < 2)
				return Pair<int, int>(0, CAL_FAILURE);
			int right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();
			switch (expr[i])
			{
				case '+':
					stack.push(left + right);
					break;
				case '-':
					stack.push(left - right);
					break;
				case '*':
					stack.push(left * right);
					break;
				case '/':
					stack.push(left / right);
					break;
				default:
					return Pair<int, int>(0, CAL_FAILURE);
					break;
			}
		}
		else
		{
			stack.push(expr[i] - '0');
		}
	}
	if (stack.size() != 1)
		return Pair<int, int>(0, CAL_FAILURE);
	int result = stack.top();
	stack.pop();
	return Pair<int, int>(result, CAL_SUCCESS);
}