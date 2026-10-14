#pragma once
#include <string>
#include <iostream>

struct BirthInfo {
    std::string dateOfBirth;
    std::string placeOfBirth;
};

struct Address {
    std::string city;
    std::string region;
    std::string street;
    int houseNumber;
    int apartmentNumber;
};

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string group;
    int grades[5];
    float attendancePercentage;
    BirthInfo birthInfo;
    Address address;

public:
    Student();

    Student(const std::string& firstName, const std::string& lastName, const std::string& group, const int grades[5],
        float attendancePercentage, const BirthInfo& birthInfo, const Address& address);

    void showInfo() const;

    void setStudentInfo(const std::string& firstName, const std::string& lastName, const std::string& group,
        const int grades[5], float attendancePercentage, const BirthInfo& birthInfo, const Address& address);

    float calculateAverageGrade() const;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGroup() const;
    std::string getRegion() const;
    std::string getDateOfBirth() const;
    bool isYoungerThan(int age) const;
};