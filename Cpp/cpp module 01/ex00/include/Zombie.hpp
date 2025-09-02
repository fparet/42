// ************************************************************************** //
//                                                                            //
//                               Zombie.hpp                                   //
//                         42 C++ Module 01 - ex00                            //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    explicit Zombie(const std::string &name);
    ~Zombie();

    void announce() const;

private:
    std::string _name;
};

// Factory functions (as per subject)
Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif // ZOMBIE_HPP
