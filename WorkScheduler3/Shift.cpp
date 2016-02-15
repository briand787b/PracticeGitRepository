#include "Shift.h"
#include <iostream>
#include <string>
using namespace std;

Shift::Shift()
{
    //ctor
}

Shift::~Shift()
{
    //dtor
}

void Shift::setName(string n)
{
    name = n;
}

//Enter in military time
void Shift::setShift(double starting, double ending)
{
    shiftStart = starting;
    shiftEnd = ending;
}

string Shift::getName()
{
    return name;
}

//************************************************************
//Function:  civTimeConv
//Purpose:  Converts the military time that the computer uses
//to civilian (12 hour) time.
//************************************************************
void Shift::civTimeConv()
{
    double temp1;
    if (shiftStart > 12.00)
        temp1 = shiftStart - 12.00;
    else
        temp1 = shiftStart;

    double temp2;
    if (shiftEnd > 12.00)
        temp2 = shiftEnd - 12.00;
    else
        temp2 = shiftEnd;

    int preColon1 = temp1;
    int preColon2 = temp2;

    int postcolon1 = (temp1 - preColon1) * 60;
    int postcolon2 = (temp2 - preColon2) * 60;

    if (postcolon1 == 0 && postcolon2 == 0)
        cout << preColon1 << ":00-" << preColon2 << ":00\n";
    else if (postcolon1 == 0 && postcolon2 != 0)
        cout << preColon1 << ":00-" << preColon2 << ":" << postcolon2 << endl;
    else if (postcolon1 != 0 && postcolon2 == 0)
        cout << preColon1 << ":" << postcolon1 << "-" << preColon2 << ":00\n";
    else
        cout << preColon1 << ":" << postcolon1 << "-" << preColon2 << ":" << postcolon2 << endl;
}

double Shift::getShiftStart()
{
    return shiftStart;
}

double Shift::getShiftEnd()
{
    return shiftEnd;
}
