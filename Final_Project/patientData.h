#ifndef PATIENTDATA_H
#define PATIENTDATA_H
#include "patient.h"

class patientData
{
    public:
        patientData();
        int AddPatient(int);
        void Update(int);
        int DeletePatient(int);
        void Diagnosis(int, int);//second one is for
        void Lookup(int);
        void SendInfo(int);
        void SendNoti(int);

};

#endif // PATIENTDATA_H
