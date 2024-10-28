#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ship.h"

class CruiseShip : public Ship {
private:
    int maxPassengers;
public:
    CruiseShip(std::string n, std::string y, int m) : Ship(n, y), maxPassengers(m) {}
    void setMaxPassengers(int m) { maxPassengers = m; }
    int getMaxPassengers() const { return maxPassengers; }
    void print() const override {
        std::cout << "Cruise Ship Name: " << getName() << ", Max Passengers: " << maxPassengers << std::endl;
    }
};

#endif
