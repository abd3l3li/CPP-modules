#pragma once

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
        int total;
        int indexing;
    public:
        PhoneBook();
        void addData();
        void searchData();
};