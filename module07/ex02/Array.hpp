#pragma once

#include <exception>

template <typename T>
class Array
{
public:
	Array()
		: mData(NULL)
		, mSize(0)
	{}

	Array(unsigned int n)
		: mData(new T[n])
		, mSize(n)
	{}

	Array(const Array<T>& other)
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

	Array& operator=(const Array& other)
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

	T& operator[](const unsigned int n)
	{
		if (n >= mSize)
			throw std::exception();
		return mData[n];
	}

	const T& operator[](const unsigned int n) const
	{
		if (n >= mSize)
			throw std::exception();
		return mData[n];
	}

	unsigned int size() const
	{
		return mSize;
	}

	~Array()
	{
		if (mData != NULL)
			delete[] mData;
	}

private:
	T* mData;
	unsigned int mSize;
};
