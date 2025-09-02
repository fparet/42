#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);
    Bureaucrat low("Low", 140);

    ShrubberyCreationForm s("garden");
    RobotomyRequestForm   r("Bender");
    PresidentialPardonForm p("Ford Prefect");

    std::cout << s << std::endl << r << std::endl << p << std::endl;

    // sign & execute with appropriate grades
    boss.signForm(s);
    boss.executeForm(s);

    mid.signForm(r);
    mid.executeForm(r); // should fail execution grade
    boss.executeForm(r); // boss executes

    low.signForm(p); // fail to sign
    boss.signForm(p);
    boss.executeForm(p);

    return 0;
}
