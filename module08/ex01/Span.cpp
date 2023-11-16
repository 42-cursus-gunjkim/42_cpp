#include "Span.hpp"

Span::Span(unsigned int n)
	: mData(new int[n + 1])
	, mBegin(mData)
	, mEnd(mData + n)
	, mSize(0)
	, mCapacity(n)
{
	for (unsigned int i = 0; i < mSize; i++)
		mData[i] = 0;
}

Span::Span(const Span& other)
	: mData(new int[other.mCapacity])
	, mBegin(mData)
	, mEnd(mData + other.mCapacity)
	, mSize(other.mSize)
	, mCapacity(other.mCapacity)
{
	for (unsigned int i = 0; i < mSize; i++)
		mData[i] = other.mData[i];
}

Span::~Span()
{
	delete[] mData;
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	delete[] mData;
	mData = new int[other.mCapacity];
	mBegin = mData;
	mEnd = mData + other.mCapacity;
	mSize = other.mSize;
	for (unsigned int i = 0; i < mSize; i++)
		mData[i] = other.mData[i];
	return *this;
}

int& Span::operator[](unsigned int index)
{
	if (index >= mSize)
		throw std::runtime_error("Span::Invalid index...");
	return mData[index];
}

void Span::addNumber(int num)
{
	if (mSize >= mCapacity)
		throw std::runtime_error("Span::Full");
	mData[mSize] = num;
	mSize++;
}

Span::iterator Span::begin()
{
	return mBegin;
}


Span::iterator Span::end()
{
	return mEnd;
}

Span::const_iterator Span::cbegin() const
{
	return mBegin;
}

Span::const_iterator Span::cend() const
{
	return mEnd;
}

int Span::shortestSpan() const
{
	Span tmp = *this;
	Span diff(mSize);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), diff.begin());
	return *(std::min_element(diff.begin(), diff.end()));
}

int Span::longestSpan() const
{
	int min = *(std::min_element(mBegin, mEnd));
	int max = *(std::max_element(mBegin, mEnd));

	return max - min;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
	Span::const_iterator begin = span.cbegin();
	Span::const_iterator end = span.cend();

	os << "Span : [ ";
	for (Span::const_iterator iter = begin; iter != end; iter++)
	{
		os << *iter << " ";
	}
	os << "]";
	return os;
}