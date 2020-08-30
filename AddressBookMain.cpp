#include <iostream>
#include "Person.h"
#include "AddressBookActions.h"

using namespace std;

void performActions()
{
    AddressBookActions actionObject;
    bool endLoop = true;
    while (endLoop)
    {
        int choice;
        cout << "\n1: Add contact 2: Display Contacts" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            actionObject.addContact();
            break;
        case 2:
            actionObject.displayContacts();
        default:
            break;
        }
    }
}

int main()
{
    cout << "Welcomem to Address Book Problem" << endl;
    performActions();
    return 0;
}