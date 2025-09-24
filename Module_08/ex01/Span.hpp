#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _nums;


    public:
        // Constructors / Destructor
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Add numbers
        void addNumber(int value);

        template <typename InputIt>
        void addNumber(InputIt begin, InputIt end);

        // Span calculations
        int shortestSpan() const;
        int longestSpan() const;

        // Exceptions
        class FullException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
};

// Template implementation must stay in header
template <typename InputIt>
void Span::addNumber(InputIt begin, InputIt end) {
    if (_nums.size() + std::distance(begin, end) > _N)
        throw FullException();
    _nums.insert(_nums.end(), begin, end);
}