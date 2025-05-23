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
        //overloading section
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        /*---------------------------------------*/
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        /*---------------------------------------*/
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
         /*---------------------------------------*/
         static Fixed& min(Fixed& a, Fixed& b); //static to be used as a global function
         static const Fixed& min(const Fixed& a, const Fixed& b);
         static Fixed& max(Fixed& a, Fixed& b);
         static const Fixed& max(const Fixed& a, const Fixed& b); 
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
