// ************************************************************************** //
//                                                                            //
//                                  Form.cpp                                   //
//                         42 C++ Module 05 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
Form::Form(const std::string& name, int gS, int gE) : _name(name), _signed(false), _gradeToSign(gS), _gradeToExecute(gE) {
    checkGrade(gS); checkGrade(gE);
}
Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
Form& Form::operator=(const Form& other) { if (this != &other) _signed = other._signed; return *this; }
Form::~Form() {}

void Form::checkGrade(int g) { if (g < 1) throw GradeTooHighException(); if (g > 150) throw GradeTooLowException(); }

const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int  Form::getGradeToSign() const { return _gradeToSign; }
int  Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat const & b) {
    if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form "" << f.getName() << "" [signed=" << (f.isSigned() ? "yes" : "no")
       << ", gradeToSign=" << f.getGradeToSign() << ", gradeToExecute=" << f.getGradeToExecute() << "]";
    return os;
}
