#include "../include/Human.h"
#include "../include/World.h"

Human::Human(int x, int y, World* world) : Animal('H', x, y, 5, 4, world){
}

int Human::getKY(){
    return kierunek.y;
}
int Human::getKX(){
    return kierunek.x;
}
void Human::setKY(int val){
    kierunek.y = val;
}
void Human::setKX(int val){
    kierunek.x = val;
}