// ************************************************************************** //
//                                                                            //
//                                Harl.hpp                                    //
//                         42 C++ Module 01 - ex05                            //
//                                                                            //
// ************************************************************************** //
#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
    Harl();
    ~Harl();
    void complain(const std::string &level);

private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif // HARL_HPP
