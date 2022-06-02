#include "patientData.h"
#include "patient.h"
#include "doctorData.h"
#include <iostream>
#include <string.h>
#include <fstream>

patient patients[20];

using namespace std;
patientData::patientData()
{
    //ctor
}

int patientData::AddPatient(int patientCap)
{
    if(patientCap > sizeof(patients))
        cout << "Hospital is at full capacity." << endl;
    else
    {
        cout << "Enter patients name: ";
        cin >> patients[patientCap].Name;
        cout << "Enter Weight(in lbs): ";
        cin >> patients[patientCap].Weight;
        cout << "Enter Height(in Inches): ";
        cin >> patients[patientCap].Height;
        cout << "Male or Female: ";
        cin >> patients[patientCap].Gender;
        cout << "Eye color: ";
        cin >> patients[patientCap].eyeColor;
        cout << "Hair color: ";
        cin >> patients[patientCap].hairColor;
    }
        patientCap++;

        cout << string( 100, '\n' );

        return patientCap;
}

void patientData::Update(int patientCap)
{
    int k;
    int usrIn;
    char usrLoop = 'y';

    cout << "----------------------------" << endl;
    cout << " Select a patient to update." << endl;
    cout << "----------------------------" << endl;

    for(int i=0; i<patientCap;i++) //only prints out patients entered into system
    {
        cout << i << ". Patient: " << patients[i].Name << endl;
    }

    try
    {
        cin >> usrIn;
        throw usrIn;
    }
    catch(int e)
    {
        cout << "Exception has occurred. Input is char. " << endl;
    }

    if (usrIn < patientCap)
    {
        k = usrIn; //frees up usrIn

        cout << string( 100, '\n' );

       while(usrLoop == 'y'|| usrLoop == 'Y')
       {
        cout << "1. Name: " << patients[k].Name << endl;
        cout << "2. Weight: " << patients[k].Weight << endl;
        cout << "3. Height: " << patients[k].Height << endl;
        cout << "4. Gender: " << patients[k].Gender << endl;
        cout << "5. Eye Color: " << patients[k].eyeColor << endl;
        cout << "6. Hair Color: " << patients[k].hairColor << endl;
        cout << endl;
        cout << "Choose information to update: ";
        cin >> usrIn;
        cout << ":";

        switch(usrIn)
        {
        case 1:
            cin >> patients[k].Name;
            break;
        case 2:
            cin >> patients[k].Weight;
            break;
        case 3:
            cin >> patients[k].Height;
            break;
        case 4:
            cin >> patients[k].Gender;
            break;
        case 5:
            cin >> patients[k].eyeColor;
            break;
        case 6:
            cin >>patients[k].hairColor;
            break;
        default:
            cout << "Invalid entry" << endl;
            break;
        }
        cout << "Would you like to update again(y or n): ";
        cin >> usrLoop;
       }
    }
    else
        cout << "Invalid patient." << endl;

} //end of function

int patientData::DeletePatient(int patientCap)
{
    int usrIn;

    cout << "----------------------------" << endl;
    cout << " Select a patient to Delete." << endl;
    cout << "----------------------------" << endl;

    for(int i=0; i<patientCap;i++) //only prints out patients entered into system
    {
        cout << i << ". Patient: " << patients[i].Name << endl;
    }

    try
    {
        cin >> usrIn;
        throw usrIn;
    }
    catch(int e)
    {
        cout << "Exception has occurred. Input is char. " << endl;
    }

    patients[usrIn].Diagnosis = " ";
    patients[usrIn].Notes = " ";
    patients[usrIn].Name[0] = 0;
    patients[usrIn].Height[0] = 0;
    patients[usrIn].eyeColor[0] = 0;
    patients[usrIn].hairColor[0] = 0;
    patients[usrIn].Gender[0] = 0;
    patients[usrIn].Weight = 0;

    for(usrIn; usrIn<patientCap;usrIn++)
    {
         patients[usrIn] = patients[usrIn+1];
    }

    patientCap--;


    return patientCap;
} //end of function

