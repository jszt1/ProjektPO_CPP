#include "../include/Antelope.h"
#include "../include/World.h"

Antelope::Antelope(int xPos, int yPos, World* itsWorld) : Animal('A', xPos, yPos, 4, 4, itsWorld) {}
Organism* Antelope::getChild(int x, int y){
    return new Antelope(x, y, itsWorld);
}

void Antelope::action(){
  // 0 1 2
  // 3 X 5
  // 6 7 6
  makeOlder();
  int checkX, checkY;
  std::vector<Pos> freePos = getFreePos();
//   if(freePos.size() > 0){
//     do{
//       checkX = rand() % 5 - 1 + getX();
//       checkY = rand() % 5 - 1 + getY();
//     } while(!setXY(checkX, checkY, false));
//   }
    while(freePos.size() > 0){
            int randPos = rand() % freePos.size();
            if(setXY(freePos[randPos].x, freePos[randPos].y, true)){
                break;
            }
            else{
                freePos.erase(freePos.begin() + randPos);
            }
    }
}

bool Antelope::canEscape(){
    bool escapeChance = rand() % 2;
    std::string logMsg = "";
    if(escapeChance){
        std::vector<Pos> freePos = getFreePos();
        while(freePos.size() > 0){
            int randPos = rand() % freePos.size();
            if(setXY(freePos[randPos].x, freePos[randPos].y, true)){
                logMsg += " has escaped!";
                return true;
            }
            else{
                freePos.erase(freePos.begin() + randPos);
            }
        }
        logMsg += " has no escape option...";  
    }
    return false;
}