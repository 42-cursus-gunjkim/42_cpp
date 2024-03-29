#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {

private:
    typedef void (Harl::*comment_ptr)(void);

    comment_ptr *commenters;
    std::string *levels;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();
    Harl(const Harl& h);
    Harl& operator=(const Harl& h);
    void complain(std::string level);
};

#endif