void patientData::Diagnosis(int patientCap,int doctorCap)
{
    int usrIn;

    cout << "-------------------------------------------" << endl;
    cout << " Select a patient to add a Diagnosis too." << endl;
    cout << "-------------------------------------------" << endl;

    for(int i=0; i<patientCap;i++)
    {
        cout << i << ". Patient: " << patients[i].Name << endl;
    }

    try
    {
        cin >> usrIn;
        throw usrIn;
    }
    catch(int e)
    {
        cout << "Exception has occurred. Input is char. " << endl;
    }

    if (usrIn < patientCap)
    {
        cout << patients[usrIn].Name << ":";
        cin >> patients[usrIn].Diagnosis;
    }
    else
        cout << "Invalid patient choice." << endl;

    //patientAssignment(); you can implement this you just need to pass in patientCap, doctorCap, and iterate patients
} //end of function

void patientData::Lookup(int patientCap)
{

    char usrIn, usrLoop;
    char *pusrIn;


    cout << "----------------------------" << endl;
    cout << "          Look Up.          " << endl;
    cout << "----------------------------" << endl;

    cout << endl;

    do
    {
        cout << "Enter a letter to look up: ";
        cin >> usrIn;
        pusrIn = &usrIn; //sets pointer to usrIn address

        for(int i=0; i<patientCap; i++) //loops through patients
        {
            for(int j=0; j<sizeof(patients[i].Name[j]);j++) //loops through names of patients
            {
                if(*pusrIn == patients[i].Name[j]) //checks patient names against argument
                {
                    cout << "Patient: " << patients[i].Name << endl;
                    cout << "Diagnosis: " << patients[i].Diagnosis << endl;
                }
            }
        }
        cout << endl;
        cout << "Would you like to look-up again(y or n): ";
        cin >> usrLoop;
        if(usrLoop == 'y' || usrLoop == 'Y')
            cin >> usrIn;
    }while(usrLoop == 'y' || usrLoop == 'Y');

    cout << endl;


} //end of function

void patientData::SendInfo(int patientCap)
{
    string fileNameInput;
    int usrIn;

    cout << "------------------------------------" << endl;
    cout << " Select patient information to send." << endl;
    cout << "------------------------------------" << endl;

    for(int i=0; i<patientCap;i++)
    {
        cout << i << ". Patient: " << patients[i].Name << endl;
    }

    cin >> usrIn;

    cout <<"Please enter file name(.txt): ";
    cin >> fileNameInput;

    ofstream myfile;
    myfile.open(fileNameInput.c_str());
    if (myfile.is_open())
      {
        myfile << patients[usrIn].Name << endl;
        myfile << patients[usrIn].Weight << endl;
        myfile << patients[usrIn].Height << endl;
        myfile << patients[usrIn].Gender << endl;
        myfile << patients[usrIn].hairColor << endl;
        myfile << patients[usrIn].eyeColor << endl;
        myfile << patients[usrIn].Diagnosis << endl;
        myfile.close();
      }
    else cout << "Unable to open file";
} //end of function

void patientData::SendNoti(int patientCap)
{

    string fileNameInput;
    int usrIn;

    cout << "---------------------------------" << endl;
    cout << " Select patient to send note for." << endl;
    cout << "---------------------------------" << endl;

    for(int i=0; i<patientCap;i++)
    {
        cout << i << ". Patient: " << patients[i].Name << endl;
    }

    cin >> usrIn;

    cout <<"Please enter file name(.txt): ";
    cin >> fileNameInput;

    ofstream myfile;
    myfile.open(fileNameInput.c_str());
    if (myfile.is_open())
      {

        if (usrIn < patientCap)
        {
            cout << patients[usrIn].Name << ":";
            cin >> patients[usrIn].Notes;
        }
        myfile << patients[usrIn].Notes << endl;

        myfile.close();
      }
    else cout << "Unable to open file";
} //end of function
