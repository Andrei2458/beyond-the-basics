#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <iostream>
#include <vector>
#include <stdlib.h> // used for rand()
#include <list>
#include "ListAndVector.hpp"
using std::vector;
using std::list;

// template function
// calculates the execution time of a function
template <typename Func>
long long TimeFunc(Func f) {
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

template <typename T>
void exercise(int size, std::string commonname) {
    T v;
    T::template value_type res1("starting entry"); // value_type is some template magic
        // if T is a vector of int -> value_type is int; if T is a list of strings, value_type is string;
        // in this example, we know that the values stored in the collection can be initilized with a string
    v.push_back(res1);
    for (int i = 0; i < size; i++) {
        int r = (int)rand();
        string s;
        int ss = r % 100;
        s.reserve(ss);
    }
}

int main() {    
    return 0;
}
