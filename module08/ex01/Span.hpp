#pragma once

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

private:
	Span();

private:
	int* mData;
	unsigned int mSize;
	unsigned int mCapacity;
};