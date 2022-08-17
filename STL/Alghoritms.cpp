#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void printVector(std::vector<int> input) {
    auto start = begin(input);
    while (start != end(input)) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;
}

int main() {
    // populate an vector
    std::vector<int> v;

    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }
    auto start = begin(v);
    while(start!=end(v)) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;

    for (int i = 0; i < 5;) {
        v.push_back(i++);
    }

    start = begin(v);
    while(start!=end(v)) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;
    
    int i = 0;
    std::generate_n(std::back_inserter(v), 5, [&](){ return i++; });

    start = begin(v);
    while(start!=end(v)) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;


    //////////////////////////////
    // totalling all the elements
    int total = 0; 
    for (int i = 0; i < 15; i++) {
        total += v[i];
    }
    std::cout << "total: " << total << std::endl;

    int total_each = 0;
    for(int elem : v) {
        total_each += elem;
    }
    std::cout << "total_each: " << total_each << std::endl;

    int total_stl = std::accumulate(begin(v), end(v), 0);
    std::cout << "total_stl: " << total_stl << std::endl;

    // count # of 3s
    int count = 0;
    for (int i = 0; i < 15; i++) {
        if(v[i] == 3) {
            count++;
        }
    }
    std::cout << "count: " << count << "\n";

    int count_it = 0;
    for (auto it = begin(v); it != end(v); it++) {
        if(*it == 3) {
            count_it++;
        }
    }
    std::cout << "count_it: " << count_it << "\n";

    auto count_stl = std::count(begin(v), end(v), 3);
    std::cout << "count_stl: " << count_stl << "\n";
    
    ///////////////////
    // removing the 3s
    auto v2 = v;
    for (unsigned int index = 0; index < v2.size(); index++) {
        if(v2[index] == 3) {
            v2.erase(begin(v2)+index);
        }
    }
    printVector(v2);

    // It is not a good idea to use iterator of a collection that you alter 
    // auto v3 = v;
    // for (auto it = begin(v3); it != end(v3); it++) {
    //     if( *it == 3) {
    //         v3.erase(it);
    //     }
    // }
    // printVector(v3);
    
    auto v4 = v;
    // this leaves left-over elements that have to be erased later 
    // -> it returns an iterator to the new end of the vector(collection)
    auto newEnd = std::remove_if(begin(v4), end(v4), [](int elem){return elem == 3;});
    v4.erase(newEnd, end(v4));
    printVector(v4);

    // just 1 line
    auto v5 = v;
    v5.erase(std::remove_if(begin(v5), end(v5), [](int elem){ return elem == 3; }), end(v5));
    printVector(v5);

    v4.push_back(-2);
    v4.push_back(7);
    v4.push_back(0);
    v4.push_back(1);
    std::cout << "Added -2, 7, 0, 1: "; 
    printVector(v4);

    // sort v4
    sort(begin(v4), end(v4));
    std::cout << "Sorted: ";
    printVector(v4);

    std::cout << "Are all elements of v4 positive?\n";
    bool allPositive = std::all_of(begin(v4), end(v4), [](int elem) { return elem >= 0; });
    std::cout << "Answer: " << (allPositive ? "yes\n" : "no\n");

    // find first appearance of 'a'
    std::string s{"Hello, I am a sentence!"};
    auto letter = std::find(begin(s), end(s), 'a');
    std::cout << "a is followed by: " << *(++letter) << "\n";

    // how many capital casses in s?
    std::cout << "# of caps in the sentence: ";
    int caps = std::count_if(begin(s),end(s), [](char c){ return (c != ' ' && c != ',' || c != '!') && (toupper(c) == c); });
    std::cout << caps << "\n";
    
    return 0;
}