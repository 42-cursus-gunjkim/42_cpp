#pragma once

namespace ft
{
	template <typename T>
	void swap(T& t1, T& t2)
	{
		T tmp = t2;
		t2 = t1;
		t1 = tmp;
	}

	template <typename T>
	const T& min(const T& t1, const T& t2)
	{
		return t1 < t2 ? t1 : t2;
	}

	template <typename T>
	const T& max(const T& t1, const T& t2)
	{
		return t1 > t2 ? t1 : t2;
	}
}
