#ifndef PATIENT_H
#define PATIENT_H
#include <string.h>
#include <iostream>

using namespace std;

class patient
{
    public:
        char Name[25];
        float Weight;
        char Gender[6];
        char eyeColor[8];
        char hairColor[8];
        char Height[5];
        string Diagnosis;
        string Notes;
};

#endif // PATIENT_H
