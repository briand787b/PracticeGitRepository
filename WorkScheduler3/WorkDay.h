#ifndef WORKDAY_H
#define WORKDAY_H
#include "Employee.h"
#include "Shift.h"
#include <string>
#include <iostream>
using namespace std;

//struct Shift{
//    string name;
//    double shiftStart;
//    double shiftEnd;
//};

class WorkDay
{
    public:
        WorkDay(int);
        virtual ~WorkDay();
        //void daySettings(int);
        //void shiftArrSetter();
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
        //Employee* empArrPTR;
};

#endif // WORKDAY_H
