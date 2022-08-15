#include <iostream>
#include <vector>
#include <algorithm>

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

}