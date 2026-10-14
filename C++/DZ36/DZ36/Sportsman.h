#pragma once
#include <string>
#include <iostream>
using namespace std;

class Sportsman {
protected:
    string firstName;
    string lastName;
    int age;
    string gender;
    string country;

public:
    Sportsman();
    Sportsman(const string& firstName, const string& lastName, int age, const string& gender, const string& country);

    void printInfo();
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setAge(int age);
    void setGender(const string& gender);
    void setCountry(const string& country);
};