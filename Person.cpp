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

string Person::getFirstName(){
    return this->first_name;
}

string Person::getlastName(){
    return this->last_name;
}

string Person::getAddress(){
    return this->address;
}

string Person::getCity(){
    return this->city;
}

string Person::getState(){
    return this->state;
}

int Person::getZipcode(){
    return this->zip_code;
}

long long Person::getPhoneNumber(){
    return this->phone_number;
}