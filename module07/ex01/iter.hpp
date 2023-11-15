#include <cctype>

template <typename T, typename Func>
void iter(T const array, const size_t len, Func const function) {
	for (size_t i = 0; i < len; ++i) {
		function(array[i]);
	}
}

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void multipleTwice(T& element)
{
	element = element * 2;
}
