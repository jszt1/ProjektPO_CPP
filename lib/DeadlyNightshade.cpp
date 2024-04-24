#include "../include/DeadlyNightshade.h"
#include "../include/World.h"

DeadlyNightshade::DeadlyNightshade(int x, int y, World* itsWorld) : Plant('n', 99, x, y, itsWorld) { }

Organism* DeadlyNightshade::getChild(int x, int y){
    return new DeadlyNightshade(x, y, itsWorld);
}

void DeadlyNightshade::colision(Organism *other){
    std::string otherName = typeid(*other).name();
    itsWorld->addLog(this, " poisoned " + otherName.erase(0,1));
    itsWorld->killOrg(other);
    itsWorld->killOrg(this);
}