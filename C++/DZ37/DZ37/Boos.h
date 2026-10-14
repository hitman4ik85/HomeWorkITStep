#pragma once
#include "Character.h"

class Boos : public Character {
private:
    int healChance;
    int maxHealPercent;

public:
    Boos(const string& name, int health, int hitChance, int attackPower, int healChance, int maxHealPercent);

    void attackMessage() override;
    int calculateAttackPower() override;
    void receiveDamage(int damage) override;
    void defeatMessage() override;

    bool tryHeal();
};