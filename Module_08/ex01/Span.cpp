#include "Span.hpp"

// Exceptions
const char* Span::FullException::what() const throw() {
    return "Cannot add number: Span is full";
}
const char* Span::NoSpanException::what() const throw() {
    return "Cannot calculate span: not enough numbers";
}

// Constructors
    // for avoid reallocation
Span::Span(unsigned int N) : _N(N) {_nums.reserve(N); }
Span::Span(const Span& other) : _N(other._N), _nums(other._nums) {}
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        _nums = other._nums;
    }
    return *this;
}
Span::~Span() {}

// Add one number
void Span::addNumber(int value)
{
    if (_nums.size() >= _N)
        throw FullException();
    _nums.push_back(value);
}

// Shortest span
int Span::shortestSpan() const
{
    if (_nums.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp = _nums;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

// Longest span
int Span::longestSpan() const 
{
    if (_nums.size() < 2)
        throw NoSpanException();
    int minVal = *std::min_element(_nums.begin(), _nums.end());
    int maxVal = *std::max_element(_nums.begin(), _nums.end());
    return maxVal - minVal;
}
