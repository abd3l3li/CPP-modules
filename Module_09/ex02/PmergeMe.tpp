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
    //here


}