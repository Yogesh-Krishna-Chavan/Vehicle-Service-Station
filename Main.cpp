#include "ServiceStationManager.h"
#include <iostream>
#include <limits>

int main()
{
    ServiceStationManager manager;
    const std::string customerDataFile = "E:\\SUNBEAM_OFFICIAL_TRAINING\\CPP LANGUAGE\\MINI PROJECTS\\Mini_Project\\Mini_Project\\customer_data.txt";
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

        // Handle valid choices
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
        case 4:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 4);

    manager.storeCustomersToFile(customerDataFile);
    return 0;
}