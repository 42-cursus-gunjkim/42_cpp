#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {

private:
    std::string *levels;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void exception(void);

public:
    Harl();
    ~Harl();
    Harl(const Harl& h);
    Harl& operator=(const Harl& h);
    void harl_filter(std::string level);
};

#endif