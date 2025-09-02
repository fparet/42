// ************************************************************************** //
//                                                                            //
//                            ScalarConverter.hpp                              //
//                         42 C++ Module 06 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    // Non-instantiable static class, but still declare Coplien in private
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP
