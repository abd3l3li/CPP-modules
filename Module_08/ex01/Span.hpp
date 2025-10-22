#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
// #include <exception>
// #include <iterator>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _nums;


    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


        void addNumber(int value);

        template <typename InputIt>
        void addNumber(InputIt begin, InputIt end);


        int shortestSpan() const;
        int longestSpan() const;


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

template <typename InputIt>
void Span::addNumber(InputIt begin, InputIt end)
{
    if (_nums.size() + std::distance(begin, end) > _N)
        throw FullException();
    _nums.insert(_nums.end(), begin, end);
}