#include "notLoser.hpp"

int notLoser(std::string filename, std::string s1, std::string s2)
{
    std::ifstream input(filename.c_str()); //int fd = input.rdbuf()->fd()
    if (!input)
    {
        std::cout << "\e[31mError: Can't open the file\e[0m";
        std::cout << std::endl;
        return 1;
    }
    
    std::ofstream output((filename+".replace").c_str());
    if (!output)
    {
        std::cout << "\e[31mError: Can't create the file\e[0m";
        std::cout << std::endl;
        return 1;
    }

    std::string line;
    size_t err = std::string::npos;
    while (std::getline(input, line))//test with -1 and test with <<
    {
        for (size_t pos = 0; (pos = line.find(s1, pos)) != err; pos += s2.length())
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
        }
        output << line << "\n"; // getline removes the \n
    }
    return 0;
}
