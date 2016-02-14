#ifndef SHIFT_H
#define SHIFT_H
#include <string>
using namespace std;

class Shift
{
    public:
        Shift();
        virtual ~Shift();
        void civTimeConv();
        void setName(string);
        string getName();
        void setShift(double, double);
        double getShiftStart();
        double getShiftEnd();
    protected:
    private:
        string name;
        double shiftStart;
        double shiftEnd;
};

#endif // SHIFT_H
