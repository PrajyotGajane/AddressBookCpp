#include <iostream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
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
    bool duplicate = false;
    Person *person;
    cout << "Enter First Name: " << endl;
    cin >> first_name;
    cout << "Enter Last Name: " << endl;
    cin >> last_name;
    if (duplicate == duplicateContact(first_name + " " + last_name))
        return;
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
    cout << "\n\n"
         << endl;
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {
        cout << "\n"
             << endl;
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
    return nullptr;
}

bool AddressBookActions::duplicateContact(string name)
{
    Person *duplicate_person = findContact(name);
    if (duplicate_person == nullptr)
    {
        return true;
    }
    else
    {
        cout << "Contact already exists" << endl;
        return false;
    }
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

bool compareNames(Person *personOne, Person *personTwo)
{
    return (personOne->getFirstName() < personTwo->getFirstName());
}

struct compareByNames
{
    bool operator()(Person *toCompare, Person *toCompareWith)
    {
        return toCompare->getFirstName() < toCompareWith->getFirstName();
    }
};

struct compareByCity
{
    bool operator()(Person *toCompare, Person *toCompareWith)
    {
        return toCompare->getCity() < toCompareWith->getCity();
    }
};

struct compareByState
{
    bool operator()(Person *toCompare, Person *toCompareWith)
    {
        return toCompare->getState() < toCompareWith->getState();
    }
};

struct compareByZipcode
{
    
    bool operator()(Person *toCompare, Person *toCompareWith)
    {
        return toCompare->getZipcode() < toCompareWith->getZipcode();
    }
};

void
AddressBookActions::sortByName()
{
    contact_list.sort(compareByNames());
}

void AddressBookActions::sortByCity()
{
    contact_list.sort(compareByCity());
}

void AddressBookActions::sortByState()
{
    contact_list.sort(compareByState());
}

void AddressBookActions::sortByZipcode()
{
    contact_list.sort(compareByZipcode());
}

void AddressBookActions::chooseSort()
{
    cout << "1: By Name 2: By City 3: By State: 4: By Zipcode" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        sortByName();
        break;
    case 2:
        sortByCity();
        break;
    case 3:
        sortByState();
        break;
    case 4:
        sortByZipcode();
        break;
    default:
        break;
    }
    displayContacts();
}