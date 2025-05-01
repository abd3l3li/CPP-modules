#include "Harl.hpp"

int main()
{
    std::string line;
    Harl        harl;

    std::cout << "\e[34mYour report sir! [DEBUG, INFO, WARNING, ERROR]: \e[0m";
    std::getline(std::cin, line);

    harl.complain(line);
}