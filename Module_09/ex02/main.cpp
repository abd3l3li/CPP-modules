#include "PmergeMe.hpp"

// Helper function to print the container
template <typename Container>
void printContainer(const Container &c)
{
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{

    try {
        // Parse input numbers from arguments
        std::vector<int> numbers = PmergeMe::parseInput(argc, argv);

        // Show before sorting
        std::cout << "Before: ";
        printContainer(numbers);

        // Copy data for both containers
        std::vector<int> vec = numbers;
        std::deque<int> deq(numbers.begin(), numbers.end()); // range constructor

        // Measure sorting time for vector
        double vectorTime = PmergeMe::elapsedTime(vec);

        // Measure sorting time for deque
        double dequeTime = PmergeMe::elapsedTime(deq);

        // Show after sorting
        std::cout << "After:  ";
        printContainer(vec);

        // Print performance results
        std::cout << "Time to process a range of " << numbers.size()
                    << " elements with std::vector : " << std::fixed 
                    << std::setprecision(6) << vectorTime << " sec" << std::endl;

        std::cout << "Time to process a range of " << numbers.size()
                    << " elements with std::deque  : " << std::fixed 
                    << std::setprecision(6) << dequeTime << " sec" << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
