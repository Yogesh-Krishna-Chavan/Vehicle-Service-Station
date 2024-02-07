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
    os << "Customer Name: " << customer.name << "\n";
    os << "Customer Address: " << customer.address << "\n";
    os << "Customer Mobile Number: " << customer.mobileNumber << "\n";
    // Output vehicles if needed
    return os;
}

std::istream &operator>>(std::istream &is, Customer &customer)
{
    std::cout << "Enter Customer Name: ";
    std::getline(is, customer.name);

    std::cout << "Enter Customer Address: ";
    std::getline(is, customer.address);

    std::cout << "Enter Customer Mobile Number: ";
    std::getline(is, customer.mobileNumber);

    if (is.fail())
    {
        // Handle input failure
        std::cerr << "Input error. Please enter valid data.\n";

        // Clear the input buffer
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return is;
}
