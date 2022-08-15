#pragma once
#include <string>

class Resource {
    private:
        std::string name;
    public:
        Resource(std::string n);
        Resource(Resource const& r);
        Resource& operator=(Resource const& r);
        ~Resource(void);
        std::string getName() const { return name; }
};