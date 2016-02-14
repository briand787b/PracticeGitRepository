#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    public:
        Employee();
        Employee(int);
        virtual ~Employee();
        string getName() const;
        void setName(string);
        int getHoursMax() const;
        void addHours(double, double);
        int getHoursToDate();
    protected:
    private:
        string name;
        double hoursToDate;
        int hoursMax;
        static int overTimeEmps;
};

#endif // EMPLOYEE_H
