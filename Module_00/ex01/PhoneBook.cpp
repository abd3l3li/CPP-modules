#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    total = 0;
    indexing = 0;
}

void PhoneBook::addData()
{
    contact[indexing].setData();
    if (!contact[indexing].checkEmpty())
    {
        std::cout << "All the fields must be filled!" << std::endl;
        return;
    }
    
    if (total < 8) //for searchData
        total++;

    indexing++;
    if (indexing == 8) //we have reached the max so we have to start again
        indexing = 0;

    std::cout << "\e[1;31mman! this is a useless data give your credit card info 👀\e[0m";
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

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while(i < total)
    {
        contact[i].getTitles(i);
        i++;
    }

    std::cout << "Insert the contact index: ";
    std::getline(std::cin, index);

    if (index.length() != 1 || index[0] < '0' || index[0] > '7')
    {
        std::cout << "Invalid input!" << std::endl;
        return;
    }

    num = std::stoi(index);
    if (num >= total)
    {
        std::cout << "Out of range!" << std::endl;
        return;
    }


    contact[num].getData();
}
