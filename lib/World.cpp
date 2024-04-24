#include "../include/World.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include "../include/Organism.h"
#include "../include/Wolf.h"
#include "../include/Sheep.h"
#include "../include/Fox.h"
#include "../include/Turtle.h"
#include "../include/Antelope.h"
#include "../include/Grass.h"
#include "../include/Dandelion.h"

World::World(int width, int height) {
  x = width;
  y = height;
  gameTurn = 0;
  logsPos = 0;
  // new Sheep(10, 10, this);
  // new Sheep(11, 12, this);
  // new Wolf(10, 11, this);
  // new Wolf(12, 13, this);
  // new Wolf(12, 14, this);
  // // new Fox(14, 11, this);
  // new Fox(14, 12, this);
  //new Fox(14, 13, this);

  new Dandelion(15, 15, this);
  new Dandelion(7, 7, this);
  new Grass(10, 10, this);
  // new Turtle(14, 0, this);
  // new Turtle(14, 0, this);
  // new Turtle(14, 0, this);
  // new Antelope(0, 10, this);
  // new Antelope(13, 10, this);
  // new Antelope(11, 10, this);
  // logsPos = 0;
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
    if(organisms[i]->getType() == 'd'){
      logs.push_back(std::to_string(organisms[i]->getX()) + std::to_string(organisms[i]->getY()));
    }
  }
  wrefresh(gameMap);
  // pass
}

void World::printStats() {
  mvwprintw(stats, 0, 2, "STATS");
  int temp = organisms.size();
  mvwprintw(stats, 1, 1, "%d", temp);
  wrefresh(stats);
  // pass
}

void World::killOrg(Organism *toBeKilled){
  if(toBeKilled == nullptr){
    return;
  }
  for(int i = 0; i < organisms.size(); i++){
    if(organisms[i] == toBeKilled){
      organisms.erase(organisms.begin() + i);
      break;
    }
  }
}

void World::printLogs() {
  mvwprintw(logsView, 0, 2, "LOGS");
  for (int i = 0; i < logs.size(); i++) {
    //td::cout << "HAHAH";
    mvwaddstr(logsView, i + 1, 1, logs[i].c_str());
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
  clearLogs();
  gameTurn++;
  std::sort(organisms.begin(), organisms.end(), Organism::priority);
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
  logs.clear();
}

void World::addLog(Organism* org, std::string s) {
  std::string log = typeid(*org).name();
  //std::cout << typeid(log);
  log.substr(1, log.length());
  logs.push_back(log + s);
  //mvwprintw(logsView, logsPos + 1, 1, "%s", (log + s).c_str());
}

int World::getGameSizeX(){ return x; }
int World::getGameSizeY(){ return y; }
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
  for(int i = 0; i < organisms.size(); i++){
    delete organisms.back();
    organisms.pop_back();
  }
  endwin();
}
