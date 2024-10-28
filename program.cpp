#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

int main() {
    Ship* ships[3];
    ships[0] = new Ship("Ocean Explorer", "1990");
    ships[1] = new CruiseShip("Luxury Cruiser", "2005", 2500);
    ships[2] = new CargoShip("Freight Master", "2010", 15000);
    for(int i = 0; i < 3; i++) {
        ships[i]->print();
        delete ships[i];
    }
    return 0;
}
