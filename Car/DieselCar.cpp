#include "DieselCar.h"
#include <iostream>

DieselCar :: DieselCar() : OilCar() { }

DieselCar :: DieselCar (int odo) : OilCar(0) { odometer = odo; }

DieselCar :: ~DieselCar() { }