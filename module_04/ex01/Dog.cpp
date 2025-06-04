#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
    std::cout << "Barking!\n";
}

Brain *Dog::getBrain() const //for test
{
    return brain;
}