#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("Diamond");

    dt.attack("TargetBot");
    dt.whoAmI();
    dt.takeDamage(40);
    dt.beRepaired(10);

    return 0;
}
