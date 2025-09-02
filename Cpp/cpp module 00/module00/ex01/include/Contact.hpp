// ************************************************************************** //
//                                                                            //
//                               Contact.hpp                                   //
//                          42 C++ Module 00 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    // Coplien
    Contact();
    Contact(const Contact& other);
    Contact& operator=(const Contact&);
    ~Contact();

    // Setters
    void setFirstName(const std::string& s);
    void setLastName(const std::string& s);
    void setNickname(const std::string& s);
    void setPhoneNumber(const std::string& s);
    void setDarkestSecret(const std::string& s);

    // Getters
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;

    bool isEmpty() const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif // CONTACT_HPP
