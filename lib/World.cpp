#include "../include/World.h"
#include <iostream>
#include <typeinfo>
#include "../include/Wolf.h"

World::World(int width, int height) {
  x = width;
  y = height;
  gameTurn = 0;
  logsPos = 0;

  addOrganism(new Wolf(10, 10));
  logsPos = 0;
  initscr();
  start_color();

  logsView = newwin(MAX_LOGS_PER_PAGE + 2, 2 * (y + 2),
                    x + 2, 0);
  stats = newwin(y + 2, x + 2, 0, 22);
  gameMap = newwin(22, 22, 0, 0);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);

  wattron(gameMap, COLOR_PAIR(1));
  wattron(stats, COLOR_PAIR(2));
  wattron(logsView, COLOR_PAIR(3));

  refresh();
}

void World::addOrganism(Organism* org){
  organisms.push_back(org);
}

World* World::world = nullptr;

World* World::getWorld(){
    return world;
}

World* World::getWorld(int width, int height){
  if(world != nullptr){
    delete world;
  }
  world = new World(width, height);
  return world;
}

void World::clearWindows() {
  logsPos = 0;
  wclear(gameMap);
  wclear(stats);
  wclear(logsView);
}

void World::addBorders() {
  box(logsView, '-', '|');
  box(stats, '-', '|');
  box(gameMap, '-', '|');
}

WINDOW *World::getGameMap() { return gameMap; }
WINDOW *World::getLogsView() { return logsView; }
WINDOW *World::getStats() { return stats; }

void World::printGameMap() {
  mvwprintw(gameMap, 0, 2, "MAP");
  for (int i = 0; i < organisms.size(); i++) {
    organisms[i]->draw();
  }
  wrefresh(gameMap);
  // pass
}

void World::printStats() {
  mvwprintw(stats, 0, 2, "STATS");
  wrefresh(stats);
  // pass
}

void World::printLogs() {
  mvwprintw(logsView, 0, 2, "LOGS");
  for (int i = 0; i < logs.size(); i++) {
    //td::cout << "HAHAH";
    mvwprintw(logsView, i + 1, 1, "%s", logs[i].c_str());
  }
  wrefresh(logsView);
}

void World::printWorld() {
  clearWindows();
  addBorders();
  printGameMap();
  printLogs();
  printStats();
}

void World::doTheTurn(){
  //clearLogs();
  gameTurn++;
  for(int i = 0; i < organisms.size(); i++){
    //printf("%d", i);
    //printf("%s", typeid(*organisms[i]).name());
    organisms[i]->action();
  }
  // for(Organism* org : organisms){
  //   //org->action();
  // }
}

void World::clearLogs(){
  // while(!logs.empty()){
  //   delete logs.back();
  //   logs.pop_back();
  // }
}

void World::addLog(Organism* org, std::string &s) {
  std::string log = typeid(*org).name();
  std::cout << log + s;
  logs.push_back(log + s);
  //mvwprintw(logsView, logsPos + 1, 1, "%s", (log + s).c_str());
}

int World::getGameSizeX() const { return x; }
int World::getGameSizeY() const { return y; }
Organism *World::getOrganismXY(int xPos, int yPos){ 
  if(xPos < 0 || xPos >= x || yPos < 0 || yPos >= y){
    return nullptr;
  }
  else{
    //for(Organism* o : organisms){
      for(int i = 0; i < organisms.size(); i++){
      if(organisms[i]->getX() == xPos && organisms[i]->getY() == yPos){
        return organisms[i];
      }
    }
    return nullptr;
  }
}

World::~World() {
  endwin();
}
