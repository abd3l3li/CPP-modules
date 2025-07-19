#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor with grade validation
Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
    : _name(other._name),
        _isSigned(other._isSigned),
        _signGrade(other._signGrade),
        _execGrade(other._execGrade)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    // _name, _signGrade, and _execGrade are const → can't be reassigned
    return *this;
}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

// beSigned() logic
void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exception messages
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low";
}

// Output stream overload
std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form \"" << f.getName() << "\" [Sign grade: " << f.getSignGrade()
        << ", Exec grade: " << f.getExecGrade()
        << ", Signed: " << (f.isSigned() ? "yes" : "no") << "]";
    return out;
}
