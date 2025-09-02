// ************************************************************************** //
//                                                                            //
//                              WrongAnimal.hpp                               
//                         42 C++ Module 04 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
public:
    // Coplien form
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal&);
    ~WrongAnimal(); // intentionally non-virtual (to illustrate the issue)

    // Custom
    explicit WrongAnimal(const std::string& type);

    // Non-virtual interface (wrong)
    void makeSound() const;
    const std::string& getType() const;

protected:
    std::string _type;
};

#endif // WRONGANIMAL_HPP
