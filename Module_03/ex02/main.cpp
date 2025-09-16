#include "FragTrap.hpp"

int main()
{
    FragTrap bot("Fraggy");

    bot.attack("EnemyBot");
    bot.takeDamage(50);
    bot.beRepaired(20);
    bot.highFivesGuys();

    return 0;
}