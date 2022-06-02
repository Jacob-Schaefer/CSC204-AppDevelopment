#include "doctorData.h"
#include <iostream>
#include <string.h>
#include "patient.h"


struct doctor
{
    char Name[25];
    char Gender[6];
    char Specialty[30];
    string Patients[5];
    int patientlimit = 0;
};

doctor doctors[20];

using namespace std;

doctorData::doctorData()
{

}

void doctorData::patientCapacity()
{
    int usrIn = 0;

    cout << "Please set patient capacity: ";
    cin >> usrIn;

    //patient *movep = new patient[usrIn]
}

int doctorData::addDoctors(int doctorCap)
{
    if(doctorCap > 20)
        cout << "Full doctor capacity." << endl;
    else
    {
        cout << "Enter Doctors name: ";
        cin >> doctors[doctorCap].Name;
        cout << "Male or Female: ";
        cin >> doctors[doctorCap].Gender;
        cout << "Specialty: ";
        cin >> doctors[doctorCap].Specialty;

    }
        doctorCap++;

        cout << string( 100, '\n' );
}

void doctorData::viewDoctors(int doctorCap)
{
    for(int i=0; i<doctorCap;i++) //only prints out doctors entered into system
    {
        cout << i << ". Dr. " << doctors[i].Name << endl;
       /* for (int j=0; j<doctors[i].patientlimit;j++)
        {
           cout << j << ". " << doctors[i].Patients[j] << endl;//will be for displaying patients
        }*/

    }
}

/*void patientAssignment()
{
    for(int i =0; i<doctorCap;i++) //iterates doctors
    {
        for(int j=0; j<patientCap;j++) //iterates patients
        {
            if(doctors[i].Specialty == "General") //checks doctor speciality
            {
                if(patients[j].Diagnosis == "Cold")
                {
                    if(doctors[i].patientlimit < 5) //checks how many patients are assigned to doctor
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name; // assigns patient to doctor
                      doctors[i].patientlimit++;
                    }

                }
                else if(patients[j].Diagnosis == "Fever")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }
                }
                else if(patients[j].Diagnosis == "Physical")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }
                }
            }
            else if(doctors[i].Specialty == "Surgeon") // repeat of everything above
            {
               if(patients[j].Diagnosis == "Broken Bone")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }

                }
                else if(patients[j].Diagnosis == "Cancer")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }

                }
                else if(patients[j].Diagnosis == "Trauma")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }

                }
                else if(patients[j].Diagnosis == "Transplant")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }

                }
            }
            else if(doctors[i].Specialty == "Pediatrician")
            {
                if(patients[j].Diagnosis == "Child")
                {
                    if(doctors[i].patientlimit < 5)
                    {
                      doctors[i].Patients[doctors[i].patientlimit] = patients[j].Name;
                      doctors[i].patientlimit++;
                    }

                }
            }
        }
    }
}*/
