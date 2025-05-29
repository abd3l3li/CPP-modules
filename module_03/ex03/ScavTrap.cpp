#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}
ScavTrap::ScavTrap(std::string name)
: ClapTrap(name) //because it is not the default constructor
{
    // this->name = name; //this is for the object, which means the base one
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " Constructed\n"; 
}
ScavTrap::ScavTrap(const ScavTrap& other) 
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy constructor called\n";
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
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
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " Destructed\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack.\n";
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
       << " causing \e[32m" << attackDamage << "\e[0m points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << "is now in Gate keeper mode\n";
}
