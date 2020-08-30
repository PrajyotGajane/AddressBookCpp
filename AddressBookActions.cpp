#include <iostream>
#include <iostream>
#include <string>
#include <list>
#include "AddressBookActions.h"
#include "Person.h"
using namespace std;

list<Person *> contact_list;

AddressBookActions::AddressBookActions() {}

void AddressBookActions::addContact()
{
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    int zip_code;
    long long phone_number;
    Person *person;
    cout << "Enter First Name: " << endl;
    cin >> first_name;
    cout << "Enter Last Name: " << endl;
    cin >> last_name;
    cin.ignore();
    cout << "Enter Address: " << endl;
    getline(cin, address);
    cout << "Enter City: " << endl;
    cin >> city;
    cout << "Enter State: " << endl;
    cin >> state;
    cout << "Enter Zip code: " << endl;
    cin >> zip_code;
    cout << "Enter Phone number: " << endl;
    cin >> phone_number;
    person = new Person(first_name, last_name, address, city, state, zip_code, phone_number);
    contact_list.push_back(person);
}

void AddressBookActions::displayContacts()
{
    cout << "\n\n" << endl;
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {   
        cout << "\n" << endl;
        (*contact_pointers)->display();
    }
}

void AddressBookActions::editContact(string name)
{
    Person *edit_person = findContact(name);
    bool endLoop = true;
    int breakLoop = 2;
    do
    {
        int choice;
        cout << "Edit : \n1: Address 2: City 3: State 4: Zipcode 5: Phone number" << endl;
        cout << "Your input: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Current Address: " << (edit_person)->getAddress() << endl;
            cout << "New Address: " << endl;
            string address;
            cin.ignore();
            getline(cin, address);
            (edit_person)->setAddress(address);
            cout << "Updated address: " << (edit_person)->getAddress() << endl;
        }
        break;
        case 2:
        {
            cout << "Current city: " << (edit_person)->getCity() << endl;
            cout << "New City: " << endl;
            string city;
            cin >> city;
            (edit_person)->setCity(city);
            cout << "Updated city: " << (edit_person)->getCity() << endl;
        }
        break;
        case 3:
        {
            cout << "Current state: " << (edit_person)->getState() << endl;
            cout << "New state: " << endl;
            string state;
            cin >> state;
            (edit_person)->setState(state);
            cout << "Updated state: " << (edit_person)->getState() << endl;
        }
        break;
        case 4:
        {
            cout << "Current zipcode: " << (edit_person)->getZipcode() << endl;
            cout << "New zipcode: " << endl;
            int zip_code;
            cin >> zip_code;
            (edit_person)->setZipcode(zip_code);
            cout << "Updated Zipcode: " << (edit_person)->getZipcode() << endl;
        }
        break;
        case 5:
        {
            cout << "Current Phone number: " << (edit_person)->getPhoneNumber() << endl;
            cout << "New Phone number: " << endl;
            long long phone_number;
            cin >> phone_number;
            (edit_person)->setPhoneNumber(phone_number);
            cout << "Updated Phone Number: " << (edit_person)->getPhoneNumber() << endl;
        }
        break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
        cout << "Do you want edit more info: 1:Yes 2:No " << endl;
        int secondChoice;
        cin >> secondChoice;
        if (secondChoice == breakLoop)
        {
            endLoop = false;
        }
    } while (endLoop);
}

Person *AddressBookActions::findContact(string name)
{
    bool foundFlag = false;
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {
        string checkName = (*contact_pointers)->getFirstName() + " " + (*contact_pointers)->getlastName();
        if (checkName == name)
        {
            foundFlag = true;
            return *contact_pointers;
        }
    }
    if (!foundFlag)
    {
        cout << "Contact doesn't exist" << endl;
    }
    return nullptr;
}

void AddressBookActions::deleteContact(string name)
{
    Person *delete_person = findContact(name);
    contact_list.remove(delete_person);
    if (contact_list.size() <= 0)
        cout << "No contacts in the address book" << endl;
    else
        displayContacts();
}