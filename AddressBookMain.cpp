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
        cout << "=====================================Main Menu=========================================" << endl;
        cout << "\n1: Add contact 2: Display Contacts 3:Edit info 4: Delete contact 5: Sort 6: View 7: Search 9:Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            actionObject.addContact();
            break;
        case 2:
            actionObject.displayContacts();
            break;
        case 3:
        {
            cout << "Enter the name of the contact you want to edit" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            actionObject.editContact(name);
        }
        break;
        case 4:
        {
            cout << "Enter the name of the contact you want to edit" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            actionObject.deleteContact(name);
        }
        break;
        case 5:
            actionObject.chooseSort();
        break;
        case 6:
            actionObject.chooseView();
        break;
        case 7:
            actionObject.searchBy();
            break;
        case 9:
            endLoop = false;
            break;
        default:
            cout << "Invalid Input" << endl;
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