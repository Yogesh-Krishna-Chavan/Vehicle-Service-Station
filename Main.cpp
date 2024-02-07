// main.cpp
#include "ServiceStationManager.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>
#include <limits>

int main()

{
    ServiceStationManager manager;
    const std::string customerDataFile = "customer_data.txt"; // Change the filename as needed
    manager.loadCustomersFromFile(customerDataFile);

    int choice;
    do
    {
        // Display menu and get user choice
        std::cout << "1. New Customer\n2. New Servicing Request\n3. Today's Business\n4. Exit\n";
        std::cout << "Enter your choice: ";

        // Check for input failure and clear the input buffer
        while (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number.\n";
        }

        // Clear the newline character from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            manager.newCustomer();
            break;
        case 2:
            manager.newServicingRequest();
            break;
        case 3:
            manager.displayTodayBusiness();
            break;
            // Add more cases as needed
        }
    } while (choice != 4);

    manager.storeCustomersToFile(customerDataFile);
    return 0;
}