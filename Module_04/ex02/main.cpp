#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Polymorphic Animals ===\n";
    // const Animal* gen = new Animal();
    const Animal* j = new Dog(); //new for avoiding temp obj
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound(); // Barking!
    i->makeSound(); // Meow!
    // gen->makeSound(); // Generic

    // delete gen;
    delete j;
    delete i;

    std::cout << "\n=== Non-polymorphic Animals ===\n";
    WrongAnimal* wrong = new WrongCat();
    wrong->makeSound(); // * weird wrong animal sound * --> this's wrong

    delete wrong;

    return 0;
}
