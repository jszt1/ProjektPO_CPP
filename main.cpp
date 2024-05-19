#include <ncurses.h>

#include <cstdlib>
#include <iostream>

#include "include/World.h"

int main(int argc, char *argv[]) {
  World* cr;
  if(argc == 3){
    std::cout << atoi(argv[0]);
    cr = World::getWorld(atoi(argv[1]), atoi(argv[2]));
  }
  else if(argc == 1){
    cr = World::getWorld(20, 20);
  }
  else if(argc == 2){
    cr = World::getWorld("gameSaves/save1436004697.txt");
  }
  
  int i = 0;
  cr->printWorld();
  while(cr->getPlayerInput()){
    cr->doTheTurn();
    cr->printWorld();
  }
  return 0;
}