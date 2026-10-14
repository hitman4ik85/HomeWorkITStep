#include "Warrior.h"

Warrior::Warrior(const string& name, int health, int hitChance, int attackPower, int blockChance, int maxBlockPercent)
    : Character(name, health, hitChance, attackPower), blockChance(blockChance), maxBlockPercent(maxBlockPercent) {}

void Warrior::attackMessage() {
    cout << name << " атакує мечем!" << endl;
}

int Warrior::calculateAttackPower() {
    return attackPower;
}

void Warrior::receiveDamage(int damage) {
    if (tryBlock()) {
        int blockedDamage = damage * maxBlockPercent / 100;
        damage -= blockedDamage;
        cout << name << " заблокував щитом, удар на " << blockedDamage << " Hp!" << endl;
    }
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    if (health == 0) {
        defeatMessage();
    }
}

void Warrior::defeatMessage() {
    cout << name << " був переможений!" << endl;
}

bool Warrior::tryBlock() {
    return rand() % 100 < blockChance;
}