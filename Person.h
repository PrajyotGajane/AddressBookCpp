#pragma once
#include <string>

using namespace std;

class Person
{
private:
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    int zip_code;
    long long phone_number;

public:
    Person(string first_name, string last_name, string address, string city, string state, int zip_code, long long phone_number);

    string getFirstName();
    string getlastName();
    string getCity();
    string getState();
    string getAddress();
    int getZipcode();
    long long getPhoneNumber();
    void display();
    void setAddress(string address);
    void setCity(string city);
    void setState(string state);
    void setZipcode(int zip_code);
    void setPhoneNumber(long long phone_number);
};