#include "iter.hpp"


template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    char carr[] = {'a', 'b', 'c', 'd', 'e'};
    std::string sarr[] = {"hello", "world", "this", "is", "C++"};

    iter(arr, 5, print);
    std::cout << "<---->" << std::endl; 
    iter(carr, 5, print);
    std::cout << "<---->" << std::endl;
    iter(sarr, 5, print);

    return 0;
}