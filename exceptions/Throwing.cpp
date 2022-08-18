#include <vector>
#include <iostream>
#include <exception>
#include "Person.hpp"

Person::Person() : firstname_(""), lastname_(""), arbitaryNumber_(-1) {

}

Person::Person(std::string first, std::string last, int arbitrary) 
    : firstname_(first), lastname_(last), arbitaryNumber_(arbitrary) {
        if (arbitaryNumber_ == 0) {
            throw std::invalid_argument("Arbitrrary number for a Person cannot be zero.\n");
        }
    }

int main() {
    std::vector<int> v;
    v.push_back(1);

    try {
        Person andrei("andrei", "vacariu", 0);
        int j = v.at(99);
    } 
    catch(std::exception& e) { // more general block gets executed as it is the first one
        std::cout << e.what() << "\n";
    }
    catch(std::out_of_range & e) { // because this more explicit catch block is placed second it will not be executed
        std::cout << " out of range exception " << e.what() << "\n";
    }
    
    
    return 0;
}