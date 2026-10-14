#include <iostream>
#include <ctime>
#include <windows.h>
#include "Boos.h"
#include "Mage.h"
#include "Warrior.h"
using namespace std;

void battle(Character& attacker, Character& defender) {
    if (rand() % 100 < attacker.getHitChance()) {
        attacker.attackMessage();
        int damage = attacker.calculateAttackPower();
        cout << attacker.getName() << " знімє " << damage << " Hp у " << defender.getName() << "а!" << endl;
        defender.receiveDamage(damage);
    }
    else {
        cout << attacker.getName() << " не влучив!" << endl;
    }
}

void displayAllStatus(Character* characters[], int size) {
    for (int i = 0; i < size; i++) {
        characters[i]->displayStatus();
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    Boos boss("Дракон", 300, 70, 25, 20, 10);
    Warrior warrior("Воїн", 200, 75, 20, 30, 20);
    Mage mage("Чарівник", 150, 80, 15, 25, 30);

    Character* characters[] = { &warrior, &mage, &boss };

    cout << "< Початковий стан персонажів: >" << endl;
    displayAllStatus(characters, 3);

    while (boss.isAlive() && (warrior.isAlive() || mage.isAlive())) {
        for (int i = 0; i < 2; i++) {
            if (characters[i]->isAlive()) {
                battle(*characters[i], boss);
                if (!boss.isAlive()) break;
            }
        }
        if (boss.isAlive()) {
            battle(boss, *characters[rand() % 2]);
        }

        cout << "< Стан персонажів: >" << endl;
        displayAllStatus(characters, 3);
    }

    if (!boss.isAlive()) {
        cout << "Гравці перемогли!" << endl;
    }
    else {
        cout << "Бос переміг!" << endl;
    }

    return 0;
}