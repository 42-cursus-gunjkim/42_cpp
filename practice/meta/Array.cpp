#include <iostream>

template <typename T, unsigned int N>
class Array
{
public:
	Array(T (&arr)[N]) {
    	for (int i = 0; i < N; i++)
      		mData[i] = arr[i];
  	}

	unsigned int getSize() { return N; }

	void printAll()
	{
		std::cout << "Array : [ ";
		for (unsigned int i = 0; i < N; i++)
			std::cout << mData[i] << " ";
		std::cout << "]\n";
	}

private:
	T mData[N];
};

template <int N>
struct Int {
	static const int num = N;
};

template <typename T, typename U>
struct add {
	typedef Int<T::num + U::num> result;
};

typedef Int<1> one;
typedef Int<2> two;
typedef add<one, two>::result three;

int main() {
	std::cout << "Addition result : " << three::num << std::endl;
}
