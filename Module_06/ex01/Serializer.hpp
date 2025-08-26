#pragma once

#include <iostream>
#include <stdint.h>


class Serializer 
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
    public:
        struct Data
        {
            int         i;
            std::string s;
        };
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


