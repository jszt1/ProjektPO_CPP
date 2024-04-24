#include "../include/Guarana.h"
#include "../include/World.h"

Guarana::Guarana(int x, int y, World* world) : Plant('G', 0, x, y, world) { }

void Guarana::colision(Organism* other){
    std::string otherName = typeid(*other).name();
    itsWorld->addLog(this, " empowered " + otherName);
    other->empower(3);
    itsWorld->killOrg(this);
}

Organism* Guarana::getChild(int x, int y){
    return new Guarana(x, y, itsWorld);
}