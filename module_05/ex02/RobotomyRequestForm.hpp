#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    // Constructor & destructor
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();

    // Copy constructor & assignment operator
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    // Override execute()
    void execute(Bureaucrat const& executor) const;
};
