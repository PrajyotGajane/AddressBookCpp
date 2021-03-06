#include <iostream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <map>

#include "AddressBookActions.h"
#include "Person.h"
using namespace std;

list<Person *> contact_list;

map<string, string> mapCity;
map<string, string> mapState;

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
    string complete_name = first_name + " " + last_name;
    mapCity.insert(pair<string, string>(complete_name, city));
    mapState.insert(pair<string, string>(complete_name, state));
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

void AddressBookActions::sortByName()
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

void viewByCity()
{
    cout << "Contact" << "\t\t" << "City" << endl;
    for (auto key = mapCity.begin(); key != mapCity.end(); ++key)
    {
        cout << key->first
             << '\t' << key->second << '\n';
    }
}

void viewByState()
{
    cout << "Contact" << "\t\t" << "State" << endl;
    for (auto key = mapState.begin(); key != mapState.end(); ++key)
    {
        cout << key->first
             << '\t' << key->second << '\n';
    }
}

void AddressBookActions::chooseView()
{
    cout << "1: By City 2: By State" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        viewByCity();
        break;
    case 2:
        viewByState();
        break;
    default:
        break;
    }
}

void searchByCity()
{
    cout << "Enter the name of the city" << endl;
    string city;
    cin >> city;
    cout << "Contact" << "\t\t" << "City" << endl;
    for (auto key = mapCity.begin(); key != mapCity.end(); ++key)
    {
        if (key->second == city)
        {
            cout << key->first
                 << '\t' << key->second << '\n';
        }
    }
}

void searchState()
{
    cout << "Enter the name of the stete" << endl;
    string state;
    cin >> state;
    cout << "Contact" << "\t\t" << "State" << endl;
    for (auto key = mapState.begin(); key != mapState.end(); ++key)
    {
        if (key->second == state)
        {
            cout << key->first
                 << '\t' << key->second << '\n';
        }
    }
}

void AddressBookActions::searchBy()
{
    cout << "1: By City 2: By State" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        searchByCity();
        break;
    case 2:
        searchState();
        break;
    default:
        break;
    }
}
