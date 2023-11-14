#include "Array.hpp"

template <typename T>
Array<T>::Array()
	: mData(NULL)
	, mSize(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: mData(new T[n])
	, mSize(n)
{}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	if (other.mData == NULL)
	{
		mData = NULL;
		mSize = 0;
		return ;
	}

	mData = new T[other.mSize];
	for (unsigned int i = 0; i < other.mSize; i++)
	{
		mData[i] = other.mData[i];
	}
	mSize = other.mSize;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return *this;
	if (mData != NULL)
		delete[] mData;
	if (other.mData == NULL)
	{
		mData = NULL;
		mSize = 0;
		return *this;
	}

	mData = new T[other.mSize];
	for (unsigned int i = 0; i < other.mSize; i++)
	{
		mData[i] = other.mData[i];
	}
	mSize = other.mSize;
	return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int n)
{
	if (n >= mSize)
		throw std::exception();
	return mData[n];
}

template <typename T>
const T& Array<T>::operator[](const unsigned int n) const
{
	if (n >= mSize)
		throw std::exception();
	return mData[n];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return mSize;
}

template <typename T>
Array<T>::~Array()
{
	if (mData != NULL)
		delete[] mData;
}