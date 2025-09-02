// ************************************************************************** //
//                                                                            //
//                              Bureaucrat.hpp                                 //
//                         42 C++ Module 05 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
class AForm;

class Bureaucrat {
public:
    // Coplien
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat&);
    ~Bureaucrat();

    // Custom
    explicit Bureaucrat(const std::string& name, int grade);

    const std::string& getName() const;
    int  getGrade() const;

    void incrementGrade(); // --grade (1 is highest)
    void decrementGrade(); // ++grade (150 is lowest)

    // ex02+ helper (safe to have here)
    void signForm(AForm& f);
    void executeForm(AForm const & form) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
        public: const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public: const char* what() const throw();
    };

private:
    const std::string _name;
    int _grade;

    static void checkGrade(int g);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
