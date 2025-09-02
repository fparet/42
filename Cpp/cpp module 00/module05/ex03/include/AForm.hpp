// ************************************************************************** //
//                                                                            //
//                                 AForm.hpp                                   //
//                         42 C++ Module 05 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
public:
    // Coplien
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm&);
    virtual ~AForm();

    // Custom
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);

    const std::string& getName() const;
    bool isSigned() const;
    int  getGradeToSign() const;
    int  getGradeToExecute() const;

    void beSigned(Bureaucrat const & b);
    void execute(Bureaucrat const & executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
    class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };
    class FormNotSignedException: public std::exception { public: const char* what() const throw(); };

protected:
    virtual void doExecute(Bureaucrat const & executor) const = 0;

private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    static void checkGrade(int g);
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
