#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cerr << "Error: No arguments provided!" << std::endl;

    try {
        PmergeMe data(argv + 1, argc - 1); }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}