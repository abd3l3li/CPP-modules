#pragma once

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator = (const ClapTrap& other);
        ClapTrap(std::string name);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};