#pragma once
#include "Character.h"

class Mage : public Character {
private:
    int pidsulenuiDamageChance;
    int maxPidsulenuiDamagePercent;

public:
    Mage(const string& name, int health, int hitChance, int attackPower, int enhancedDamageChance, int maxEnhancedDamagePercent);

    void attackMessage() override;
    int calculateAttackPower() override;
    void receiveDamage(int damage) override;
    void defeatMessage() override;

    bool tryEnhancedDamage();
};