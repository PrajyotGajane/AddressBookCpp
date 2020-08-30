#include "Person.h"
#include<iostream>
using namespace std;

Person::Person(string first_name, string last_name, string address, string city, string state, int zip_code, long long phone_number)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip_code = zip_code;
    this->phone_number = phone_number;
}

void Person::display(){
    cout <<  "Name: " << this->first_name << " " << this->last_name <<
            "\nAddress: " << this->address <<
            "\nCity: " << this->city <<
            "\nState: " << this->state <<
            "\nZipcode: " << this->zip_code <<
            "\nPhone Number: " << this->phone_number << endl;
}