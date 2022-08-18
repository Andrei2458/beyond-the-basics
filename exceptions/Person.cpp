#include "Person.hpp"
#include <iostream>

Person::Person() : firstname_(""), lastname_(""), arbitaryNumber_(-1) {

}

Person::Person(std::string first, std::string last, int arbitrary) 
    : firstname_(first), lastname_(last), arbitaryNumber_(arbitrary) {
        if (arbitaryNumber_ == 0) {
            throw std::invalid_argument("Arbitrrary number for a Person cannot be zero.\n");
        }
    }