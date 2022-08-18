#include "Person.hpp"
#include <iostream>
#include "Noise.hpp"

Person::Person() : firstname_(""), lastname_(""), arbitaryNumber_(-1) {

}

Person::Person(std::string first, std::string last, int arbitrary) 
    : firstname_(first), lastname_(last), arbitaryNumber_(arbitrary) {
        // local variable -> goes out of scope at the end of the constructor
        Noise np("speak");
        if (arbitaryNumber_ == 0) {
            throw std::invalid_argument("Arbitrrary number for a Person cannot be zero.\n");
        }
}

Person::~Person(void) {
    std::cout << "Destructing person " << this->getName();
}