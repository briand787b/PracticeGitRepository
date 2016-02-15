#ifndef WORKDAY_H
#define WORKDAY_H
#include "Employee.h"
#include "Shift.h"
#include <string>
#include <iostream>
using namespace std;

class WorkDay
{
    public:
        WorkDay(int);
        virtual ~WorkDay();
        void setEmployees(Employee*, int);
        void displayShift(int);
        string getDayName();
    protected:
    private:
        int numShifts;
        double dayStart;
        double dayEnd;
        Shift* shiftArrPTR;
        string dayName;
};

#endif // WORKDAY_H
