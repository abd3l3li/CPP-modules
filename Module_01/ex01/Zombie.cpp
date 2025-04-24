#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie() { std::cout << "A zombie has been spawned\n"; }
Zombie::~Zombie() { std::cout << "See ya..!\n"; }

void Zombie::setName(std::string name) { this->name = name; }