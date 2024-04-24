#include "../include/Dandelion.h"
#include "../include/World.h"

Dandelion::Dandelion(int x, int y, World *world) : Plant('d', 0, x, y, world){ }

Organism* Dandelion::getChild(int x, int y){
    return new Dandelion(x, y, itsWorld);
}

void Dandelion::action(){
    for(int i = 0; i < 3; i++){
        Plant::action();
    }
}