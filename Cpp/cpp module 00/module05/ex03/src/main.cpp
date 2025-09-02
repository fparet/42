#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* unknown = someRandomIntern.makeForm("unknown form", "target");
    if (unknown) delete unknown;

    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (shrub) {
        Bureaucrat mid("Mid", 137);
        mid.signForm(*shrub);
        Bureaucrat exec("Exec", 5);
        exec.executeForm(*shrub);
        delete shrub;
    }

    return 0;
}
