// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                         42 C++ Module 08 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << std::endl;

        // Range add
        std::vector<int> more;
        for (int i = 0; i < 10; ++i) more.push_back(i * i);
        Span big(20);
        big.addNumber(more.begin(), more.end());
        std::cout << "big.size() = " << big.size() << " / capacity " << big.capacity() << std::endl;
        std::cout << "big shortest = " << big.shortestSpan() << " ; longest = " << big.longestSpan() << std::endl;

        // Overflow test
        try {
            big.addNumber(more.begin(), more.end()); // should overflow
        } catch (std::exception& e) {
            std::cout << "Expected overflow: " << e.what() << std::endl;
        }

        // Not enough numbers
        Span tiny(1);
        tiny.addNumber(42);
        try { tiny.shortestSpan(); } catch (std::exception& e) { std::cout << "Expected error: " << e.what() << std::endl; }

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
