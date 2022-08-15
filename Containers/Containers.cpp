#include "Resource.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::cout;

int main() {
    std::vector numbers { 0,1,2 }; //class template argument deduction -> only from c++17 otherwise std::vector<int>
    numbers.push_back(-2);
    numbers[0] = 3;
    int num = numbers[2];

    cout << "num = " << num << " & numbers[2] = " << numbers[2] << "\n";

    for (int i : numbers) {
        cout << i << "\n";
    }

    Resource r("local");
    {   // braces for scope
        cout << "-----------------------------1" << "\n";
        vector<Resource> resources;
        resources.push_back(r);
        cout << "-----------------------------2" << "\n";
        resources.push_back(Resource("first"));
        cout << "-----------------------------3" << "\n";
        resources.push_back(Resource("second"));
        cout << "-----------------------------4" << "\n";
    }
    cout << "-----------------------------5" << "\n";

    return 0;
    
}