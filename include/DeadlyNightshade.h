#pragma once
#include "Plant.h"
class DeadlyNightshade : public Plant{
    Organism* getChild(int x, int y);
public:
    DeadlyNightshade(int x, int y, World* world);
    void colision(Organism*);
    
};