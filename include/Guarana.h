#pragma once
#include "Plant.h"

class Guarana : public Plant{
    Organism* getChild(int x, int y);
public:
    Guarana(int x, int y, World*);
    void colision(Organism* other);
};