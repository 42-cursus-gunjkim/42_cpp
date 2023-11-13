#pragma once

#include <exception>

#define DEFAULT_ARR_SIZE 10

template <typename T>
class Array
{
public:
	Array()
		: mData(new T[DEFAULT_ARR_SIZE])
		, mSize(DEFAULT_ARR_SIZE)
	{}

	Array(unsigned int n)
		: mData(new T[n])
		, mSize(n)
	{
		//for (int i = 0; i < static_cast<int>(n); i++)
		//	mData[i] = 0;
		// 각 타입마다의 초기화 코드는 어떻게 작성하지...?
	}

	Array(const Array<T>& other)
	{
		mData = new T[other.mSize];
		for (int i = 0; i < other.mSize; i++)
		{
			mData[i] = other.mData[i];
		}
		mSize = other.mSize;
	}

	Array& operator=(const Array& other)
	{
		if (*this == other)
			return *this;
		delete[] mData;
		mData = new T[other.mSize];
		for (int i = 0; i < other.mSize; i++)
		{
			mData[i] = other.mData[i];
		}
		mSize = other.mSize;
	}

	T& operator[](int n)
	{
		if (n < 0 || n >= mSize)
			throw std::exception();
		return mData[n];
	}

	int size()
	{
		return mSize;
	}

	~Array()
	{
		delete[] mData;
	}

private:
	T* mData;
	int mSize;
};
