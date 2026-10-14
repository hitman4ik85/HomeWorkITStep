#include "Runner.h"
using namespace std;

Runner::Runner() : Sportsman(), raceDistance(0.0), bestTime(0.0), mainSponsor("") {}
Runner::Runner(const string& fName, const string& lName, int a, const string& g, const string& c,
    double distance, double time, const string& sponsor)
    : Sportsman(fName, lName, a, g, c), raceDistance(distance), bestTime(time), mainSponsor(sponsor) {}

void Runner::printInfo() {
    Sportsman::printInfo();
    cout << "Дистанція забігу: " << raceDistance << " км" << endl;
    cout << "Кращий час забігу: " << bestTime << " хв" << endl;
    cout << "Головний спонсор: " << mainSponsor << endl;
}

void Runner::setRaceDistance(double distance) {
    raceDistance = distance;
}

void Runner::setBestTime(double time) {
    bestTime = time;
}

void Runner::setMainSponsor(const string& sponsor) {
    mainSponsor = sponsor;
}

double Runner::getAverageSpeed() {
    if (bestTime == 0.0) return 0.0;
    return raceDistance / bestTime * 60;
}