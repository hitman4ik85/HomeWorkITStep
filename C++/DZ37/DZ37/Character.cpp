#include "Character.h"

Character::Character(const string& name, int health, int hitChance, int attackPower)
    : name(name), health(health), hitChance(hitChance), attackPower(attackPower) {}

string& Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getHitChance() {
    return hitChance;
}

bool Character::isAlive() {
    return health > 0;
}

void Character::displayStatus() {
    cout << name << " - Hp: " << health << endl;
}