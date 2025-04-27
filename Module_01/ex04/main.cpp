#include "notLoser.hpp"

int main(int ac, char *av[])
{
    int r;

    r = 0;
    if ( ac == 4)
    {
        r = notLoser(av[1], av[2], av[3]);
        if (!r)
            std::cout << "\e[34mAll is done!\n\e[0m";
    }
    else
    {
        std::cout << "\e[31mError: You have to insert: [filename] [s1] [s2]\e[0m";
        std::cout << std::endl; 
    }
    return r;
}