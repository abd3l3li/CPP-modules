#include "ScavTrap.hpp"

int main() {
    ScavTrap robot("Guardian");

    robot.attack("Bomber");
    robot.takeDamage(30);
    robot.beRepaired(20);
    robot.guardGate();

    return 0;
}
