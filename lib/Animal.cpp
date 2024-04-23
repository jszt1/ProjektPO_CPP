#include "../include/Animal.h"
#include "../include/World.h"

#include <cstdlib>

void Animal::action() {
  // 0 1 2
  // 3 X 5
  // 6 7 6
  makeOlder();
  int checkX, checkY;
  do{
    checkX = rand() % 3 - 1; + getX();
    checkY = rand() % 3 - 1; + getY();
  } while(setXY(checkX, checkY, false));
    
    // if(setXY(checkX, checkY, false)){
    //   //pass
    // }
    // else{
    //   //pass
    // }
}

void Animal::colision(Organism* other) {
  // pass
}

Animal::Animal(char orgType, int x, int y, int power,
               int initiative)
    : Organism(orgType, x, y, power, initiative) {}

