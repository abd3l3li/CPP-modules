#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }
    std::deque<int> deq;
    for (int i = 10; i <= 50; i += 10) {
        deq.push_back(i);
    }

    try
    {
        std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Found in deque: " << *easyfind(deq, 30) << std::endl;
        std::cout << "Trying to find 6 in vector..." << std::endl;
        easyfind(vec, 6);
    }
    
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}