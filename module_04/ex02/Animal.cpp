#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed\n";
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copied\n";
}

Animal& Animal::operator=(const Animal& other) {
    type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed\n";
}

// void Animal::makeSound() const {
//     std::cout << "* generic animal sound *\n";
// }

std::string Animal::getType() const {
    return type;
}
