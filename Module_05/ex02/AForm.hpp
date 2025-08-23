#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; 

class AForm
{
private:
    const std::string _name;
    bool        _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    
    AForm(const std::string& name, int signGrade, int execGrade);
    virtual ~AForm();

    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    
    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;


    void beSigned(const Bureaucrat& b);

    
    virtual void execute(Bureaucrat const& executor) const = 0;


    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};


std::ostream& operator<<(std::ostream& out, const AForm& f);
