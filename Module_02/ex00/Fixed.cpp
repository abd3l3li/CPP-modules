#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
 }

Fixed::Fixed(const Fixed& other) { std::cout << "Copy constructor called" << std::endl;
    _rawBits = other.getRawBits();
}

Fixed& Fixed::operator = (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) //this != other; ❌ invalid — pointer != reference
        _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}
