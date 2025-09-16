#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    Array<int> a(5); // the compiler can't deduce the type without explicit template argument
    for (size_t i = 0; i < a.size(); i++)
        a[i] = i * 10;

    std::cout << "Array<int>: ";
    for (size_t i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    Array<std::string> b(3);
    b[0] = "hello"; // overloaded operator[] to allow this
    b[1] = "world";
    b[2] = "!";
    std::cout << "Array<std::string>: ";
    for (size_t i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << "\n";

    // Test copy
    Array<int> c = a;
    std::cout << "Copied Array<int>: ";
    for (size_t i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << "\n";

    // Test out-of-range
    try {
        std::cout << b[3] << "\n";  // should throw
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
