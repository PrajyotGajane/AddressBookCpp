#pragma once
#include "Person.h"
class AddressBookActions
{
public:
    AddressBookActions();
    void addContact();
    void displayContacts();
    void editContact(string name);
    Person * findContact(string name);
    void deleteContact(string name);
    bool duplicateContact(string);
    void sortByName();
    void chooseSort();
    void sortByCity();
    void sortByState();
    void sortByZipcode();
    void chooseView();
    void searchBy();
};
