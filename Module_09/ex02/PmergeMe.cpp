#include "PmergeMe.hpp"

int PmergeMe::ParseInput(std::string &item)
{
    for (int i = 0; i < item.size(); ++i)
        if (isdigit(item[i]))
            return (-1);
    
    std::stringstream ss(item);
    long num;
    ss >> num;
    if (num > 0 && num < INT_MAX)
        _dataUnsorted.push_back(static_cast<int>(num));
    else
        return (-1);
}

PmergeMe::PmergeMe(char **data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::string items(data[i]);
        
        if(-1 == ParseInput(items))
            throw std::runtime_error("Wrong data type!");    
    }

    if (_dataUnsorted.empty())
        return;
        
    std::vector<int> vec;
    std::deque<int> deq;

    mergeInsert(vec);
    mergeInsert(deq);
}
