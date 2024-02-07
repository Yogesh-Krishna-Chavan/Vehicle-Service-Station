#ifndef SPAREPART_H
#define SPAREPART_H

#include <iostream>

class SparePart
{
private:
    char partName[50];
    double partCost;

public:
    SparePart();
    SparePart(const char *name, double cost);

    const char *getPartName() const;
    double getPartCost() const;

    friend std::ostream &operator<<(std::ostream &os, const SparePart &sparePart);
    friend std::istream &operator>>(std::istream &is, SparePart &sparePart);
};
#endif