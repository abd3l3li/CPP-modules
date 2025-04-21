#include "Contact.hpp"

void format (std::string data)
{
    std::string tmp;

    if (data.length() > 10)
    {
        tmp = data.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << tmp;
    }
    else
    std::cout << "|" << std::setw(10) << data;
}

void Contact::setData()
{
    std::cout << "First Name: ";
    std::getline(std::cin, firstName);

    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumer);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    //std::cout << "\e[1;31mman! this is a useless 
    //data give your credit card info 👀\e[0m";
    
}

void Contact::getData()
{
    std::cout << "First Name: " << firstName << " ℹ️" << std::endl;
    std::cout << "Last Name: " << lastName << " ℹ️" << std::endl;
    std::cout << "Nickname: " << nickname << " ℹ️" << std::endl;
    std::cout << "Phone Number: " << phoneNumer << " ☎️" << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << " ☠️" << std::endl;
}

void Contact::getTitles(int index)
{
    std::cout << "|" << std::setw(10) << index;
    format(firstName);
    format(lastName);
    format(phoneNumer);
    format(nickname);
    std::cout << "|" << std::endl;
}

bool Contact::checkEmpty()
{
    return (!firstName.empty() && !lastName.empty() && !nickname.empty()
            && !phoneNumer.empty() && !darkestSecret.empty());
}