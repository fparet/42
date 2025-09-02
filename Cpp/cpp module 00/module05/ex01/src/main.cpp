#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat low("Low", 150);
        Bureaucrat high("High", 1);
        Form f("TopSecret", 10, 20);
        std::cout << f << std::endl;

        std::cout << "Low tries to sign..." << std::endl;
        try { f.beSigned(low); } catch (std::exception& e) { std::cout << "Failed: " << e.what() << std::endl; }
        std::cout << f << std::endl;

        std::cout << "High signs..." << std::endl;
        f.beSigned(high);
        std::cout << f << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
