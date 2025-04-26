#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) //try to use no ref
{
    this->weapon = &weapon;
}
void HumanB::attack()
{
    if (!weapon)
        std::cout << name << " got no armor";
    else
        std::cout << name << " attacks with their " << (*weapon).getType();
    std:: cout << std::endl;
}
