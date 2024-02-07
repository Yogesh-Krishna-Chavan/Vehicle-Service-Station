// Bill.h
#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include "SparePart.h"
#include "ServiceRequest.h"

class Bill
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
    Bill(const ServiceRequest &request);

    const char *getServiceStationName() const;
    const char *getCustomerName() const;
    const char *getVehicleDetails() const;
    const char *getServiceDate() const;
    float getMaintenanceCharges() const;
    const std::vector<SparePart> &getSpareParts() const;
    float getOilAdditivePrice() const;
    float getBillAmount() const;

    void calculateBillAmount();

    friend std::ostream &operator<<(std::ostream &os, const Bill &bill);
};
#endif