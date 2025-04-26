#include "Weapon.hpp"


void Weapon::setType(std::string type) { this->type = type; }
std::string Weapon::getType() const
{
    const std::string& reff = type; //does the func return also must be const!!
    return reff;

}

Weapon::Weapon(std::string type) { 
    Weapon::setType(type);
}
Weapon::~Weapon() {}