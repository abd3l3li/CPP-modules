#include "PmergeMe.hpp"

template <typename container>
void PmergeMe::mergeInsert(container& data) const
{
    container win;
    container lose;

    for (int i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i] > data[i + 1] )
        {
            win.push_back(data[i])
            lose.push_back(data[i + 1])
        }
        else
        {
            win.push_back(data[i + 1])
            lose.push_back(data[i])
        }
    }
    if (data.size() % 2 != 0)
        win.push_back(data.back());
    
    win = win.sort();

    int i = 0;
    while (i < lose.size())
    {
        binaryIsert(win, lose[i]);
    }

    data = win;

    // printContainer(_dataSorted); // not it's place
}

template <typename container>
void PmergeMe::binaryInsert(container& win, int lose)
{
    int range = 0;
    int left = 0;
    int right = win.size();

    while (left < right)
    {
        range = left + right / 2;
        if (lose < range)
            left = range;
        else
            right = range + 1; //why
    }
    win.insert(win + left, lose);
}

template <typename container> 
void PmergeMe::printContainer(container& data) const
{
    std::cout << "Unsorted numbers: ";
    typname container::iterator it;
    it = data.begin()
    while (it != data.end())
        std::cout << *it++ << " ";
    
    std::cout << "Sorted numbers: ";
    typname container::iterator it;
    it = data.begin()
    while (it != data.end())
        std::cout << *it++ << " ";
            
}