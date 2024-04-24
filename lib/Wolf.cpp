#include "../include/Wolf.h"

Wolf::Wolf(int xPos, int yPos, World* itsWorld) : Animal('W', xPos, yPos, 9, 5, itsWorld) {}
Organism* Wolf::getChild(int x, int y){
    return new Wolf(x, y, itsWorld);
}
