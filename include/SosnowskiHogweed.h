#pragma once
#include "Plant.h"
class SosnowskiHogweed : public Plant{
    Organism* getChild(int x, int y);
public:
    SosnowskiHogweed(int x, int y, World*);
    void action();
    void colision(Organism*);
};