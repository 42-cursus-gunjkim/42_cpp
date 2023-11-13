#include <cctype>

template <typename T, typename Func>
void iter(T* array, size_t length, Func function) {
	for (size_t i = 0; i < length; ++i) {
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
