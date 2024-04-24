#include "../include/Fox.h"
#include <iostream>
#include <typeinfo>
#include "../include/World.h"

Fox::Fox(int xPos, int yPos, World* itsWorld) : Animal('F', xPos, yPos, 3, 7, itsWorld) {}
Organism* Fox::getChild(int x, int y){
    return new Fox(x, y, itsWorld);
}
void Fox::action(){
    makeOlder();
    int checkX, checkY;
    std::vector<Pos> freePos = getFreePos();
    std::cout << freePos.size();
    while(freePos.size() > 0){
        int randPos = rand() % freePos.size();
        Organism* other = itsWorld->getOrganismXY(freePos[randPos].x, freePos[randPos].y);
        if(other != nullptr && typeid(*this) == typeid(*other)){
            Animal::action();
        }
        if(other != nullptr){
            if(other->getPower() > getPower()){
                freePos.erase(freePos.begin() + randPos);
                break;
            }
            else if(setXY(freePos[randPos].x, freePos[randPos].y, false)){
                break;
            }
            else{
                freePos.erase(freePos.begin() + randPos);
            }
        }
        else{
            setXY(freePos[randPos].x, freePos[randPos].y, false);
        }
    }
}