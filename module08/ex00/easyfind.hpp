#pragma once

#include <exception>
#include <algorithm>

namespace ft
{
	template <typename T>
	typename T::iterator easyfind(T& container, int i)
	{
		typename T::iterator first = container.begin();
		typename T::iterator last = container.end();
		typename T::iterator ret = std::find(first, last, i);
		return ret;
	}
}
