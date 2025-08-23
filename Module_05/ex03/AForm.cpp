#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
    : _name(other._name),
        _isSigned(other._isSigned),
        _signGrade(other._signGrade),
        _execGrade(other._execGrade)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    
    return *this;
}


const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }


void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade is too low";
}


std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "AForm \"" << f.getName() << "\" [Sign grade: " << f.getSignGrade()
        << ", Exec grade: " << f.getExecGrade()
        << ", Signed: " << (f.isSigned() ? "yes" : "no") << "]";
    return out;
}
