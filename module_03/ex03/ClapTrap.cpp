#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}
ClapTrap::ClapTrap(std::string name)
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " Constructed\n"; 
}
ClapTrap::ClapTrap(const ClapTrap& other) 
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
    if (this != &other)
    {
        
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " Destructed\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't attack.\n";
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
       << " causing \e[32m" << attackDamage << "\e[0m points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << name << " took damage"
        << " remaining \e[32mHP: " << hitPoints << "\e[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if (energyPoints > 0 && hitPoints > 0)
        hitPoints += amount, --energyPoints,
        std::cout << name << " got repaired 🤖\n";

    else
        std::cout << name << " can't be repaired, his \e[43mheart\e[0m is broken!\n";
}