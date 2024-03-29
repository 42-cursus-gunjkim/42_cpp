#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    this->commenters = new comment_ptr[4];
    this->levels = new std::string[4];

    this->commenters[0] = &Harl::debug;
    this->commenters[1] = &Harl::info;
    this->commenters[2] = &Harl::warning;
    this->commenters[3] = &Harl::error;

    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
}

Harl::~Harl() {
    delete[] this->commenters;
    delete[] this->levels;
}

Harl::Harl(const Harl& h) {
    this->commenters = new comment_ptr[4];
    this->levels = new std::string[4];

    this->commenters[0] = h.commenters[0];
    this->commenters[1] = h.commenters[1];
    this->commenters[2] = h.commenters[2];
    this->commenters[3] = h.commenters[3];

    this->levels[0] = h.levels[0];
    this->levels[1] = h.levels[1];
    this->levels[2] = h.levels[2];
    this->levels[3] = h.levels[3];
}

Harl& Harl::operator=(const Harl& h) {
    this->commenters[0] = h.commenters[0];
    this->commenters[1] = h.commenters[1];
    this->commenters[2] = h.commenters[2];
    this->commenters[3] = h.commenters[3];

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

void Harl::complain(std::string level) {
    int target_idx = -1;

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            target_idx = i;
            break;
        }
    }
    if (target_idx == -1) {
        std::cout << "There is no match..." << std::endl;
        return;
    }
    (this->*commenters[target_idx])();
}
