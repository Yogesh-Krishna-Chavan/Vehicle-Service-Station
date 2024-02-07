#ifndef SERVICESTATIONMANAGER_H
#define SERVICESTATIONMANAGER_H

#include <list>
#include <chrono>
#include "Customer.h"
#include "Bill.h"

class ServiceStationManager
{
public:
    void newCustomer();
    void newServicingRequest();
    void displayTodayBusiness();
    void loadCustomersFromFile(const std::string &filename);
    void storeCustomersToFile(const std::string &filename);
    std::list<Customer>::const_iterator findCustomerByName(const std::string &name) const;

private:
    std::list<Customer> customerList;
    std::list<Bill> billList;
};
#endif