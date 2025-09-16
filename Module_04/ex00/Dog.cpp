#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    type = "Dog";
    std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
    std::cout << "Barking!\n";
}
