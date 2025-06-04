#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    std::cout << "WrongAnimal copied\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "* weird wrong animal sound *\n";
}

std::string WrongAnimal::getType() const {
    return type;
}
