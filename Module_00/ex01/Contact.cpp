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
    if(!std::getline(std::cin, firstName))
        exit(0);
    std::cout << "Last Name: ";
    if(!std::getline(std::cin, lastName))
        exit(0);
    std::cout << "Nickname: ";
    if(!std::getline(std::cin, nickname))
        exit(0);
    std::cout << "Phone Number: ";
    if(!std::getline(std::cin, phoneNumber))
        exit(0);
    std::cout << "Darkest Secret: ";
    if(!std::getline(std::cin, darkestSecret))
        exit(0);
}

void Contact::getData()
{
    std::cout << "First Name: " << firstName << " ℹ️" << std::endl;
    std::cout << "Last Name: " << lastName << " ℹ️" << std::endl;
    std::cout << "Nickname: " << nickname << " ℹ️" << std::endl;
    std::cout << "Phone Number: " << phoneNumber << " ☎️" << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << " ☠️" << std::endl;
}

void Contact::getTitles(int index)
{
    std::cout << "|" << std::setw(10) << index;
    format(firstName);
    format(lastName);
    format(nickname);
    std::cout << "|" << std::endl;
}

bool Contact::isValid()
{
    if (firstName.empty() || lastName.empty() || nickname.empty()
        || phoneNumber.empty() || darkestSecret.empty())
        return false;

    for (size_t i = 0; i < firstName.length(); ++i)
        if (!isprint(firstName[i]))
            return false;
    for (size_t i = 0; i < lastName.length(); ++i)
        if (!isprint(lastName[i]))
            return false;
    for (size_t i = 0; i < nickname.length(); ++i)
        if (!isprint(nickname[i]))
            return false;
    for (size_t i = 0; i < phoneNumber.length(); ++i)
        if (!isdigit(phoneNumber[i]))
            return false;
    for (size_t i = 0; i < darkestSecret.length(); ++i)
        if (!isprint(darkestSecret[i]))
            return false;
    return true;
}
