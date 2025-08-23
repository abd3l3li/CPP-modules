#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cctype>


class ScalarConverter 
{
    public:
        static void convert(const std::string& literal);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
};

bool checkPseudoLiteral(const std::string& str);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

void printPseudoLiteral(const std::string& literal);
void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);
