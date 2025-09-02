// ************************************************************************** //
//                                                                            //
//                                 Megaphone                                   //
//                          42 C++ Module 00 - ex00                           //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        for (size_t j = 0; j < s.size(); ++j) {
            unsigned char c = static_cast<unsigned char>(s[j]);
            std::cout << static_cast<char>(std::toupper(c));
        }
    }
    std::cout << std::endl;
    return 0;
}
