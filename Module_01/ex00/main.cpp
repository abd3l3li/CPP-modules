#include "Zombie.hpp"

int main()
{
    Zombie *alloc = newZombie("dynamic zombie");
    alloc->announce();
    delete alloc;

    randomChump("static zombie");
}
