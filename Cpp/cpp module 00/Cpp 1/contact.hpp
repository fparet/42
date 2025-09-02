// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setInfo(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
    void displayShort(int index) const;
    void displayFull() const;
};

#endif
