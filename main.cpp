#include <ncurses.h>

#include <cstdio>

#include "include/World.h"

int main() {
  World* cr = World::getWorld(20, 20);
  int i = 0;
  while(i < 10){
  //cr->doTheTurn();
  //cr->printWorld();
  napms(1000);
  cr->doTheTurn();
  //getch();
  i++;
  }
  return 0;
}