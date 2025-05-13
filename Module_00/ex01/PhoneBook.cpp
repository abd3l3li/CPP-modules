#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    total = 0;
    indexing = 0;
}

void PhoneBook::addData()
{
    contact[indexing].setData();
    if (!contact[indexing].isValid())
    {
        std::cout << "\e[31mPlease recheck your information!\033[0m" << std::endl;
        return;
    }
    
    if (total < 8) //for searchData
        total++;

    indexing++;
    if (indexing == 8) //we have reached the max so we have to start again
        indexing = 0;

    std::cout << "\e[1;33mMan! this is a useless data. Provide your credit card info 👀\e[0m";
    std::cout << std::endl;
    std::cout << "\e[1;32mHowever, your data has been added successfully :)\e[0m"  << std::endl;

}

void PhoneBook::searchData()
{
    int i;
    int num;
    std::string index;
    
    i = 0;
    if (total == 0)
    {
        std::cout << "The phoneBook is empty!" << std::endl;
        return;
    }

    std::cout << "\033[34m|     Index|First Name| Last Name|  Nickname|\033[0m";
    std::cout << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while(i < total)
    {
        contact[i].getTitles(i);
        i++;
    }

    std::cout << "Insert the contact index: ";
    if(!std::getline(std::cin, index))
        exit(0);

    if (index.length() != 1 || index[0] < '0' || index[0] > '7')
    {
        std::cout << "\033[31mInvalid input!\033[0m" << std::endl;
        return;
    }

    num = index[0] - '0';
    if (num >= total)
    {
        std::cout << "\033[31mOut of range!\033[0m" << std::endl;
        return;
    }


    contact[num].getData();
}
