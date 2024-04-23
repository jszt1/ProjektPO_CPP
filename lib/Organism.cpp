#include "../include/Organism.h"
#include "../include/World.h"

int Organism::getX() const { return x; }
void Organism::makeOlder(){ age++; }
int Organism::getY() const { return y; }
int Organism::getPower() const { return power; }
int Organism::getInitiative() const { return initiative; }
char Organism::getType() const { return orgType; }
void Organism::draw() const {
  mvwaddch(World::getWorld()->getGameMap(), 1 + y, 1 + x, orgType);
} 
bool Organism::setXY(int x, int y, bool forcedEmpty){
  if (x < 0 || x >= World::getWorld()->getGameSizeX() || y < 0 ||
        y >= World::getWorld()->getGameSizeY()) {
      return false;
  }
  //Organism* other = world->getOrganismXY(x, y);
  int lastPosX = this->x;
  int lastPosY = this->y;

  // if(forcedEmpty && other != nullptr){
  //   return false;
  // }

  this->x = x;
  this->y = y;
  // std::string moveMsg = " moved from (";
  // moveMsg.append(std::to_string(lastPosX));
  // moveMsg.append(",");
  // moveMsg.append(std::to_string(lastPosY));
  // moveMsg.append(") to (");
  // moveMsg.append(std::to_string(this->x));
  // moveMsg.append(", ");
  // moveMsg.append(std::to_string(this->y));
  // moveMsg.append(")");
  std::string moveMsg = " moved from (" + std::to_string(lastPosX) + "," 
                 + std::to_string(lastPosY) + ") to ("
                 + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
  world->addLog(this, moveMsg);
  // world->addLog(this, " moved from (" + std::to_string(lastPosX) + "," 
  //               + std::to_string(lastPosY) + ") to ("
  //               + std::to_string(this->x) + ", " + std::to_string(this->y) + ")");
  // if(other != nullptr){
  //   other->colision(this);
  // }
  return true;
}
Organism::Organism(char orgType, int x, int y, int power, int initiative) 
: orgType(orgType), x(x), y(y), power(power),
      initiative(initiative) {
        this->world = World::getWorld();
        this->age = 0;
      }
