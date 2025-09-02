// ************************************************************************** //
//                                                                            //
//                                 AForm.cpp                                   //
//                         42 C++ Module 05 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
AForm::AForm(const std::string& name, int gS, int gE) : _name(name), _signed(false), _gradeToSign(gS), _gradeToExecute(gE) {
    checkGrade(gS); checkGrade(gE);
}
AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
AForm& AForm::operator=(const AForm& other) { if (this != &other) _signed = other._signed; return *this; }
AForm::~AForm() {}

void AForm::checkGrade(int g) { if (g < 1) throw GradeTooHighException(); if (g > 150) throw GradeTooLowException(); }

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int  AForm::getGradeToSign() const { return _gradeToSign; }
int  AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const & b) {
    if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_signed) throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
    doExecute(executor);
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form "" << f.getName() << "" [signed=" << (f.isSigned() ? "yes" : "no")
       << ", gradeToSign=" << f.getGradeToSign() << ", gradeToExecute=" << f.getGradeToExecute() << "]";
    return os;
}
