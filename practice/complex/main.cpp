#include "Complex.hpp"

int main()
{
	 Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);
  a += b;
  a.println();
  b.println();
}