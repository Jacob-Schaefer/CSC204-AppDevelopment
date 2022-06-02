#include <iostream>
#include <string.h>
#include <fstream>
#include <cstddef>
#include "patientData.h"
#include "patient.h"
#include "doctorData.h"

using namespace std;


class Node {
    public:
    string data;
    Node * next;
};

void print_list(Node * n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void LinkedList();
int Settings(int);


int main()
{
    int patientCap;
    int usrIn = 0;
    int doctorCap;


    patientData pData;

    while(usrIn != 9)
    {
      cout << "#################################################" << endl;
      cout << endl;
      cout << "                     WELCOME" << endl;
      cout << endl;
      cout << "#################################################" << endl;
      cout << endl;

      cout << "Please select and option: " << endl;
      cout << "1. Add Patient Info" << endl;
      cout << "2. Update Patient Info" << endl;
      cout << "3. Delete Patient Info" << endl;
      cout << "4. Patient Diagnosis" << endl;
      cout << "5. Patient Lookup" << endl;
      cout << "6. Send Patient Info" << endl;
      cout << "7. Send Notification(WIP)" << endl;
      cout << "8. Hospital settings" << endl;
      cout << "9. Close Application" << endl;

      cout << endl;

      cin >> usrIn;

      switch(usrIn)
      {
        case 1:
           patientCap = pData.AddPatient(patientCap);
            break;
        case 2:
            pData.Update(patientCap);
            break;
        case 3:
            patientCap = pData.DeletePatient(patientCap);
            break;
        case 4:
            pData.Diagnosis(patientCap, doctorCap);
            break;
        case 5:
            pData.Lookup(patientCap);
            break;
        case 6:
            pData.SendInfo(patientCap);
            break;
        case 7:
            //pData.SendNoti(patientCap);
            break;
        case 8:
            doctorCap = Settings(doctorCap);
            break;
        case 9:
            return 1;
            break;
         default:
            cout << "Invalid entry" << endl;
            break;
      }

      cout << endl;

      cout << string( 100, '\n' );
    }

    return 0;
}

int Settings(int doctorCap)
{
    doctorData dData;

    int usrIn;
    while(usrIn != 4)
    {
        cout << "-----------------------------" << endl;
        cout << "           Settings.          " << endl;
        cout << "-----------------------------" << endl;

        cout << endl;
        LinkedList(); //Here's where I use a linked list
        cout << endl;
        cout << ": ";
        cin >> usrIn;

        switch(usrIn)
        {
            case 1:
                dData.patientCapacity();
                break;
            case 2:
                doctorCap = dData.addDoctors(doctorCap);
                break;
            case 3:
                dData.viewDoctors(doctorCap);
                break;
            case 4:
                break;
            default:
                cout << "Invalid entry" << endl;
                break;
          }
    }
  return doctorCap;
}

void LinkedList()
{
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;
    Node * forth = NULL;
    Node * tail = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    forth = new Node();
    tail = new Node();

    head->data = "Please Select and option \n";
    head->next = second;

    second->data = "1. Patient Capacity(WIP) \n";
    second->next = third;

    third->data = "2. Add doctors \n";
    third->next = forth;

    forth->data = "3. View doctors(WIP) \n";
    forth->next = tail;

    tail->data = "4. Return to Home \n";
    tail->next = NULL;

    print_list(head);
}


