#ifndef REPAIRING_H
#define REPAIRING_H

#include <iostream>
#include <list>
#include "SparePart.h"

class Repairing
{
private:
    char repairArea[50];
    double laborCharges;
    std::list<SparePart> replacedParts;

public:
    Repairing(const char *area, double charges);

    const char *getRepairArea() const;
    double getLaborCharges() const;

    void addReplacedPart(const SparePart &part);

    friend std::ostream &operator<<(std::ostream &os, const Repairing &repairing);
    friend std::istream &operator>>(std::istream &is, Repairing &repairing);
};
#endif