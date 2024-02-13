#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <iostream>
#include <vector>
#include "SparePart.h"
#include "vehicle.h"
#include <fstream>

class ServiceRequest
{
private:
    char serviceStationName[50];
    char customerName[50];
    char vehicleDetails[100];
    char serviceDate[20];
    float maintenanceCharges;
    std::vector<SparePart> spareParts;
    float oilAdditivePrice;
    float billAmount;

public:
    ServiceRequest(const char *stationName, const char *custName, const char *vehicle,
                   const char *date, float maintenance, const std::vector<SparePart> &parts, float oilPrice);

    const char *getServiceStationName() const;
    const char *getCustomerName() const;
    const char *getVehicleDetails() const;
    const char *getServiceDate() const;
    float getMaintenanceCharges() const;
    const std::vector<SparePart> &getSpareParts() const;
    float getOilAdditivePrice() const;
    float getBillAmount() const;

    void calculateBillAmount();

    // Default constructor declaration...
    ServiceRequest();

    void saveToFile(const std::string &filename) const;
    static ServiceRequest loadFromFile(const std::string &filename);

    friend std::ostream &operator<<(std::ostream &os, const ServiceRequest &request);
};
#endif