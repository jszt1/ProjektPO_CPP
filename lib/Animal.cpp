#include "../include/Animal.h"

#include <cstdlib>

void Animal::action() {
  // 0 1 2
  // 3 X 5
  // 6 7 6
  char randX = 0, randY = 0;
  while (randX + randY == 0) {
    randX = rand() % 3 - 1;
    randY = rand() % 3 - 1;
    char checkX = randX + getX();
    char checkY = randY + getY();
    if (checkX < 0 || checkX >= getWorld().getGameSizeX() || checkY < 0 ||
        checkY >= getWorld().getGameSizeY()) {
      checkX = randY = 0;
    }
  }
}

void Animal::colision() {
  // pass
}

void Animal::draw() {
  // poss
}

Animal::Animal(World &world) : Organism(world) {}
