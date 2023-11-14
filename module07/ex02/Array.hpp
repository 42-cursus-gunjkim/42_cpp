#pragma once

#include <exception>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& other);
	~Array();

	Array& operator=(const Array& other);
	T& operator[](const unsigned int n);
	const T& operator[](const unsigned int n) const;

	unsigned int size() const;

private:
	T* mData;
	unsigned int mSize;
};

#include "Array.tpp"
