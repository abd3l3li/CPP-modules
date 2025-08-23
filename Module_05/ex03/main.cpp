
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{

    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "test1");
    if (form) {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "test2");
    if (form) {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = intern.makeForm("presidential pardon", "test3");
    if (form) {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = intern.makeForm("unknown form", "test4");
    if (form) {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    return 0;
}