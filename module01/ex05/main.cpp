#include "Harl.hpp"

int main()
{
    Harl example;

    example.complain("DEBUG");
    example.complain("INFO");
    example.complain("WARNING");
    example.complain("ERROR");
    example.complain("WHATEVER");
}