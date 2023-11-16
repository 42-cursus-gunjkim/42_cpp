#pragma once

#include <algorithm>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <iostream>

class Span
{
public:
	typedef int* iterator;
	typedef const int* const_iterator;

public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);
	int& operator[](unsigned int index);
	void addNumber(int num);
	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;
	int shortestSpan() const;
	int longestSpan() const;

	template <typename iterator>
	void addRange(iterator begin, iterator end)
	{
		if (end - begin > mCapacity - mSize)
			throw std::runtime_error("Span::Full!");
		for (iterator iter = begin; iter != end; iter++)
		{
			mData[mSize] = *iter;
			mSize++;
		}
	}

private:
	Span();

private:
	int* mData;
	iterator mBegin;
	iterator mEnd;
	unsigned int mSize;
	unsigned int mCapacity;
};

std::ostream& operator<<(std::ostream& out, const Span& span);
