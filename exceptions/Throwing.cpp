#include <vector>
#include <iostream>
#include <exception>
#include "Person.hpp"
#include "Noise.hpp"

// Person implementation

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

// Noise implementation

Noise::Noise(std::string sim) : soundIMake_(sim) {
    std::cout << "Constructing Noise " << soundIMake_ << "\n";
}

Noise::~Noise(void) {
    std::cout << "Destructing Noise  " << soundIMake_ << "\n";
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    Noise n1("beep 1");

    try {
        Noise n2("beep 2");
        Person andrei("andrei", "vacariu", 0);
        int j = v.at(99);
    }
    catch(std::out_of_range & e) { // because this more explicit catch block is placed second it will not be executed
        std::cout << " out of range exception " << e.what() << "\n";
    } 
    catch(std::exception& e) { // more general block gets executed as it is the first one
        std::cout << e.what() << "\n";
    }
    
    
    return 0;
}