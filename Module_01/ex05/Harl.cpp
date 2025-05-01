#include "Harl.hpp"

void Harl::debug() { std::cout << "[DEBUG] this is a Debug Messaage\n"; }
void Harl::info() { std::cout << "[INFO] this is an Info Messaage\n"; }
void Harl::warning() { std::cout << "[WARNING] this is a Warning Messaage\n"; }
void Harl::error() { std::cout << "[ERROR] this is an Error Messaage\n"; }

void Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcPtr[])() = { //just use the name of the function with no ()
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*funcPtr[i])();//use brackets to derefrence it first then call the function
                                  //using -> because this is a pointer to the object
            return;
        }
    }
    std::cout << "\e[31m[AWKWARD] you missed the right option sir!\n\e[0m";
}
