#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Ali", 2);
        a.incrementGrade();
        std::cout << a.getName() << " grade is: " << a.getGrade() << std::endl;
        Bureaucrat b("someone", 149);
        b.decrementGrade();
        std::cout << b.getName() << " grade is: " << b.getGrade() << std::endl;

        // std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Gotchu body, what u say about this: \n"
            << e.what() << "\n";
    }

    //std::cout << "Man! u got run form the exceptions, cheers!\n";
}