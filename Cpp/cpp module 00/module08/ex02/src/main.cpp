// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                         42 C++ Module 08 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "iterate forward: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "iterate const reverse: ";
    const MutantStack<int>& cref = mstack;
    for (MutantStack<int>::const_reverse_iterator rit = cref.rbegin(); rit != cref.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // Compatibility with std::stack
    std::stack<int> s(mstack);
    std::cout << "std::stack top from mutant copy: " << s.top() << std::endl;

    // Compare with std::list behavior (subject parity)
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::cout << "list forward: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
