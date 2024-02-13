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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter customer details:\n";
    std::string name, address, mobileNumber;

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Mobile Number: ";
    std::getline(std::cin, mobileNumber);

    Customer newCustomer(name, address, mobileNumber);

    std::cout << "Enter vehicle details:\n";
    Vehicle newVehicle;
    std::cin >> newVehicle;
    newCustomer.addVehicle(newVehicle);

    customerList.push_back(newCustomer);

    std::cout << "New customer added successfully!\n";
    std::cout << newVehicle;
}

void ServiceStationManager::displayCustomers(const std::string &customerName)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (customerName.empty())
    {
        std::cout << "Customer List:\n";
        for (const auto &customer : customerList)
        {
            std::cout << "Customer Name: " << customer.getName() << "\n";
            std::cout << "----------------------\n";
        }
        return;
    }

    auto it = findCustomerByName(customerName);

    if (it != customerList.end())
    {
        const auto &customer = *it;

        std::cout << "Customer Name: " << customer.getName() << "\n";
        std::cout << "Customer Address: " << customer.getAddress() << "\n";
        std::cout << "Customer Mobile Number: " << customer.getMobileNumber() << "\n";

        const std::list<Vehicle> vehicles = customer.getVehicles();
        for (const auto &vehicle : vehicles)
        {
            std::cout << "Manufacturer: " << vehicle.getManufacturer() << "\n";
            std::cout << "Model: " << vehicle.getModel() << "\n";
            std::cout << "Vehicle Number: " << vehicle.getVehicleNumber() << "\n";
        }

        std::cout << "----------------------\n";
    }
    else
    {
        std::cout << "Customer not found.\n";
    }
}

void ServiceStationManager::newServicingRequest()
{
    std::string stationName, custName, vehicleDetails, serviceDate;
    float maintenanceCharges, oilAdditivePrice;

    std::cout << "1. Existing Customer\n";
    std::cout << "2. New Customer\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {

        displayCustomers();
        std::cout << "Enter Customer Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, custName);

        std::cout << "Entered Customer Name: " << custName << "\n";

        auto it = findCustomerByName(custName);
        if (it != customerList.end())
        {
            std::cout << "Customer found in the list!\n";

            std::cout << "Customer Name in List: " << it->getName() << "\n";
        }
        else
        {
            std::cout << "Customer not found in the list.\n";
        }
    }
    else if (choice == 2)
    {

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter customer details:\n";
        std::string name, address, mobileNumber;

        std::cout << "Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);

        std::cout << "Address: ";
        std::getline(std::cin, address);

        std::cout << "Mobile Number: ";
        std::getline(std::cin, mobileNumber);

        Customer newCustomer(name, address, mobileNumber);

        std::cout << "Enter vehicle details:\n";
        Vehicle newVehicle("Toyota", "Camry", "ABC123");

        std::cin >> newVehicle;
        newCustomer.addVehicle(newVehicle);

        customerList.push_back(newCustomer);

        std::cout << "New customer added successfully!\n";
        custName = newCustomer.getName();
    }
    else
    {
        std::cout << "Invalid choice.\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Service Station Name: ";
    std::getline(std::cin >> std::ws, stationName);

    std::cout << "Enter Vehicle Number: ";
    std::getline(std::cin >> std::ws, vehicleDetails);

    std::cout << "Enter Service Date: ";
    std::getline(std::cin >> std::ws, serviceDate);

    std::cout << "Enter Maintenance Charges: $";
    std::cin >> maintenanceCharges;

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

    ServiceRequest newRequest(
        stationName.c_str(),
        custName.c_str(),
        vehicleDetails.c_str(),
        serviceDate.c_str(),
        maintenanceCharges,
        spareParts,
        oilAdditivePrice);

    billList.push_back(Bill(newRequest));

    std::cout << "New servicing request added successfully!\n";
}

void ServiceStationManager::displayTodayBusiness()
{

    auto today = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string todayStr = std::ctime(&today);

    todayStr.erase(std::remove(todayStr.begin(), todayStr.end(), '\n'), todayStr.end());

    std::cout << "Today's Date: " << todayStr << "\n";

    float totalCashCollection = 0.0;
    for (const auto &bill : billList)
    {

        if (std::string(bill.getServiceDate()) == todayStr)
        {
            totalCashCollection += bill.getBillAmount();
        }
    }

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

        const std::list<Vehicle> vehicles = customer.getVehicles();
        for (const auto &vehicle : vehicles)
        {
            file << vehicle;
        }
    }

    file.close();
}

std::list<Customer>::const_iterator ServiceStationManager::findCustomerByName(const std::string &name) const
{
    std::cout << "Entered Customer Name: " << name << "\n";

    auto it = std::find_if(customerList.begin(), customerList.end(),
                           [&name](const Customer &customer)
                           {
                               std::cout << "Comparing with List Customer Name: " << customer.getName() << "\n";
                               return customer.getName() == name;
                           });

    if (it != customerList.end())
    {
        std::cout << "Customer found in the list!\n";

        std::cout << "Customer Name in the List: " << it->getName() << "\n";
    }
    else
    {
        std::cout << "Customer not found in the list.\n";
    }

    return it;
}
