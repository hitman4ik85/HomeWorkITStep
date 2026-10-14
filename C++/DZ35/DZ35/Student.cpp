#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

// Конструктор без параметрів
Student::Student() : firstName("Невідомий"), lastName("Невідомий"), group("Невідомо"), grades{ 0 },
attendancePercentage(0.0f), birthInfo({ "01.01.2000", "Невідомо" }), address({ "Невідомо", "Невідомо", "Невідомо", 0, 0 }) {}

// Конструктор з параметрами
Student::Student(const std::string& firstName, const std::string& lastName, const std::string& group, const int grades[5],
    float attendancePercentage, const BirthInfo& birthInfo, const Address& address)
    : firstName(firstName), lastName(lastName), group(group), attendancePercentage(attendancePercentage), birthInfo(birthInfo), address(address) {
    std::copy(grades, grades + 5, this->grades);
}

// Метод виводу інформації про студента на екран
void Student::showInfo() const {
    std::cout << "Ім'я: " << firstName << "\n";
    std::cout << "Прізвище: " << lastName << "\n";
    std::cout << "Група: " << group << "\n";
    std::cout << "Оцінки за семестр: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << grades[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Відсоток відвіданих пар: " << attendancePercentage << "%" << std::endl;
    std::cout << "Дата народження: " << birthInfo.dateOfBirth << std::endl;
    std::cout << "Місце народження: " << birthInfo.placeOfBirth << std::endl;
    std::cout << "Адреса проживання: місто " << address.city << ", область " << address.region << ", вулиця " << address.street
        << ", будинок " << address.houseNumber << ", квартира " << address.apartmentNumber << std::endl;
}

void Student::setStudentInfo(const std::string& firstName, const std::string& lastName, const std::string& group,
    const int grades[5], float vidsotokZaniat, const BirthInfo& birthInfo, const Address& address) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->group = group;
    std::copy(grades, grades + 5, this->grades);
    this->attendancePercentage = vidsotokZaniat;
    this->birthInfo = birthInfo;
    this->address = address;
}

float Student::calculateAverageGrade() const {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0f;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getGroup() const {
    return group;
}

std::string Student::getRegion() const {
    return address.region;
}

std::string Student::getDateOfBirth() const {
    return birthInfo.dateOfBirth;
}

bool Student::isYoungerThan(int age) const {
    std::tm tm = {};
    std::istringstream ss(birthInfo.dateOfBirth);
    ss >> std::get_time(&tm, "%d.%m.%Y");
    std::time_t birthTime = std::mktime(&tm);
    std::time_t now = std::time(nullptr);
    double seconds = std::difftime(now, birthTime);
    double years = seconds / (60 * 60 * 24 * 365.25);
    return years < age;
}