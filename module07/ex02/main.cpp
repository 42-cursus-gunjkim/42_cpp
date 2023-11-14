#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> intArr(10);
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	
	std::cout << "intArr" << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << std::endl;
	
	Array<int> emptyArr;
	try
	{
		std::cout << "empty array's size : " << emptyArr.size() << std::endl;
		emptyArr[0] = 1;
	}
 	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	emptyArr = intArr;
	std::cout << "emptyArr" << std::endl;
	for (unsigned int i = 0; i < emptyArr.size(); i++)
		std::cout << emptyArr[i] << std::endl;

	try
	{
		int a = intArr[intArr.size()];
		std::cout << a << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "Who are you?";
	strArr[2] = "What is your name?";

	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;

	return 0;
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
// 		std::cout << numbers[i] << std::endl;
//     }
//     delete [] mirror;//
//     return 0;
// }
