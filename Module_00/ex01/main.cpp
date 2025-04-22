#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string holder;

    std::cout << "\033[34m****** Welcome to the PhoneBook program ******\033[0m";
    std::cout << std::endl;
    std::cout << "\033[32mThe program only accepts ADD, SEARCH and EXIT.\033[0m";
    std::cout << std::endl;
    while(true)
    {
        std::cout << "Please insert you option: ";
        std::getline(std::cin, holder);
        std::cout << std::endl;
        if (holder == "ADD")
            phonebook.addData();
        else if (holder == "SEARCH")
            phonebook.searchData();
        else if (holder == "EXIT")
            break;
        else
            std::cout << "\e[31mInvalid input!\033[0m" << std::endl;
    }
}
