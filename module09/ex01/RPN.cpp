#include "RPN.hpp"
#include <iostream>
RPN::~RPN()
{
	while (!m_stack.empty())
		m_stack.pop();
}

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

int operate(char c, int left, int right)
{
	switch (c)
	{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
	}
	return -1;
}

Pair<int, int> RPN::Calculate(const std::string& expr)
{
	Pair<int, int> err_ret(0, 1);
	std::size_t expr_len = expr.length();
	for (size_t i = 0; i < expr_len; i++)
	{
		if (isspace(expr[i]) == true)
			continue;
		if (isValidChar(expr[i]) == false)
			return err_ret;
		if (isOperator(expr[i]) == true)
		{
			int right = m_stack.top();
			m_stack.pop();
			if (m_stack.empty() == true)
				return err_ret;
			int left = m_stack.top();
			m_stack.pop();
			m_stack.push(operate(expr[i], left, right));
		}
		else
		{
			m_stack.push(expr[i] - '0');
		}
	}
	int result = m_stack.top();
	m_stack.pop();
	if (m_stack.empty() == false)
		return err_ret;
	return Pair<int, int>(result, 0);
}