#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{

    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // 14

        // Bulk insert
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i) v.push_back(rand());
        Span big(10000);
        big.addNumber(v.begin(), v.end());
        std::cout << "Big shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Big longest span: " << big.longestSpan() << std::endl;

        // Exception cases
        sp.addNumber(42); // Should throw FullException

    }
    
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}
