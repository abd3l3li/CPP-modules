#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

// Execute behavior
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
