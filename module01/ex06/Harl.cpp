#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    this->levels = new std::string[4];

    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
}

Harl::~Harl() {
    delete[] this->levels;
}

Harl::Harl(const Harl& h) {
    this->levels = new std::string[4];

    this->levels[0] = h.levels[0];
    this->levels[1] = h.levels[1];
    this->levels[2] = h.levels[2];
    this->levels[3] = h.levels[3];
}

Harl& Harl::operator=(const Harl& h) {
    this->levels[0] = h.levels[0];
    this->levels[1] = h.levels[1];
    this->levels[2] = h.levels[2];
    this->levels[3] = h.levels[3];

    return *this;
}

void Harl::debug() {
    std::cout
        << "[DEBUG]" << std::endl
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
        << "I really do!" << std::endl;
}

void Harl::info() {
    std::cout 
        << "[INFO]" << std::endl
        << "I cannot believe adding extra bacon costs more money." << std::endl
        << "You didn't put enough bacon in my burger!" << std::endl
        << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout
        << "[WARNING]" << std::endl
        << "I think I deserve to have some extra bacon for free." << std::endl
        << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout
        << "[ERROR]" << std::endl
        << "This is unaccpetable!" << std::endl
        << "I want to speak to the manager now." << std::endl;
}

void Harl::exception() {
    std::cout
        << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::harl_filter(std::string level) {
    int target_idx = -1;

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            target_idx = i;
            break;
        }
    }
    
    switch(target_idx) {
        case -1:
            exception();
            break;
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
    }
}