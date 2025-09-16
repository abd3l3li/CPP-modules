#include "FragTrap.hpp"

FragTrap::FragTrap() {}
FragTrap::FragTrap(std::string name)
: ClapTrap(name) //because it is not the default constructor
{
    // this->name = name; //this is for the object, which means the base one
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " Constructed\n"; 
}
FragTrap::FragTrap(const FragTrap& other) 
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy constructor called\n";
}


FragTrap& FragTrap::operator = (const FragTrap& other)
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
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " Destructed\n";
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "FragTrap " << name << " can't attack.\n";
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target
       << " causing \e[32m" << attackDamage << "\e[0m points of damage!\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high fives ✋" << std::endl;
}