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

    void display();
};