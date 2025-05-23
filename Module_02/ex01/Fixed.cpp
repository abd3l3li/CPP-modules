#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
 }
 
 Fixed::Fixed(const Fixed& other) 
{   
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

Fixed& Fixed::operator = (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value * (1 << _fractionalBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }


float Fixed::toFloat( void ) const
{
    return (float)_rawBits / 256;
}
int Fixed::toInt( void ) const
{
    return _rawBits / 256;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    return out << fixed.toFloat();
}
