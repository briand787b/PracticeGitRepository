#include "WorkDay.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

enum Week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

WorkDay::WorkDay(int dayType)
{
    switch(dayType)
    {
        case sunday:    dayName = "Sunday";
                        break;
        case monday:    dayName = "Monday";
                        break;
        case tuesday:   dayName = "Tuesday";
                        break;
        case wednesday: dayName = "Wednesday";
                        break;
        case thursday:  dayName = "Thursday";
                        break;
        case friday:    dayName = "Friday";
                        break;
        case saturday:  dayName = "Saturday";
                        break;
    }

    if (dayType == sunday)
    {
        dayStart = 10.00;
        dayEnd = 18.00;
        numShifts = 4;
        shiftArrPTR = new Shift[4];
        shiftArrPTR->setShift(9.00, 17.00);
        (shiftArrPTR+1)->setShift(9.00, 17.00);
        (shiftArrPTR+2)->setShift(11.00, 19.00);
        (shiftArrPTR+3)->setShift(11.00, 19.00);
    }
    else if (dayType > sunday && dayType < friday)
    {
        dayStart = 10.00;
        dayEnd = 21.50;
        numShifts = 6;
        shiftArrPTR = new Shift[6];
        shiftArrPTR->setShift(9.00, 17.00);
        (shiftArrPTR+1)->setShift(9.00, 17.00);
        (shiftArrPTR+2)->setShift(11.00, 19.00);
        (shiftArrPTR+3)->setShift(13.00, 21.00);
        (shiftArrPTR+4)->setShift(14.50, 22.50);
        (shiftArrPTR+5)->setShift(14.50, 22.50);
    }
    else if (dayType > thursday && dayType <= saturday)
    {
        dayStart = 10.00;
        dayEnd = 21.50;
        numShifts = 7;
        shiftArrPTR = new Shift[7];
        shiftArrPTR->setShift(9.00, 17.00);
        (shiftArrPTR+1)->setShift(9.00, 17.00);
        (shiftArrPTR+2)->setShift(11.00, 19.00);
        (shiftArrPTR+3)->setShift(12.00, 20.00);
        (shiftArrPTR+4)->setShift(13.00, 21.00);
        (shiftArrPTR+5)->setShift(14.50, 22.50);
        (shiftArrPTR+6)->setShift(14.50, 22.50);
    }
    else{
        cout << "Invalid input!!!\n";
    }
}

WorkDay::~WorkDay()
{
    //dtor
}

//***********************************************************
//Function:  setEmployees
//Purpose:  randomly assign different employees to all available
//shifts for that day, with no duplicates
//***********************************************************
void WorkDay::setEmployees(Employee* emp, int numEmps)
{
    //to keep a log of numbers already used
    int* logDynArr = new int[numShifts];
    int randNum;
    for (int count = 0; count < numShifts; count++)
    {
        do{
            randNum = (rand() % (numEmps));
        } while ((randNum == *logDynArr || randNum == *(logDynArr+1) || randNum == *(logDynArr+2)
                 || randNum == *(logDynArr+3) || randNum == *(logDynArr+4) || randNum == *(logDynArr+5))
                 || (emp+randNum)->getHoursToDate() >= 40);
        (shiftArrPTR+count)->setName((emp+randNum)->getName());
        *(logDynArr+count) = randNum;
        (emp+randNum)->addHours((shiftArrPTR+count)->getShiftStart(), (shiftArrPTR+count)->getShiftEnd());
    }
    delete logDynArr;
    logDynArr = NULL;
}

//**********************************************************
//Function:  displayShift
//Purpose:  display the names assigned to each shift
//for the workday
//**********************************************************
void WorkDay::displayShift(int shiftNum)
{
    cout << "\n\tShift Schedule\n";
    cout << "\t" << setw(10) << internal << getDayName() << endl;
    for (int i = 0; i < shiftNum; i++)
    {
        cout << setw(14) << left << (shiftArrPTR+i)->getName() << ":  ";
        (shiftArrPTR+i)->civTimeConv();
    }
}

string WorkDay::getDayName()
{
    return dayName;
}
