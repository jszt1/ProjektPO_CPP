#include "../include/Organism.h"

int Organism::getX() const { return x; }

int Organism::getY() const { return y; }
int Organism::getPower() const { return power; }
int Organism::getInitiative() const { return initiative; }
char Organism::getType() const { return orgType; }
Organism::Organism(World &w) : world(w) {}
Organism::Organism(World &w, char orgType, int x, int y, int power,
                   int initiative)
    : world(w), orgType(orgType), x(x), y(y), power(power),
      initiative(initiative) {}
World Organism::getWorld() const { return world; }
