#include "../include/Animal.h"
#include "../include/World.h"
#include <typeinfo>
#define MATURE_AGE 10


#include <stdlib.h>
#include <string>

void Animal::action() {
  // 0 1 2
  // 3 X 5
  // 6 7 6
  makeOlder();
  int checkX, checkY;
  std::vector<Pos> freePos = getFreePos();
  if(freePos.size() > 0){
    do{
      checkX = rand() % 3 - 1 + getX();
      checkY = rand() % 3 - 1 + getY();
    } while(!setXY(checkX, checkY, false));
  }
}

bool Animal::isAnimal(){
  return true;
}

void Animal::createChild(int x, int y){
  getChild(x, y);
}

#define ORG_THIS " (" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")"
#define ORG_OTHER std::to_string(other->getX()) + ", " + std::to_string(other->getY()) + ")"

void Animal::colision(Organism* other) {
  // pass
  std::string logMsg = "";
  if(this == other){
    return;
  }
  if(typeid(*this) == typeid(*other)){
    std::vector<Pos> freePos = getFreePos();
    if((getAge() > MATURE_AGE || other->getAge() > MATURE_AGE) && freePos.size() > 0){ 
      logMsg += ORG_THIS + " and " + ORG_OTHER " have a baby!";
      
      int randPos = rand() % freePos.size();
      createChild(freePos[randPos].x, freePos[randPos].y);
    }
  }
  else if(canEscape() || other->canEscape()){
    return;
  }
  else if(other->getType() == 'T' && getPower() < 5){
      logMsg += ORG_THIS + " ODPARL ATAK!!!";
      setXY(getPrevX(), getPrevY(), false);
  }
  else if(getPower() >= other->getPower()){
    logMsg += ORG_THIS + " killed " + ORG_OTHER;
    itsWorld->killOrg(other);
  }
  else{
    logMsg += ORG_OTHER + " killed " + ORG_THIS;
    itsWorld->killOrg(this);
  }
  itsWorld->addLog(this, logMsg);
}

Animal::Animal(char orgType, int x, int y, int power,
               int initiative, World* itsWorld)
    : Organism(orgType, x, y, power, initiative, itsWorld) {
    }

