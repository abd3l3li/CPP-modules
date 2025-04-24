#include "Zombie.hpp"

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; }

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << name << " zombie has been spawned\n";
}
Zombie::~Zombie() { std::cout << name << " hold oooon, not yet.....!\n"; }