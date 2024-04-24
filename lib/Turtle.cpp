#include "../include/Turtle.h"
#include <cstdlib>

Turtle::Turtle(int xPos, int yPos, World* itsWorld) : Animal('T', xPos, yPos, 2, 1, itsWorld) {}
Organism* Turtle::getChild(int x, int y){
    return new Turtle(x, y, itsWorld);
}


void Turtle::action(){
    int moveOrNot = rand() % 4;
    if(moveOrNot >= 2){
        Animal::action();
    }
    else{
        makeOlder();
    }
}