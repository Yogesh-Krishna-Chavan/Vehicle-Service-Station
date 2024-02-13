#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
private:
    char manufacturer[50];
    char model[50];
    char vehicleNumber[20];

public:
    Vehicle(const char *manu, const char *mdl, const char *num);
    Vehicle() = default;
    const char *getManufacturer() const;
    const char *getModel() const;
    const char *getVehicleNumber() const;

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);
    friend std::istream &operator>>(std::istream &is, Vehicle &vehicle);
};
#endif