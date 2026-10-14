#pragma once
#include "Sportsman.h"
using namespace std;

class Runner : public Sportsman {
private:
    double raceDistance;
    double bestTime;
    string mainSponsor;

public:
    Runner();
    Runner(const string& firstName, const string& lastName, int age, const string& gender, const string& country,
        double raceDistance, double bestTime, const string& mainSponsor);

    void printInfo();
    void setRaceDistance(double distance);
    void setBestTime(double time);
    void setMainSponsor(const string& sponsor);
    double getAverageSpeed();
};