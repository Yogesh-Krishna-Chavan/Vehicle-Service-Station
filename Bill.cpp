#include "Bill.h"
#include <cstring>
#include <iomanip>

Bill::Bill(const ServiceRequest &request)
    : maintenanceCharges(request.getMaintenanceCharges()),
      spareParts(request.getSpareParts()),
      oilAdditivePrice(request.getOilAdditivePrice())
{
    strncpy(serviceStationName, request.getServiceStationName(), sizeof(serviceStationName) - 1);
    serviceStationName[sizeof(serviceStationName) - 1] = '\0';
    strncpy(customerName, request.getCustomerName(), sizeof(customerName) - 1);
    customerName[sizeof(customerName) - 1] = '\0';
    strncpy(vehicleDetails, request.getVehicleDetails(), sizeof(vehicleDetails) - 1);
    vehicleDetails[sizeof(vehicleDetails) - 1] = '\0';
    strncpy(serviceDate, request.getServiceDate(), sizeof(serviceDate) - 1);
    serviceDate[sizeof(serviceDate) - 1] = '\0';

    calculateBillAmount();
}

const char *Bill::getServiceStationName() const
{
    return serviceStationName;
}

const char *Bill::getCustomerName() const
{
    return customerName;
}

const char *Bill::getVehicleDetails() const
{
    return vehicleDetails;
}

const char *Bill::getServiceDate() const
{
    return serviceDate;
}

float Bill::getMaintenanceCharges() const
{
    return maintenanceCharges;
}

const std::vector<SparePart> &Bill::getSpareParts() const
{
    return spareParts;
}

float Bill::getOilAdditivePrice() const
{
    return oilAdditivePrice;
}

float Bill::getBillAmount() const
{
    return billAmount;
}

void Bill::calculateBillAmount()
{
    float sparePartsCost = 0.0;
    for (const auto &part : spareParts)
    {
        sparePartsCost += part.getPartCost();
    }

    billAmount = maintenanceCharges + sparePartsCost + oilAdditivePrice;
    billAmount += (billAmount * 12.6) / 100.0;
}

std::ostream &operator<<(std::ostream &os, const Bill &bill)
{
    os << "Service Station Name: " << bill.serviceStationName << "\n";
    os << "Customer Name: " << bill.customerName << "\n";
    os << "Vehicle Details: " << bill.vehicleDetails << "\n";
    os << "Service Date: " << bill.serviceDate << "\n";
    os << "Maintenance Charges: $" << bill.maintenanceCharges << "\n";
    os << "Spare Parts:\n";
    for (const auto &part : bill.spareParts)
    {
        os << part;
    }
    os << "Oil/Additive Price: $" << bill.oilAdditivePrice << "\n";
    os << "Bill Amount: $" << std::fixed << std::setprecision(2) << bill.billAmount << "\n";

    return os;
}
