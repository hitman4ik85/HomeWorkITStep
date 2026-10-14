#include "Sportsman.h"
using namespace std;

Sportsman::Sportsman() : firstName(""), lastName(""), age(0), gender(""), country("") {}
Sportsman::Sportsman(const string& fName, const string& lName, int a, const string& g, const string& c)
    : firstName(fName), lastName(lName), age(a), gender(g), country(c) {}

void Sportsman::printInfo() {
    cout << "Ім’я: " << firstName << endl;
    cout << "Прізвище: " << lastName << endl;
    cout << "Вік: " << age << endl;
    cout << "Стать: " << gender << endl;
    cout << "Країна: " << country << endl;
}

void Sportsman::setFirstName(const string& fName) {
    firstName = fName;
}

void Sportsman::setLastName(const string& lName) {
    lastName = lName;
}

void Sportsman::setAge(int a) {
    age = a;
}

void Sportsman::setGender(const string& g) {
    gender = g;
}

void Sportsman::setCountry(const string& c) {
    country = c;
}