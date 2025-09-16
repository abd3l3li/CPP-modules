#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int SIZE = 4;
    Animal* animals[SIZE];

    // Half dogs, half cats
    for (int i = 0; i < SIZE; ++i) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Making sounds ---\n";
    for (int i = 0; i < SIZE; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting animals ---\n";
    for (int i = 0; i < SIZE; ++i) {
        delete animals[i];  // should call the right destructor chain
    }

    std::cout << "\n--- Deep copy test ---\n";
    Dog basic;
    basic.getBrain()->setIdea(0, "I want a bone!");

    Dog copy = basic;  // calls copy constructor
    basic.getBrain()->setIdea(0, "I want a steak!");

    std::cout << "Original Dog's idea: " << basic.getBrain()->getIdea(0) << "\n";
    std::cout << "Copied Dog's idea: " << copy.getBrain()->getIdea(0) << "\n";

    return 0;
}

