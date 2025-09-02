#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm&);
    ~RobotomyRequestForm();

protected:
    void doExecute(Bureaucrat const & executor) const;

private:
    std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
