// ServiceStationManager.cpp
#include "ServiceStationManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <limits>
#include <iomanip>
#include "Customer.h"

void ServiceStationManager::newCustomer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    std::cout << "Enter customer details:\n";
    std::string name, address, mobileNumber;

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Mobile Number: ";
    std::getline(std::cin, mobileNumber);

    Customer newCustomer(name, address, mobileNumber);

    // For simplicity, let's assume the customer can have only one vehicle
    std::cout << "Enter vehicle details:\n";
    Vehicle newVehicle("Toyota", "Camry", "ABC123");

    std::cin >> newVehicle;
    newCustomer.addVehicle(newVehicle);

    // Add the new customer to the list
    customerList.push_back(newCustomer);

    std::cout << "New customer added successfully!\n";
    std::cout << newVehicle;
}

void ServiceStationManager::newServicingRequest()
{
    // Get service request details from the user
    std::string stationName, custName, vehicleDetails, serviceDate;
    float maintenanceCharges, oilAdditivePrice;

    std::cout << "Enter Service Station Name: ";
    std::getline(std::cin >> std::ws, stationName);

    std::cout << "Enter Customer Name: ";
    std::getline(std::cin >> std::ws, custName);

    std::cout << "Enter Vehicle Number: ";
    std::getline(std::cin >> std::ws, vehicleDetails);

    std::cout << "Enter Service Date: ";
    std::getline(std::cin >> std::ws, serviceDate);

    std::cout << "Enter Maintenance Charges: $";
    std::cin >> maintenanceCharges;

    // Get spare parts details from the user
    std::vector<SparePart> spareParts;
    int numSpareParts;

    std::cout << "Enter the number of spare parts: ";
    std::cin >> numSpareParts;

    for (int i = 0; i < numSpareParts; ++i)
    {
        SparePart sparePart;
        std::cout << "Enter details for spare part " << i + 1 << ":\n";
        std::cin >> sparePart;
        spareParts.push_back(sparePart);
    }

    std::cout << "Enter Oil/Additive Price: $";
    std::cin >> oilAdditivePrice;

    // Create a new ServiceRequest object
    ServiceRequest newRequest(
        stationName.c_str(),
        custName.c_str(),
        vehicleDetails.c_str(),
        serviceDate.c_str(),
        maintenanceCharges,
        spareParts,
        oilAdditivePrice);

    // Add the new service request to the list
    billList.push_back(Bill(newRequest));

    std::cout << "New servicing request added successfully!\n";
}

void ServiceStationManager::displayTodayBusiness()
{
    // Get the current date
    auto today = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string todayStr = std::ctime(&today);

    // Remove the newline character from todayStr
    todayStr.erase(std::remove(todayStr.begin(), todayStr.end(), '\n'), todayStr.end());

    // Display today's date
    std::cout << "Today's Date: " << todayStr << "\n";

    // Iterate through the billList and calculate total cash collection
    float totalCashCollection = 0.0;
    for (const auto &bill : billList)
    {
        // Check if the bill's service date matches today's date
        if (std::string(bill.getServiceDate()) == todayStr)
        {
            totalCashCollection += bill.getBillAmount();
        }
    }

    // Display total cash collection
    std::cout << "Today's Cash Collection: $" << std::fixed << std::setprecision(2) << totalCashCollection << "\n";
}

void ServiceStationManager::loadCustomersFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    customerList.clear();

    while (file)
    {
        Customer customer;
        file >> customer;

        if (!file.fail())
        {
            customerList.push_back(customer);
        }
    }

    file.close();
}

void ServiceStationManager::storeCustomersToFile(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    for (const auto &customer : customerList)
    {
        file << customer;
    }

    file.close();
}

std::list<Customer>::const_iterator ServiceStationManager::findCustomerByName(const std::string &name) const
{
    return std::find_if(customerList.begin(), customerList.end(),
                        [&name](const Customer &customer)
                        { return customer.getName() == name; });
}