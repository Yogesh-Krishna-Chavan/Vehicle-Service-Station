#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <list>
#include "Vehicle.h"

class Customer
{
private:
    std::string name;
    std::string address;
    std::string mobileNumber;
    std::list<Vehicle> vehicles;

public:
    Customer(const std::string &nm, const std::string &addr, const std::string &mobile);

    Customer() = default;

    std::string getName() const;
    std::string getAddress() const;
    std::string getMobileNumber() const;
    const std::list<Vehicle> &getVehicles() const;

    void addVehicle(const Vehicle &vehicle);

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
    friend std::istream &operator>>(std::istream &is, Customer &customer);
};
#endif