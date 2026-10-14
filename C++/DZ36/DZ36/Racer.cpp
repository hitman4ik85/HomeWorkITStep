#include "Racer.h"
using namespace std;

Racer::Racer() : Sportsman(), team(""), wins(0), races(0) {}
Racer::Racer(const string& fName, const string& lName, int a, const string& g, const string& c,
    const std::string& t, int w, int r)
    : Sportsman(fName, lName, a, g, c), team(t), wins(w), races(r) {}

void Racer::printInfo() {
    Sportsman::printInfo();
    cout << "Команда: " << team << endl;
    cout << "Кількість перемог: " << wins << endl;
    cout << "Кількість проведених гонок: " << races << endl;
}

void Racer::setTeam(const string& t) {
    team = t;
}

void Racer::setWins(int w) {
    wins = w;
}

void Racer::setRaces(int r) {
    races = r;
}

double Racer::getEfficiency() {
    if (races == 0) return 0.0;
    return (wins * 1.0 / races) * 100;
}