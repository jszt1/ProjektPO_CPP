#include "../include/Sheep.h"

Sheep::Sheep(int xPos, int yPos, World* itsWorld) : Animal('S', xPos, yPos, 4, 4, itsWorld) {}
Organism* Sheep::getChild(int x, int y){
    return new Sheep(x, y, itsWorld);
}
