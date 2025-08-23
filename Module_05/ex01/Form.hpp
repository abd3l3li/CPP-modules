#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; 

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

    
    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;


    void beSigned(const Bureaucrat& b);


    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};


std::ostream& operator<<(std::ostream& out, const Form& f);
