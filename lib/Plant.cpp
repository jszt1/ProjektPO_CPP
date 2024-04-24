#include "../include/Plant.h"
#include "../include/World.h"

#include <vector>
#include <stdlib.h>

#define PLANT_MATURE_AGE 2

Plant::Plant(char orgType, int power, int x, int y, World *itsWorld) : Organism(orgType,  x, y, power, 0, itsWorld){}

void Plant::action(){
    makeOlder();
    if(getAge() > PLANT_MATURE_AGE){
        int probOfSpreading = rand() % 50;
        if(probOfSpreading == 0){
            std::vector<Pos> freePos = getFreePos();
            std::string logMsg = "";
            if(freePos.size() > 0){
                int randPos = rand() % freePos.size();
                createChild(freePos[randPos].x, freePos[randPos].y);
                logMsg += " zasial sie dalej.";
                itsWorld->addLog(this, logMsg);
            }
        }   
    }
    
}

#define ORG_THIS " (" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")"
#define ORG_OTHER std::to_string(other->getX()) + ", " + std::to_string(other->getY()) + ")"

void Plant::colision(Organism *other){
    std::string logMsg = "";
    if(getPower() >= other->getPower()){
        logMsg += ORG_THIS + " poisoned " + ORG_OTHER;
        itsWorld->killOrg(other);
        itsWorld->killOrg(this);
    }
    else{
        logMsg += ORG_OTHER + " has eaten " + ORG_THIS;
        itsWorld->killOrg(this);
    }
    itsWorld->addLog(this, logMsg);
}


void Plant::createChild(int x, int y){
    itsWorld->addOrganism(getChild(x, y));
}