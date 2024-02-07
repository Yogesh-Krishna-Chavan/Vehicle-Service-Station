#include "SparePart.h"
#include <cstring>

SparePart::SparePart() : partCost(0.0)
{
    partName[0] = '\0';
}

SparePart::SparePart(const char *name, double cost) : partCost(cost)
{
    strncpy(partName, name, sizeof(partName) - 1);
    partName[sizeof(partName) - 1] = '\0';
}

const char *SparePart::getPartName() const
{
    return partName;
}

double SparePart::getPartCost() const
{
    return partCost;
}

std::ostream &operator<<(std::ostream &os, const SparePart &sparePart)
{
    os << "Part Name: " << sparePart.partName << "\n";
    os << "Part Cost: $" << sparePart.partCost << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, SparePart &sparePart)
{
    std::cout << "Enter Part Name: ";
    is >> sparePart.partName;
    std::cout << "Enter Part Cost: ";
    is >> sparePart.partCost;
    return is;
}
