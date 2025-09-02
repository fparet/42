#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) { checkGrade(_grade); }
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { if (this != &other) _grade = other._grade; return *this; }
Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }
int  Bureaucrat::getGrade() const { return _grade; }
void Bureaucrat::checkGrade(int g) { if (g < 1) throw GradeTooHighException(); if (g > 150) throw GradeTooLowException(); }
void Bureaucrat::incrementGrade() { checkGrade(_grade - 1); --_grade; }
void Bureaucrat::decrementGrade() { checkGrade(_grade + 1); ++_grade; }
const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

void Bureaucrat::signForm(AForm& /*f*/) {}
void Bureaucrat::executeForm(AForm const & /*form*/) const {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) { os << b.getName() << ", bureaucrat grade " << b.getGrade(); return os; }
