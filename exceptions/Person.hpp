#pragma once
#include <string>

class Person {
    private:
        std::string firstname_;
        std::string lastname_;
        int arbitaryNumber_;

    public:
        Person(std::string first, std::string last, int arbitary);
        Person();
        std::string getName() const { return firstname_ + " " + lastname_; };
        int getNum() const { return arbitaryNumber_; };
};