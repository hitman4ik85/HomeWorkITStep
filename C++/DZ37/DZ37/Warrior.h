#pragma once
#include "Character.h"

class Warrior : public Character {
private:
    int blockChance;
    int maxBlockPercent;

public:
    Warrior(const string& name, int health, int hitChance, int attackPower, int blockChance, int maxBlockPercent);

    void attackMessage() override;
    int calculateAttackPower() override;
    void receiveDamage(int damage) override;
    void defeatMessage() override;

    bool tryBlock();
};