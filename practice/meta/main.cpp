#include <iostream>
#include <string>

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

// template parameter pack
template <typename T, typename... Types>
void print(T arg, Types... args) // function parameter pack
{
	std::cout << arg << ", ";
	print(args...);
}
// 단점 : 모든 걸 재귀호출의 형태로 만들어야 함, 재귀 base case에 대한 함수 구현도 따로 만들어주어야 함
// 장점 : 인라인 함수화 되기 때문에 성능 감소가 없다. 즉 컴파일 시간에 하나의 완전한 함수로 만들어줌

// int sumAll()
// {
// 	return 0;
// }

// template <typename... T>
// int sumAll(int num, T... args)
// {
// 	return num + sumAll(args...);
// }

// fold expression version
// fold를 쓸대에는 괄호로 감싸주기

template <typename... Ints>
int sumAll(Ints... args)
{
	return (... + args);
}

int main()
{
	std::cout << sumAll(1, 2, 3, 4, 5, 6, 7, 8) << std::endl;

	return 0;
}