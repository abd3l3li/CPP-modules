#include "Base.hpp"

Base::~Base() {}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
    else std::cout << "Uknown Type\n";
}

void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n";}
    catch(...){} // or I can use std::bad_cast &e if I want
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n";}
    catch(...){}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n";}
    catch(...){}
}

Base* generate(void)
{
    // srand(time(NULL));
    int random = rand() % 3; // it moves to next in each call
    if (random == 0) return new A();
    else if (random == 1) return new B();
    else return new C();
}