#include "Span.hpp"

Span::Span(unsigned int n)
	: mData(new int[n])
	, mSize(0)
	, mCapacity(n)
{}

Span::Span(const Span& other)
{

}

Span::~Span()
{

}

Span& Span::operator=(const Span& other)
{

}