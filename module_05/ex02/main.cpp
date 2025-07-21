#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 1); // high-level bureaucrat
        Bureaucrat bob("Bob", 140);   // low-level bureaucrat

        ShrubberyCreationForm shrubForm("garden");
        RobotomyRequestForm robotForm("marvin");
        PresidentialPardonForm pardonForm("Ford");

        std::cout << "\n== Trying to sign all forms with Bob ==\n";
        bob.signForm(shrubForm);  // Should work
        bob.signForm(robotForm);  // Should fail
        bob.signForm(pardonForm); // Should fail

        std::cout << "\n== Trying to execute all forms with Bob ==\n";
        bob.executeForm(shrubForm);  // Should fail (low exec grade)
        bob.executeForm(robotForm);  // Should fail
        bob.executeForm(pardonForm); // Should fail

        std::cout << "\n== Now Alice signs and executes all ==\n";
        alice.signForm(robotForm);
        alice.signForm(pardonForm);
        alice.signForm(shrubForm);  // Should work // why it still work?

        std::cout << "\n== Alice executing forms ==\n";

        alice.executeForm(shrubForm);  // Should succeed
        alice.executeForm(robotForm);  // Should succeed/fail randomly
        alice.executeForm(pardonForm); // Should succeed

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
