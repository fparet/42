// ************************************************************************** //
//                                                                            //
//                                AAnimal.hpp                                 //
//                         42 C++ Module 04 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
public:
    // Coplien form
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal&);
    virtual ~AAnimal();

    // Custom
    explicit AAnimal(const std::string& type);

    // Abstract interface
    virtual void makeSound() const = 0; // pure virtual
    const std::string& getType() const;

protected:
    std::string _type;
};

#endif // AANIMAL_HPP
