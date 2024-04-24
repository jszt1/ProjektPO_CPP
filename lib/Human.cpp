#include "../include/Human.h"
#include "../include/World.h"

Human::Human(int xPos, int yPos, World* world) : Animal('H', xPos, yPos, 5, 4, world){
    //this->abilityTimer = 0;
}

Organism* Human::getChild(int x, int y){
    return nullptr;
}

int Human::getAbilityTimer(){ return abilityTimer; }

void Human::action(){
    makeOlder();
    setXY(getX() + kierunek.x, getY() + kierunek.y, false);
    if(abilityTimer > 1){
        abilityTimer--;
    }
    else if(abilityTimer == 1){
        abilityTimer = -5;
    }
    else if(abilityTimer < 0){
        abilityTimer++;
    }
}

bool Human::canEscape(){
    std::string logMsg = "";
    if(abilityTimer > 0){
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

bool Human::selectMove(int key){
    switch(key){

        case KEY_UP:
            if(getY() > 0){
                setKXY(0, -1);
            }
            else{
                setKXY(0, 0);
            }
            break;
        case KEY_DOWN:
            if(getY() < itsWorld->getGameSizeY()){
                    setKXY(0, 1);
                }
                else{
                    setKXY(0, 0);
                }
                return true;
            break;
        case KEY_LEFT:
            if(getX() > 0){
                    setKXY(-1, 0);
                }
            else{
                setKXY(0, 0);
            }
            return true;
            break;
        case KEY_RIGHT:
            if(getX() < itsWorld->getGameSizeX()){
                    setKXY(1, 0);
                }
            else{
                setKXY(0, 0);
            }
            return true;
            break;
        case 's':
            if(abilityTimer == 0){
                abilityTimer = 5;
            }
            setKXY(0, 0);
            return true;
        case 'q':
            return false;
            break;
        default:
            return true;
            break;
  }
  return true;
}
void Human::setKXY(int x, int y){
    this->kierunek.x = x;
    this->kierunek.y = y;
}