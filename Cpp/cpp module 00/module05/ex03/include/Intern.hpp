// ************************************************************************** //
//                                                                            //
//                                 Intern.hpp                                  //
//                         42 C++ Module 05 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    // Coplien
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern&);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif // INTERN_HPP
