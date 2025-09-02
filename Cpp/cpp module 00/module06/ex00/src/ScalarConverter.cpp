// ************************************************************************** //
//                                                                            //
//                            ScalarConverter.cpp                              //
//                         42 C++ Module 06 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>

namespace {
    bool isPseudo(const std::string& s) {
        return s == "nan" || s == "+inf" || s == "-inf" || s == "inf"
            || s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
    }
    bool isFloatLiteral(const std::string& s) {
        if (s.size() >= 2 && s[s.size()-1] == 'f') {
            std::string core = s.substr(0, s.size()-1);
            bool dot = false;
            if (core.size() == 0) return false;
            size_t i = 0;
            if (core[0] == '+' || core[0] == '-') i = 1;
            bool any = false;
            for (; i < core.size(); ++i) {
                if (core[i] == '.') { if (dot) return false; dot = true; }
                else if (std::isdigit(static_cast<unsigned char>(core[i]))) { any = true; }
                else return false;
            }
            return any;
        }
        return false;
    }
    bool isDoubleLiteral(const std::string& s) {
        bool dot = false;
        if (s.size() == 0) return false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-') i = 1;
        bool any = false;
        for (; i < s.size(); ++i) {
            if (s[i] == '.') { if (dot) return false; dot = true; }
            else if (std::isdigit(static_cast<unsigned char>(s[i]))) { any = true; }
            else return false;
        }
        return dot && any;
    }
    bool isIntLiteral(const std::string& s) {
        if (s.size() == 0) return false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-') i = 1;
        if (i == s.size()) return false;
        for (; i < s.size(); ++i)
            if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
        return true;
    }
    void printChar(double d) {
        std::cout << "char: ";
        if (std::isnan(d) || d < 0 || d > 127) {
            std::cout << "impossible" << std::endl; return;
        }
        unsigned char c = static_cast<unsigned char>(static_cast<int>(d));
        if (!std::isprint(c)) {
            std::cout << "Non displayable" << std::endl; return;
        }
        std::cout << "'" << c << "'" << std::endl;
    }
    void printInt(double d) {
        std::cout << "int: ";
        if (std::isnan(d) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)) {
            std::cout << "impossible" << std::endl; return;
        }
        std::cout << static_cast<int>(d) << std::endl;
    }
    void printFloat(double d) {
        std::cout.setf(std::ios::fixed);
        std::cout.precision((std::floor(std::fabs(d)) == std::fabs(d) && !std::isnan(d) && !std::isinf(d)) ? 1 : 6);
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
    void printDouble(double d) {
        std::cout.setf(std::ios::fixed);
        std::cout.precision((std::floor(std::fabs(d)) == std::fabs(d) && !std::isnan(d) && !std::isinf(d)) ? 1 : 6);
        std::cout << "double: " << d << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& lit) {
    // Pseudo literals
    if (isPseudo(lit)) {
        bool f = (lit.size() && lit[lit.size()-1] == 'f');
        std::string core = lit;
        if (f) core = lit.substr(0, lit.size()-1);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << core << "f" << std::endl;
        std::cout << "double: " << core << std::endl;
        return;
    }

    // Single char (non-digit)
    if (lit.size() == 1 && !std::isdigit(static_cast<unsigned char>(lit[0]))) {
        unsigned char c = static_cast<unsigned char>(lit[0]);
        double d = static_cast<double>(c);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    char* end = 0;
    double d = 0.0;
    if (isIntLiteral(lit)) {
        long l = std::strtol(lit.c_str(), &end, 10);
        d = static_cast<double>(l);
    } else if (isFloatLiteral(lit)) {
        d = std::strtod(lit.c_str(), &end);
    } else if (isDoubleLiteral(lit)) {
        d = std::strtod(lit.c_str(), &end);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    (void)end; // parsed successfully per checks
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}
