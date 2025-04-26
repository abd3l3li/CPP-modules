#pragma once

#include <iostream>

class Weapon // recheck this part of the weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        ~Weapon();
        void setType(std::string type);
        std::string getType() const;
};