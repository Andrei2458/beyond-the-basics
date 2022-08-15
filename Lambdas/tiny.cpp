#include <iostream>
#include <vector>
#include <algorithm>
#include "Resource.hpp"
#include <memory>

int main() {
    auto isOdd = [](int candidate) {return candidate %2 != 0; };

    bool is3Odd = isOdd(3);
    std::cout << " 3 is odd : " << (is3Odd ? "true" : "false") << "\n";
    bool is2Odd = isOdd(2);
    std::cout << " 2 is odd : " << (is2Odd ? "true" : "false") << "\n";

    std::vector nums { 2,3,4,-1,1 };

    int odds = std::count_if(begin(nums), end(nums), isOdd);
    int evens = std::count_if(begin(nums), end(nums), 
        [](int elem) { return elem %2 == 0; });
    std::cout << "# of odd elems: " << odds << std::endl;
    std::cout << "# of even elems: " << evens << std::endl;

    ///////////////////

	//capturing by value and reference explicitly  [x,y,&message]

    int x = 3;
    int y = 7;

    std::string message = "\nelements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
    for_each(begin(nums), end(nums),
        [x, y, &message](int n) {
            if (n >= x && n <= y) {
                message += " " + std::to_string(n);
            }
        });
    message += "\n";
    std::cout << message;

    //////////////////////

    x = y = 0;
    // x by value, rest is by refference
    for_each(begin(nums), end(nums),
        [&, x](int elem) mutable {
            x += elem;
            y += elem;
        });
    
    std::cout << "x = " << x << "\n" << "y = " << y << "\n";

    //////////////////////
    // { // braces for scope
    //     auto pResource = std::make_unique<Resource>(", "); // a smart pointer that automatically clean itself up

    //     for_each(begin(nums), end(nums), 
    //         [=, &message, p = std::move(pResource)](int n) {
    //             if (n >= x && n <=y ) {
    //                 message += p->getName() + std::to_string(n);
    //             }
    //         });
        
    //     // pResource is not out of scope yet -> but it was moved to the lambda so it is empty now
    //     std::cout << "\nOut of for_each\n";
    // }
    // std::cout << "\nOut of scope from braces\n";

}