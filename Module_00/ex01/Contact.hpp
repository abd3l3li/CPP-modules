#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void setData();
        void getData();
        void getTitles(int index);
        bool isValid();
};