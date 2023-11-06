#include "CharConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"
#include "DoubleConverter.hpp"

int main(int argc, char* argv[])
{
	double a = -214748123123123;

	CharConverter::convert(a);
	IntConverter::convert(a);
	FloatConverter::convert(a);
	DoubleConverter::convert(a);

	return 0;
}
