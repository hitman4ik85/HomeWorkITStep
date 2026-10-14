#pragma once
#include "Sportsman.h"
using namespace std;

class Racer : public Sportsman {
private:
    string team;
    int wins;
    int races;

public:
    Racer();
    Racer(const string& firstName, const string& lastName, int age, const string& gender, const string& country,
        const string& team, int wins, int races);

    void printInfo();
    void setTeam(const string& team);
    void setWins(int wins);
    void setRaces(int races);
    double getEfficiency();
};