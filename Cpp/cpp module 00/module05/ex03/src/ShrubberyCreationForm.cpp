#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("home") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { if (this != &other) { AForm::operator=(other); _target = other._target; } return *this; }
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::doExecute(Bureaucrat const & /*executor*/) const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) { std::cerr << "Failed to open output file" << std::endl; return; }
    ofs << "       _-_        " << std::endl;
    ofs << "    /~~   ~~\    " << std::endl;
    ofs << " /~~         ~~\ " << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \  _-     -_  / " << std::endl;
    ofs << "   ~  \\ //  ~  " << std::endl;
    ofs << "_- -   | | _- _  " << std::endl;
    ofs << "  _ -  | |   -_  " << std::endl;
    ofs << "      // \\      " << std::endl;
    ofs.close();
}
