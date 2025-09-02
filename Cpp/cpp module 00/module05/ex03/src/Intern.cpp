// ************************************************************************** //
//                                                                            //
//                                 Intern.cpp                                  //
//                         42 C++ Module 05 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& /*other*/) {}
Intern& Intern::operator=(const Intern& /*other*/) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    struct Pair { const char* name; AForm* (*ctor)(const std::string&); };
    static AForm* mkShrub(const std::string& t){ return new ShrubberyCreationForm(t); }
    static AForm* mkRobo (const std::string& t){ return new RobotomyRequestForm(t); }
    static AForm* mkPard (const std::string& t){ return new PresidentialPardonForm(t); }
    const Pair table[3] = {
        { "shrubbery creation", &mkShrub },
        { "robotomy request",   &mkRobo  },
        { "presidential pardon",&mkPard  }
    };
    for (int i=0;i<3;++i) {
        if (formName == table[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return table[i].ctor(target);
        }
    }
    std::cout << "Intern: unknown form "" << formName << """ << std::endl;
    return 0;
}
