#pragma once

#include <stack>
#include <string>
#include "Pair.hpp"

class RPN
{
public:
	RPN() {}
	~RPN();
	Pair<int, int> Calculate(const std::string& expr);

private:
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

private:
	std::stack<int> m_stack;
};