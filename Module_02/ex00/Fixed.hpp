#pragma once

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed();
        void setRawBits( int const raw );
        int getRawBits( void ) const;
};