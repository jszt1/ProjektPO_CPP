#pragma once
#include "Animal.h"
#include "World.h"

class Human : public Animal{
    int abilityTimer;
    Pos kierunek;
    Organism* getChild(int x, int y);
public:
    Human(int x, int y, World*);
    void setKXY(int x, int y);
    bool canEscape();
    bool selectMove(int key);
    int getAbilityTimer();
    void activateSuperPower();
    void action();
};