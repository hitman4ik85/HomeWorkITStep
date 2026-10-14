#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int hitChance;
    int attackPower;

public:
    Character(const string& name, int health, int hitChance, int attackPower);
    virtual ~Character() = default;

    string& getName();
    int getHealth();
    int getHitChance();

    virtual void attackMessage() = 0;
    virtual int calculateAttackPower() = 0;
    virtual void receiveDamage(int damage) = 0;
    virtual void defeatMessage() = 0;

    bool isAlive();
    void displayStatus();
};