#include <iostream>
#include "Person.h"

using namespace std;

Person* addContact()
{
    Person *personObject = new Person("Prajyot", "Gajane", "Hno 3", "Margao", "Goa", 403601, 99223443345);
    return personObject;
}

void display(Person* person){
    person->display();
}

int main()
{
    cout << "Welcomem to Address Book Problem" << endl;
    Person *personObject = addContact();
    display(personObject);
    return 0;
}