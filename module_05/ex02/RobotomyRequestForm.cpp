#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "* DRILLING NOISES *\n";

    static bool toggle = false;
    toggle = !toggle;

    if (toggle)
        std::cout << _target << " has been successfully robotomized!\n";
    else
        std::cout << "Robotomy failed.\n";
}

