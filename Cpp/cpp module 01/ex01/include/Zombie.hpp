// ************************************************************************** //
//                                                                            //
//                               Zombie.hpp                                   //
//                         42 C++ Module 01 - ex01                            //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    explicit Zombie(const std::string &name);
    ~Zombie();

    void        announce() const;
    void        setName(const std::string &name);

private:
    std::string _name;
};

Zombie* zombieHorde(int N, const std::string &name);

#endif // ZOMBIE_HPP
