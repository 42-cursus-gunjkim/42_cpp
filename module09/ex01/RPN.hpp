#pragma once

#include <stack>
#include <string>
#include "Pair.hpp"

# define CAL_SUCCESS 0
# define CAL_FAILURE 1

class RPN
{
public:
	static Pair<int, int> Calculate(const std::string& expr);

private:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
};