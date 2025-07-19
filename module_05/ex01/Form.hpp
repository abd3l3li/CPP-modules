#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration (we'll include the full class in Form.cpp)

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    
    Form(const std::string& name, int signGrade, int execGrade);
    ~Form();

    
    Form(const Form& other);
    Form& operator=(const Form& other);

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Signing logic
    void beSigned(const Bureaucrat& b);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// Overload output operator
std::ostream& operator<<(std::ostream& out, const Form& f);
