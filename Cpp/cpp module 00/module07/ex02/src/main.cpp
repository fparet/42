// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                         42 C++ Module 07 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    // Empty
    Array<int> a0;
    std::cout << "a0.size() = " << a0.size() << std::endl;

    // Sized
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i) a[i] = static_cast<int>(i * 10);
    for (unsigned int i = 0; i < a.size(); ++i) std::cout << a[i] << " ";
    std::cout << std::endl;

    // Copy
    Array<int> b = a; // copy ctor
    b[0] = 999;
    std::cout << "a[0]=" << a[0] << " b[0]=" << b[0] << std::endl;

    // Assign
    Array<std::string> s1(3);
    s1[0] = "hello"; s1[1] = "module"; s1[2] = "07";
    Array<std::string> s2;
    s2 = s1;
    for (unsigned int i = 0; i < s2.size(); ++i) std::cout << s2[i] << " ";
    std::cout << std::endl;

    // Bounds check
    try {
        std::cout << a[42] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Const access
    const Array<int> ca = a;
    std::cout << "const access ca[1]=" << ca[1] << std::endl;

    return 0;
}
