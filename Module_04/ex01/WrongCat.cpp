#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound() const {
    std::cout << "Meow??\n";
}
