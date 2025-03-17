#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(std::string value);
};

#endif