#pragma once

template <typename T, typename U>
class Pair
{
public:
	Pair(T first, U second)
	{
		m_first = first;
		m_second = second;
	}
	Pair(const Pair& other)
	{
		m_first = other.m_first;
		m_second = other.m_second;
	}
	~Pair() {}
	Pair& operator=(const Pair& other)
	{
		if (this == &other)
			return *this;
		m_first = other.m_first;
		m_second = other.m_second;
	}

	T First() { return m_first; }
	U Second() { return  m_second; }

private:
	T m_first;
	U m_second;
};