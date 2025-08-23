#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}


AForm*    shrubCreation(const std::string& t) { return new ShrubberyCreationForm(t); }
AForm*    robotCreation(const std::string& t) { return new RobotomyRequestForm(t); }
AForm*    presidentialCreation(const std::string& t) { return new PresidentialPardonForm(t); }


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*constructors[3])(const std::string&) = {
        shrubCreation,
        robotCreation,
        presidentialCreation

    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return constructors[i](target);
        }
    }

    std::cout << "Intern: Error - Unknown form name '" << formName << "'." << std::endl;
    return NULL;
}
