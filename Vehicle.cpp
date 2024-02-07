#include "Vehicle.h"
#include <cstring>

Vehicle::Vehicle(const char *manu, const char *mdl, const char *num)
{
    strncpy(manufacturer, manu, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
    strncpy(model, mdl, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
    strncpy(vehicleNumber, num, sizeof(vehicleNumber) - 1);
    vehicleNumber[sizeof(vehicleNumber) - 1] = '\0';
}

const char *Vehicle::getManufacturer() const
{
    return manufacturer;
}

const char *Vehicle::getModel() const
{
    return model;
}

const char *Vehicle::getVehicleNumber() const
{
    return vehicleNumber;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << "Manufacturer: " << vehicle.manufacturer << "\n";
    os << "Model: " << vehicle.model << "\n";
    os << "Vehicle Number: " << vehicle.vehicleNumber << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Vehicle &vehicle)
{
    std::cout << "Enter Manufacturer: ";
    is >> vehicle.manufacturer;
    std::cout << "Enter Model: ";
    is >> vehicle.model;
    std::cout << "Enter Vehicle Number: ";
    is >> vehicle.vehicleNumber;
    return is;
}
