#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "1 arguments is needed..." << std::endl;
        return 0;
    }

    Harl example;

    example.harl_filter(argv[1]);
}