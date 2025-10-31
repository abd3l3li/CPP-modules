#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <climits>
//for precision
#include <iomanip>

class PmergeMe
{
    public:
        static std::vector<int> parseInput(int argc, char **argv);

        template <typename Container>
        static void mergeInsertSort(Container &data);

        template <typename Container>
        static double elapsedTime(Container &data);

        template <typename Container>
        static void binaryInsert(Container &sorted, int value);
};


template <typename Container>
void PmergeMe::binaryInsert(Container &sorted, int value)
{
    if (sorted.empty())
    {
        sorted.push_back(value);
        return;
    }
    size_t left = 0;
    size_t right = sorted.size();
    while (left < right) {
        size_t range = (left + right) / 2;
        if (value < sorted[range])
            right = range;
        else
            left = range + 1;
    }
    sorted.insert(sorted.begin() + left, value);
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &data)
{

    if (data.size() <= 1)
        return;

    Container winners, losers;

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        int first = data[i];
        int second = data[i + 1];
        if (first < second)
            std::swap(first, second);
        winners.push_back(first);
        losers.push_back(second);
    }

    if (data.size() % 2 != 0)
        winners.push_back(data.back());

    std::sort(winners.begin(), winners.end());

    for (size_t i = 0; i < losers.size(); ++i)
        binaryInsert(winners, losers[i]);

    data = winners;
}

template <typename Container>
double PmergeMe::elapsedTime(Container &data)
{
    timeval start, end;
    gettimeofday(&start, NULL);
    mergeInsertSort(data);
    gettimeofday(&end, NULL);

    double start_us = static_cast<double>(start.tv_sec) + start.tv_usec / 1000000.0;
    double end_us = static_cast<double>(end.tv_sec) + end.tv_usec / 1000000.0;
    return end_us - start_us;
}

