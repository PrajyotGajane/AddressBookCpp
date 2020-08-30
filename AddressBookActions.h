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
};
