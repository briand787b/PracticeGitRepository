#include "Employee.h"
#include <string>

Employee::Employee()
{
    hoursMax = 40;
    hoursToDate = 0;
}

Employee::Employee(int hoursDesired)
{
    hoursMax = hoursDesired;
}

Employee::~Employee()
{
    //dtor
}

string Employee::getName() const
{
    return name;
}

void Employee::setName(string n)
{
    name = n;
}

int Employee::getHoursMax() const
{
    return hoursMax;
}

void Employee::addHours(double starting, double ending)
{
    hoursToDate += ending - starting;
}

int Employee::getHoursToDate()
{
    return hoursToDate;
}
