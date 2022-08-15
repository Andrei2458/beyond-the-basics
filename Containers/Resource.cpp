#include "Resource.hpp"
#include <iostream>

using std::cout; 
using std::string;

Resource::Resource(string n) : name(n) {
    cout << "Constructing " << name << "\n";
}

Resource::Resource(Resource const& r) : name(r.name) {
    cout << "Copy constructing " << name << "\n";
}

Resource& Resource::operator=(Resource const& r) {
    //if this class managed Resource lifetime, clean up existing one
	//before setting new values. No need here because string takes care of it
    name = r.getName();
    cout << "copy assigning " << name << "\n";
    return *this;
}

Resource::~Resource(void) {
    //if this class managed Resource lifetime, clean up existing one
	//No need here because string takes care of it
	cout << "destructing " << name << "\n";
}
