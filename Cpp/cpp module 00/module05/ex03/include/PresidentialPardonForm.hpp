#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    ~PresidentialPardonForm();

protected:
    void doExecute(Bureaucrat const & executor) const;

private:
    std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP
