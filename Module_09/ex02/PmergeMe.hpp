#pragma once


#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <climits>
#include <deque>


class PmergeMe
{
    
    public:
    PmergeMe() = default; // default means the compiler generates the behavior automatically
    PmergeMe(char **data, int size);
    PmergeMe(const PmergeMe &other) = default;
    PmergeMe& operator=(const PmergeMe &other) = default;
    ~PmergeMe() = default;
    
    
    private:
    std::vector<int> _dataUnsorted;
    std::vector<int> _dataSorted;
    int ParseInput(std::string &item);
    
        #include "PmergeMe.tpp"
        template <typename container>
        void mergeInsert(container& data) const;
        template <typename container>
        void binaryInsert(container& win, int lose);
        template <typename container>
        void printContainer(container& data) const;


};