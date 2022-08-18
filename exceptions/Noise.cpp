#include "Noise.hpp"
#include <iostream>

Noise::Noise(std::string sim) : soundIMake_(sim) {
    std::cout << "Constructing Noise " << soundIMake_ << "\n";
}

Noise::~Noise(void) {
    std::cout << "Destructing Noise  " << soundIMake_ << "\n";
}