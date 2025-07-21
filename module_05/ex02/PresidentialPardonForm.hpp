#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    // Constructor / Destructor
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

    // Copy constructor / Assignment operator
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    // Execution behavior
    void execute(const Bureaucrat& executor) const;
};
