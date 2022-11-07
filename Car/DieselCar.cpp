#include "DieselCar.h"
#include <iostream>

DieselCar :: DieselCar() : OilCar() { }

DieselCar :: DieselCar(int odo) : Car(0), OilCar(0) { odometer = odo; }

DieselCar :: ~DieselCar() { }