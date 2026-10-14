#include "Boos.h"

Boos::Boos(const string& name, int health, int hitChance, int attackPower, int healChance, int maxHealPercent)
    : Character(name, health, hitChance, attackPower), healChance(healChance), maxHealPercent(maxHealPercent) {}

void Boos::attackMessage() {
    cout << name << " атакує вогнем!" << endl;
}

int Boos::calculateAttackPower() {
    return attackPower;
}

void Boos::receiveDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    if (health == 0) {
        defeatMessage();
    }
}

void Boos::defeatMessage() {
    cout << name << " був переможений!" << endl;
}

bool Boos::tryHeal() {
    if (rand() % 100 < healChance) {
        int healAmount = health * maxHealPercent / 100;
        health += healAmount;
        cout << name << " зцілився на " << healAmount << " Hp!" << endl;
        return true;
    }
    return false;
}