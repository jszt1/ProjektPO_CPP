#include "../include/SosnowskiHogweed.h"
#include "../include/World.h"
#include "../include/Animal.h"

SosnowskiHogweed::SosnowskiHogweed(int x, int y, World* world) : Plant('H',10, x, y, world) { }

Organism* SosnowskiHogweed::getChild(int x, int y){
    return new SosnowskiHogweed(x, y, itsWorld);
}

void SosnowskiHogweed::action(){
    std::vector<Pos> neighbours = getNeighbours();
    for(int i = 0; i < neighbours.size(); i++){
        Organism* other = itsWorld->getOrganismXY(neighbours[i].x, neighbours[i].y);
        if(other->isAnimal()){
            itsWorld->addLog(this, " poisoned his neighbour");
            itsWorld->killOrg(other);
        }
    }
    Plant::action();
}

void SosnowskiHogweed::colision(Organism* other){
    std::string otherName = typeid(*other).name();
    itsWorld->addLog(this, " poisoned " + otherName.erase(0, 1));
    itsWorld->killOrg(other);
    itsWorld->killOrg(this);
}