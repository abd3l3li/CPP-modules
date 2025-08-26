#include "Base.hpp"

int main()
{
    Base* base;

    for (int i = 0; i < 5; i++)
    {
        base = generate();
        std::cout << "-" << std::endl;

        std::cout << "Identified base pointer is: ";
        identify(base);
        std::cout << "Identified base reference is: ";
        identify(*base);

        delete base;
        sleep(2);
    }

    return 0;
}