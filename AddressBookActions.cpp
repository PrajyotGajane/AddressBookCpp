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
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {
        cout << "\nName: " << (*contact_pointers)->getFirstName() << " " << (*contact_pointers)->getlastName() << endl;
        cout << "Address: " << (*contact_pointers)->getAddress() << endl;
        cout << "City: " << (*contact_pointers)->getCity() << endl;
        cout << "State: " << (*contact_pointers)->getState() << endl;
        cout << "Zipcode: " << (*contact_pointers)->getZipcode() << endl;
        cout << "Phone Number: " << (*contact_pointers)->getPhoneNumber() << endl;
    }
}