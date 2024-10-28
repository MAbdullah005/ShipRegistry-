#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>

class Ship {
private:
    std::string name;
    std::string yearBuilt;
public:
    Ship(std::string n, std::string y) : name(n), yearBuilt(y) {}
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
    void setYearBuilt(std::string y) { yearBuilt = y; }
    std::string getYearBuilt() const { return yearBuilt; }
    virtual void print() const {
        std::cout << "Ship Name: " << name << ", Year Built: " << yearBuilt << std::endl;
    }
};

#endif
