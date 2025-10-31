#include "PmergeMe.hpp"

// Parse input arguments and validate them
std::vector<int> PmergeMe::parseInput(int argc, char **argv)
{
    std::vector<int> numbers;
    std::set<int> uniqueCheck;

    if (argc < 2)
        throw std::runtime_error("Error: no arguments provided");

    for (int i = 1; i < argc; ++i)
    {

        std::string arg = argv[i];
        std::istringstream iss(arg);
        long num;

        // Ensure argument is a valid positive integer
        if (!(iss >> num) || !iss.eof() || (num <= 0 || num > INT_MAX))
            throw std::runtime_error("Error: invalid number '" + arg + "'");
        
        if (uniqueCheck.find(static_cast<int>(num)) != uniqueCheck.end())
            throw std::runtime_error("Error: duplicate number '" + arg + "'");
        uniqueCheck.insert(static_cast<int>(num));

        numbers.push_back(static_cast<int>(num));
    }

    return numbers;
}
