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
    public:
        static void convert(std::string value);

};

#endif