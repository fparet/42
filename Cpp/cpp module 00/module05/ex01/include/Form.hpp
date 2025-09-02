// ************************************************************************** //
//                                                                            //
//                                  Form.hpp                                   //
//                         42 C++ Module 05 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class Form {
public:
    // Coplien
    Form();
    Form(const Form& other);
    Form& operator=(const Form&);
    ~Form();

    // Custom
    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    const std::string& getName() const;
    bool isSigned() const;
    int  getGradeToSign() const;
    int  getGradeToExecute() const;

    void beSigned(Bureaucrat const & b);

    class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
    class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };

private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    static void checkGrade(int g);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
