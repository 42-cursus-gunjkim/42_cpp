#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

public:
	iterator begin()
	{
		return this->c.begin();
	}
	const_iterator cbegin() const
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	const_iterator cend() const
	{
		return this->c.end();
	}
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	const_reverse_iterator crbegin() const
	{
		return this->c.rbegin();
	}
	reverse_iterator rend()
	{
		return this->c.rend();
	}
	const_reverse_iterator crend() const
	{
		return this->c.rend();
	}

public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(const MutantStack& other)
	{
		std::stack<T, Container>::operator=(other);
	}
	MutantStack& operator=(const MutantStack& other)
	{
		if (this == &other)
			return *this;
		std::stack<T, Container>::operator=(other);
		return *this;
	}
};
