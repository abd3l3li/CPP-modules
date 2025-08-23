#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}


ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
    {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getExecGrade())
    {
        throw Bureaucrat::GradeTooLowException();
    }

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    outfile << "       /\\\n";
    outfile << "      /**\\\n";
    outfile << "     /****\\\n";
    outfile << "    /******\\\n";
    outfile << "   /********\\\n";
    outfile << "  /**********\\\n";
    outfile << "      ||||\n";
    outfile << "      ||||\n";

    outfile.close(); 
}
