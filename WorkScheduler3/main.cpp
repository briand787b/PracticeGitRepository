#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "WorkDay.h"
#include "Employee.h"
using namespace std;

enum Week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

int main()
{
    //Seed the random number generator only once
    unsigned seed = time(0);
    srand(seed);

    WorkDay sun(sunday);
    WorkDay mon(monday);
    WorkDay tue(tuesday);
    WorkDay wed(wednesday);
    WorkDay thu(thursday);
    WorkDay fri(friday);
    WorkDay sat(saturday);

    //Set an array of all employees
    const int SIZE = 10;
    Employee employees[SIZE];
    employees[0].setName("John Williams");
    employees[1].setName("Carl Junior");
    employees[2].setName("Matt Miller");
    employees[3].setName("Amy Mack");
    employees[4].setName("Paul Vargus");
    employees[5].setName("Carol Watts");
    employees[6].setName("Justin Stegus");
    employees[7].setName("Brad Daniels");
    employees[8].setName("Amanda Arnold");
    employees[9].setName("Joe Donald");

    sun.setEmployees(employees, SIZE);
    mon.setEmployees(employees, SIZE);
    tue.setEmployees(employees, SIZE);
    wed.setEmployees(employees, SIZE);
    thu.setEmployees(employees, SIZE);
    fri.setEmployees(employees, SIZE);
    sat.setEmployees(employees, SIZE);
    //find way to return the data for each shift
    sun.displayShift(4);
    mon.displayShift(6);
    tue.displayShift(6);
    wed.displayShift(6);
    thu.displayShift(6);
    fri.displayShift(7);
    sat.displayShift(7);

    cout << "=================================================================\n";

    for (int count = 0; count < SIZE; count++)
    {
        cout << employees[count].getName() << " has worked "
            << employees[count].getHoursToDate() << " hours this week.\n";
    }


    return 0;
}
