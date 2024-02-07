#include <iostream>
#include <limits>
#include "Customer.h"
#include "bill.h"
#include "vehicle.h"

Customer::Customer(const std::string &nm, const std::string &addr, const std::string &mobile)
    : name(nm), address(addr), mobileNumber(mobile) {}

std::string Customer::getName() const
{
    return name;
}

std::string Customer::getAddress() const
{
    return address;
}

std::string Customer::getMobileNumber() const
{
    return mobileNumber;
}

void Customer::addVehicle(const Vehicle &vehicle)
{
    vehicles.push_back(vehicle);
}

std::ostream &operator<<(std::ostream &os, const Customer &customer)
{
    os << "Customer Name: " << customer.getName() << "\n";
    os << "Customer Address: " << customer.getAddress() << "\n";
    os << "Customer Mobile Number: " << customer.getMobileNumber() << "\n";
    // Output vehicles if needed
    return os;
}

std::istream &operator>>(std::istream &is, Customer &customer)
{
    // Implementation to read data into the Customer object
    is >> customer.name >> customer.address >> customer.mobileNumber;
    // Add any additional information you want to read

    return is;
}