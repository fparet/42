// ************************************************************************** //
//                                                                            //
//                                Brain.hpp                                   //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
    // Coplien form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain&);
    ~Brain();

    // Accessors
    const std::string& getIdea(int idx) const;
    void setIdea(int idx, const std::string& idea);

private:
    std::string _ideas[100];
};

#endif // BRAIN_HPP
