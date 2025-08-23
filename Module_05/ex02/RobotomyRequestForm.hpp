#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();

    
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    
    void execute(Bureaucrat const& executor) const;
};
