#include <ncurses.h>

#include <cstdio>

#include "include/World.h"

int main() {
  World* cr = World::getWorld(20, 20);
  int i = 0;
  while(i < 1000){
    cr->printWorld();
    napms(100);
    cr->doTheTurn();
    //getch();
  i++;
  }
  return 0;
}