#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("Bender") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) { if (this != &other) { AForm::operator=(other); _target = other._target; } return *this; }
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::doExecute(Bureaucrat const & /*executor*/) const {
    std::cout << "* DRILLING NOISES *" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
