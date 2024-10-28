#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {
private:
    int cargoCapacity;
public:
    CargoShip(std::string n, std::string y, int c) : Ship(n, y), cargoCapacity(c) {}
    void setCargoCapacity(int c) { cargoCapacity = c; }
    int getCargoCapacity() const { return cargoCapacity; }
    void print() const override {
        std::cout << "Cargo Ship Name: " << getName() << ", Cargo Capacity: " << cargoCapacity << " tons" << std::endl;
    }
};

#endif
