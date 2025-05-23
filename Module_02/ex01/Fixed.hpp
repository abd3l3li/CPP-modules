#pragma once

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
