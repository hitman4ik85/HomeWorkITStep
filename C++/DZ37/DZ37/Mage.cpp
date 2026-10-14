#include "Mage.h"

Mage::Mage(const string& name, int health, int hitChance, int attackPower, int pidsulenuiDamageChance, int maxPidsulenuiDamagePercent)
    : Character(name, health, hitChance, attackPower), pidsulenuiDamageChance(pidsulenuiDamageChance), maxPidsulenuiDamagePercent(maxPidsulenuiDamagePercent) {}

void Mage::attackMessage() {
    cout << name << " атакує магією!" << endl;
}

int Mage::calculateAttackPower() {
    if (tryEnhancedDamage()) {
        return attackPower + attackPower * maxPidsulenuiDamagePercent / 100;
    }
    return attackPower;
}

void Mage::receiveDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    if (health == 0) {
        defeatMessage();
    }
}

void Mage::defeatMessage() {
    cout << name << " був переможений!" << endl;
}

bool Mage::tryEnhancedDamage() {
    return rand() % 100 < pidsulenuiDamageChance;
}