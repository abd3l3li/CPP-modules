#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(const std::string& literal)
{

    if (checkPseudoLiteral(literal))
        return printPseudoLiteral(literal);

    if (!literal.empty() && std::isprint(literal[0]))
    {
            if (literal.size() == 1 && !std::isdigit(literal[0]))
                printChar(literal[0]);
            else if (isInt(literal))
                printInt(std::atol(literal.c_str()));
            else if (isFloat(literal) && literal.find(".") != std::string::npos)
                printFloat(std::atof(literal.c_str()));
            else if (isDouble(literal) && literal.find(".") != std::string::npos)
                printDouble(std::atof(literal.c_str()));
            else
                {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                }
    }
    else
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
}

//checkers


bool checkPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" || str == "inf" || str == "inff" ||
            str == "-inf" || str == "-inff");
}

bool isInt(const std::string& str)
{
    char* end;
    //long int strtol(const char* str, char** endptr, int base);
    //base is for the inserted str frormat
    long val = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool isFloat(const std::string& str)
{
    char* end;
    float val = std::strtof(str.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0') || (*end == '\0' && val >= -FLT_MAX && val <= FLT_MAX);
}

bool isDouble(const std::string& str)
{
    char* end;
    double val = std::strtod(str.c_str(), &end);
    return *end == '\0' && val >= -DBL_MAX && val <= DBL_MAX;
}

//printers


void printPseudoLiteral(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    //fixed used for avoiding scientific notation in large or small nums
    //setprecision used for N of numbers after the fixed point
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printInt(int i)
{
    if (i >= 0 && i <= 127 && std::isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void printFloat(float f)
{
    if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    //For float: not every large int can be represented exactly, so there’s a precision risk
    if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void printDouble(double d)
{
    if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (d >= -FLT_MAX && d <= FLT_MAX)
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

