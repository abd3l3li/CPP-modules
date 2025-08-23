#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Valid Signing ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("TaxForm", 100, 80); // Bob is high enough to sign

        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Signing ===" << std::endl;
    try {
        Bureaucrat tom("Tom", 130);
        Form secretForm("SecretForm", 50, 20); // Tom is too low to sign

        std::cout << secretForm << std::endl;
        tom.signForm(secretForm); // should fail
        std::cout << secretForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Grades ===" << std::endl;
    try {
        Form invalid("BrokenForm", 0, 10); // invalid signGrade (too high)
    } catch (std::exception& e) {
        std::cerr << "Caught while creating form: " << e.what() << std::endl;
    }

    return 0;
}
