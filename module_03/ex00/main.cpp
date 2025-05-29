#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Dummy");
    a.attack("Fool");
    a.takeDamage(5);
    a.beRepaired(5);
    a.takeDamage(20);
    a.beRepaired(10);
}