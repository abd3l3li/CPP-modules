#include "Cat.hpp"

Cat::Cat()
: Animal()
{
    type = "Cat";
    std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other) //why animal not dog obj
{
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
