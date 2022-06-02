#include <iostream>
#include <string.h>

using namespace std;

typedef struct employee
{
    char firstName[21];
    char lastName[21];
    int  age;
    char phoneNum[21];
    struct employee *nextptr;
    struct employee *prevptr;
} employee_t;

int main()
{
    employee_t * headptr = nullptr;
    employee_t * nodeptr = nullptr;
    employee_t * newptr = nullptr;
    employee_t * lastptr = nullptr;
    employee_t * tailptr = nullptr;
    char option;
    bool quit = false;
    char firstName[21];
    char lastName[21];
    char phoneNum[21];

    while ( quit == false )
    {

        cout << "Linked List using Structures" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. List Employees" << endl;
        cout << "3. List Employees(Backwards)" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Quit" << endl << endl;
        cout << "Enter Choice: ";
        cin >> option;

        switch ( option )
        {
            case '1':
            {
                newptr = ( employee_t * )malloc( sizeof( employee_t ));
                    if ( newptr != nullptr )
                    {
                        cout << "Enter First Name for New Employee: " << endl;
                        cin >> newptr->firstName;
                        cout << "Enter Last Name for New Employee: " << endl;
                        cin >> newptr->lastName;
                        cout << "Enter Age for New Employee: " << endl;
                        cin >> newptr->age;
                        cout << "Enter Phone-Number for New Employee: " << endl;
                        cin >> newptr->phoneNum;
                        newptr->nextptr = nullptr;
                        newptr->prevptr = nullptr;
                    }

                    if ( headptr == nullptr )
                    {
                        headptr = newptr;
                        tailptr = newptr;
                    }
                    else
                    {
                        nodeptr = headptr;
                        while ( nodeptr->nextptr != nullptr )
                        {
                            nodeptr = nodeptr->nextptr;
                        }
                        nodeptr->nextptr = newptr;
                        newptr->prevptr = nodeptr;
                        tailptr = newptr;
                    }
                    cout << "Node (" << newptr->firstName << " " << newptr->lastName << ") Added" << endl << endl;
            break;
            }
            case '2':
            {
                cout << "**** Current Employee List ****" << endl;
                nodeptr = headptr;

                while ( nodeptr != nullptr )
                {
                    cout << "Employee: " << nodeptr->lastName << ", " << nodeptr->firstName << " ("
                        << nodeptr->age << ")" << endl;
                    nodeptr = nodeptr->nextptr;
                }
                cout << endl << endl;
            break;
            }
            case '3':
            {
                cout << "**** Current Employee List ****" << endl;
                nodeptr = tailptr;

                while ( nodeptr != nullptr )
                {
                    cout << "Employee: " << nodeptr->lastName << ", " << nodeptr->firstName << " ("
                        << nodeptr->age << ")" << endl;
                    nodeptr = nodeptr->prevptr;
                }
                cout << endl << endl;
            break;
            }
            case '4':
            {
                bool found = false;

                cout << "**** Current Employe List ****" << endl;
                nodeptr = headptr;

                while ( nodeptr != nullptr )
                {
                    cout << "Employee: " << nodeptr->firstName << " " << nodeptr->lastName << " (" << nodeptr->phoneNum << ")" <<endl;
                    nodeptr = nodeptr->nextptr;
                }

                cout << "First Name of Employee to Delete: ";
                cin >> firstName;

                cout << "Last Name of Employee to Delete: ";
                cin >> lastName;

                cout << "Phone number of Employee to Delete: ";
                cin >> phoneNum;

                nodeptr = headptr;
                while (( nodeptr != nullptr ) && ( found == false ))
                {
                    if (( strcmp( firstName, nodeptr->firstName ) == 0 )
                    && ( strcmp( lastName, nodeptr->lastName ) == 0 )
                    && (strcmp (phoneNum, nodeptr->phoneNum) == 0 ))
                    {
                       if ( nodeptr == headptr )
                        {
                            // Node is first in the list
                            headptr = headptr->nextptr;
                            headptr->prevptr = nullptr;
                            free( nodeptr );
                        }
                        else if ( nodeptr->nextptr == nullptr )
                        {
                            tailptr = nodeptr->prevptr;
                            lastptr->nextptr = nullptr;
                            free (nodeptr);
                        }
                        else if (nodeptr->nextptr != nullptr )
                        {
                            lastptr->nextptr = nodeptr->nextptr;
                            lastptr->nextptr->prevptr = nodeptr->prevptr;
                            free( nodeptr );
                        }

                        found = true;
                    }
                    else
                    {
                        lastptr = nodeptr; //pre pre node in list
                        nodeptr = nodeptr->nextptr; //current node in list
                    }
                }
            break;
            }
            case '5':
                quit = true;
            break;

            default:
            break;
        }
    }
}
