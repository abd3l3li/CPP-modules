#include "Zombie.hpp"

int main()
{
    int i;

    Zombie *zombies = zombieHorde( 4,"testing" );

    i = 0;
    while(i < 4) { zombies[i++].announce(); }

    delete[] zombies;
}
