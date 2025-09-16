#include "Cat.hpp"

Cat::Cat()
: Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

Brain *Cat::getBrain() const //for test
{
    return brain;
}