#include "ServiceRequest.h"
#include <cstring>

ServiceRequest::ServiceRequest(const char *stationName, const char *custName, const char *vehicle,
                               const char *date, float maintenance, const std::vector<SparePart> &parts, float oilPrice)
    : maintenanceCharges(maintenance), spareParts(parts), oilAdditivePrice(oilPrice)
{
    strncpy(serviceStationName, stationName, sizeof(serviceStationName) - 1);
    serviceStationName[sizeof(serviceStationName) - 1] = '\0';
    strncpy(customerName, custName, sizeof(customerName) - 1);
    customerName[sizeof(customerName) - 1] = '\0';
    strncpy(vehicleDetails, vehicle, sizeof(vehicleDetails) - 1);
    vehicleDetails[sizeof(vehicleDetails) - 1] = '\0';
    strncpy(serviceDate, date, sizeof(serviceDate) - 1);
    serviceDate[sizeof(serviceDate) - 1] = '\0';

    // Calculate bill amount
    calculateBillAmount();
}

const char *ServiceRequest::getServiceStationName() const
{
    return serviceStationName;
}

const char *ServiceRequest::getCustomerName() const
{
    return customerName;
}

const char *ServiceRequest::getVehicleDetails() const
{
    return vehicleDetails;
}

const char *ServiceRequest::getServiceDate() const
{
    return serviceDate;
}

float ServiceRequest::getMaintenanceCharges() const
{
    return maintenanceCharges;
}

const std::vector<SparePart> &ServiceRequest::getSpareParts() const
{
    return spareParts;
}

float ServiceRequest::getOilAdditivePrice() const
{
    return oilAdditivePrice;
}

float ServiceRequest::getBillAmount() const
{
    return billAmount;
}

void ServiceRequest::calculateBillAmount()
{
    float sparePartsCost = 0.0;
    for (const auto &part : spareParts)
    {
        sparePartsCost += part.getPartCost();
    }

    billAmount = maintenanceCharges + sparePartsCost + oilAdditivePrice;
    billAmount += (billAmount * 12.6) / 100.0; // Add 12.6% tax
}

std::ostream &operator<<(std::ostream &os, const ServiceRequest &request)
{
    os << "Service Station Name: " << request.serviceStationName << "\n";
    os << "Customer Name: " << request.customerName << "\n";
    os << "Vehicle Details: " << request.vehicleDetails << "\n";
    os << "Service Date: " << request.serviceDate << "\n";
    os << "Maintenance Charges: $" << request.maintenanceCharges << "\n";
    os << "Spare Parts:\n";
    for (const auto &part : request.spareParts)
    {
        os << part;
    }
    os << "Oil/Additive Price: $" << request.oilAdditivePrice << "\n";
    os << "Bill Amount: $" << request.billAmount << "\n";

    return os;
}
