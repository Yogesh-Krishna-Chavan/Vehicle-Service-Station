// Repairing.cpp
#include "Repairing.h"
#include <cstring>

Repairing::Repairing(const char *area, double charges) : laborCharges(charges)
{
    strncpy(repairArea, area, sizeof(repairArea) - 1);
    repairArea[sizeof(repairArea) - 1] = '\0';
}

const char *Repairing::getRepairArea() const
{
    return repairArea;
}

double Repairing::getLaborCharges() const
{
    return laborCharges;
}

void Repairing::addReplacedPart(const SparePart &part)
{
    replacedParts.push_back(part);
}

std::ostream &operator<<(std::ostream &os, const Repairing &repairing)
{
    os << "Repair Area: " << repairing.repairArea << "\n";
    os << "Labor Charges: " << repairing.laborCharges << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Repairing &repairing)
{
    std::cout << "Enter Repair Area: ";
    is >> repairing.repairArea;
    std::cout << "Enter Labor Charges: ";
    is >> repairing.laborCharges;
    return is;
}
