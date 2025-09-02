// ************************************************************************** //
//                                                                            //
//                             HI THIS IS BRAIN                                //
//                         42 C++ Module 01 - ex02                            //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>

static void print_header(const std::string& title) {
    std::cout << "---------------- " << title << " ----------------" << std::endl;
}

int main() {
    std::string     stringVAR = "HI THIS IS BRAIN";
    std::string*    stringPTR = &stringVAR;
    std::string&    stringREF = stringVAR;

    print_header("ADDRESSES");
    std::cout << "Address of stringVAR : " << &stringVAR << std::endl;
    std::cout << "Address in stringPTR : " << stringPTR << std::endl;
    std::cout << "Address of stringREF : " << &stringREF << std::endl;

    print_header("VALUES");
    std::cout << "Value of stringVAR   : " << stringVAR << std::endl;
    std::cout << "Value pointed by PTR : " << *stringPTR << std::endl;
    std::cout << "Value via REF        : " << stringREF << std::endl;

    // Demonstrate that modifying via reference/pointer affects the same object
    print_header("MODIFY THROUGH PTR/REF");
    *stringPTR = "BRAIN THROUGH PTR";
    std::cout << "After *stringPTR=...  | stringVAR: " << stringVAR << " | stringREF: " << stringREF << std::endl;
    stringREF = "BRAIN THROUGH REF";
    std::cout << "After stringREF=...   | stringVAR: " << stringVAR << " | *stringPTR: " << *stringPTR << std::endl;

    return 0;
}
