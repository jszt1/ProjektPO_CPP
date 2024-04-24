#pragma once
#include "Animal.h"
#include "World.h"

class Human : public Animal{
    int abilityTimer;
    Pos kierunek;
    Organism* getChild(int x, int y);
public:
    Human(int x, int y, World*);
    int getKY();
    int getKX();
    void setKY(int);
    void setKX(int);
    void activateSuperPower();
    int getAbilityTimer();
};