#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    // Constructor & destructor
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();

    // Copy constructor & assignment operator
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    // Override execute()
    void execute(Bureaucrat const& executor) const;
};
