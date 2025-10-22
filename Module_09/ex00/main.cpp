#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Provide a valid input file." << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;
    
    // Load the database
    exchange.loadData("data.csv");
    
    // Process the input file
    exchange.processInput(argv[1]);
    
    return 0;
}