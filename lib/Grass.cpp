#include "../include/Grass.h"

Grass::Grass(int x, int y, World* itsWorld) : Plant('g', 0, x, y, itsWorld){ }

Organism* Grass::getChild(int x, int y){
    return new Grass(x, y, itsWorld);
}