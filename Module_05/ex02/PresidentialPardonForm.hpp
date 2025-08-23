#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();


    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    
    void execute(const Bureaucrat& executor) const;
};
