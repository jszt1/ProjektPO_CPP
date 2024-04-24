#include "../include/Organism.h"
#include "../include/World.h"

int Organism::getX() const { return x; }
void Organism::makeOlder(){ age++; }
int Organism::getY() const { return y; }
int Organism::getPrevX() const { return prevX; }
int Organism::getPrevY() const { return prevY; }
int Organism::getPower() const { return power; }
int Organism::getInitiative() const { return initiative; }
char Organism::getType() const { return orgType; }
int Organism::getAge() const { return age; }
void Organism::draw(){
  mvwaddch(itsWorld->getGameMap(), 1 + y, 1 + x, orgType);
} 
bool Organism::isAnimal(){
  return false;
}

bool Organism::setXY(int x, int y, bool forcedEmpty){
  if (x < 0 || x >= itsWorld->getGameSizeX() || y < 0 ||
        y >= itsWorld->getGameSizeY()) {
      return false;
  }
  Organism* other = itsWorld->getOrganismXY(x, y);
  this->prevX = this->x;
  this->prevY = this->y;

  if(forcedEmpty && other != nullptr){
    return false;
  }

  this->x = x;
  this->y = y;
  std::string moveMsg = " moved from (" + std::to_string(this->prevX) + "," 
                 + std::to_string(this->prevY) + ") to ("
                 + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
  this->itsWorld->addLog(this, moveMsg);
  if(other != nullptr){
    other->colision(this);
  }
  return true;
}

void Organism::goBack(){
  setXY(prevX, prevY, false);
}

void Organism::empower(int val){
  power += val;
}

bool Organism::canEscape(){
  return false;
}

std::string Organism::toString(){
  std::string name = typeid(*this).name();
  name.erase(0, 1);
  return name + " " + std::to_string(getX()) + " " + std::to_string(getY());
}

#define MAX_POS_TO_MOVE 8
vector<Pos> Organism::getNeighbours(){
  std::vector<Pos> temp;
  Pos tempPos;
  for(int i = 0; i < MAX_POS_TO_MOVE; i++){
    tempPos.x = getX() + i / 3 - 1;
    tempPos.y = getY() + i % 3 - 1;
    if(tempPos.x < itsWorld->getGameSizeX() && tempPos.x >= 0 
    && tempPos.y < itsWorld->getGameSizeY() && tempPos.y >= 0
    && itsWorld->getOrganismXY(tempPos.x, tempPos.y)
    ){
      temp.push_back(tempPos);
    }
  }
  return temp;
}

std::vector<Pos> Organism::getFreePos(){
  std::vector<Pos> freePos;
  Pos tempPos;
  for(int i = 0; i < MAX_POS_TO_MOVE; i++){
    tempPos.x = getX() + i / 3 - 1;
    tempPos.y = getY() + i % 3 - 1;
    if(tempPos.x < itsWorld->getGameSizeX() && tempPos.x >= 0 
    && tempPos.y < itsWorld->getGameSizeY() && tempPos.y >= 0
    && !itsWorld->getOrganismXY(tempPos.x, tempPos.y)
    ){
      freePos.push_back(tempPos);
    }
  }
  return freePos;
}

bool Organism::priority(Organism* first, Organism* second){
  if(first->initiative > second->initiative){
    return 1;
  }
  else if(first-> initiative < second->initiative){
    return 0;
  }
  else{
    if(first->age > second->age){
      return 1;
    }
    else{
      return 0;
    }
  }
}


Organism::Organism(char orgType, int x, int y, int power, int initiative, World* itsWorld, int age) 
: orgType(orgType), x(x), y(y), power(power),
      initiative(initiative) {
        this->itsWorld = itsWorld;
        this->age = age;
        itsWorld->addOrganism(this);
      }