#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn’t sign " << form.getName()
                << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException(); 
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : _name(other._name), _grade(other._grade)
{}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other)
        _grade = other._grade; 
    return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() 
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}



const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Exception: Grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Exception: Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    return out << b.getName() << ", bureaucrat grade " << b.getGrade();
}