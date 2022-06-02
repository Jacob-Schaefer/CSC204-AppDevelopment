#ifndef DOCTORDATA_H
#define DOCTORDATA_H
#include <string.h>
#include <iostream>

using namespace std;

class doctorData
{
    public:
        doctorData();
        void patientCapacity();
        int addDoctors(int);
        void viewDoctors(int);
        void patientAssignment(int);

};

#endif // DOCTORDATA_H
