#include "../include/World.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include "../include/Organism.h"
#include "../include/Wolf.h"
#include "../include/Sheep.h"
#include "../include/Fox.h"
#include "../include/Turtle.h"
#include "../include/Antelope.h"
#include "../include/Grass.h"
#include "../include/Guarana.h"
#include "../include/Dandelion.h"
#include "../include/DeadlyNightshade.h"
#include "../include/SosnowskiHogweed.h"
#include "../include/Human.h"

using namespace std;

World::World(int width, int height) {
  x = width;
  y = height;
  // new Sheep(10, 10, this);
  // new Sheep(11, 12, this);
   
  // new Grass(10, 10, this);
  //new SosnowskiHogweed(12, 12, this);
  //new SosnowskiHogweed(14, 14, this);
  // new Turtle(14, 0, this);
  // new Turtle(14, 0, this);
  // new Turtle(14, 0, this);
  // new Antelope(0, 10, this);
  // new Antelope(13, 10, this);
  // new Antelope(11, 10, this);
  // logsPos = 0;
  initscr();
  start_color();
  noecho();
  curs_set(0);
  cbreak();
  srand(time(NULL));
  keypad(stdscr, TRUE);
  logsView = newwin(MAX_LOGS_PER_PAGE + 2, 2 * (y + 2),
                    x + 2, 0);
  stats = newwin(y + 2, x + 2, 0, x + 2);
  gameMap = newwin(y + 2, x + 2, 0, 0);

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

void World::insertOrganismAtEmptySpace(string orgName){
  int xRandPos, yRandPos;
  xRandPos = rand() % x;
  yRandPos = rand() % y;
  while(getOrganismXY(xRandPos, yRandPos)){
    xRandPos = rand() % x;
    yRandPos = rand() % y;
  }
  this->findOrganismAndCreate(orgName, xRandPos, yRandPos);
}


World* World::getWorld(int width, int height){
  if(world != nullptr){
    delete world;
  }
  world = new World(width, height);
  world->gameTurn = 0;
  world->logsPos = 0;
  int xRandPos, yRandPos;
  world->insertOrganismAtEmptySpace("Wolf");
  world->insertOrganismAtEmptySpace("Wolf");
  world->insertOrganismAtEmptySpace("Wolf");
  world->insertOrganismAtEmptySpace("Dandelion");
  world->insertOrganismAtEmptySpace("Dandelion");
  world->insertOrganismAtEmptySpace("Human");
  
  return world;
}

World* World::getWorld(const char* s){
  if(world != nullptr){
    delete world;
  }
  ifstream in;
  string temp;
  int xTemp, yTemp, turn, orgCount;
  in.open(s);

  getline(in, temp, ' '); // blank
  getline(in, temp); 
  turn = stoi(temp);


  getline(in, temp, ' '); // blank
  getline(in, temp, ' '); 
  xTemp = stoi(temp);
  getline(in, temp); 
  yTemp = stoi(temp);

  world = new World(xTemp, yTemp);
  world->gameTurn = turn;
  world->logsPos = 0;

  getline(in, temp); 
  orgCount = stoi(temp);
  int orgX, orgY;
  string orgName;
  for(int i = 0; i < orgCount; i++){
    getline(in, temp, ' ');
    orgName = temp;
    getline(in, temp, ' ');
    orgX = stoi(temp);
    getline(in, temp);
    orgY = stoi(temp);
    world->findOrganismAndCreate(orgName, orgX, orgY);
  }
  in.close();
  return world;
}


void World::findOrganismAndCreate(string s, int x, int y){
    if (s == "Antelope") {
      new Antelope(x, y, this);
  } else if (s == "Dandelion") {
      new Dandelion(x, y, world);
  } else if (s == "DeadlyNightshade") {
      new DeadlyNightshade(x, y, this);
  } else if (s == "Fox") {
      new Fox(x, y, this);
  } else if (s == "Grass") {
      new Grass(x, y, this);
  } else if (s == "Guarana") {
      new Guarana(x, y, this);
  } else if (s == "Human") {
      this->humanPtr = new Human(x, y, this);
  } else if (s == "Sheep") {
      new Sheep(x, y, this);
  } else if (s == "SosnowskiHogweed") {
      new SosnowskiHogweed(x, y, this);
  } else if (s == "Turtle") {
      new Turtle(x, y, this);
  } else if (s == "Wolf") {
      new Wolf(x, y, this);
  }
  else{
    return;
  }

}

void World::saveWorld(){
  string name = "gameSaves/save" + to_string(rand()) + ".txt";
  ofstream save;
  save.open(name);
  save << "Turn: " << to_string(gameTurn) << "\nWorldSz(x,y): " 
  + to_string(x) + " " + to_string(y) + "\n" + to_string(organisms.size()) << "\n";

  for(int i =0; i < organisms.size(); i++){
    save << organisms[i]->toString() << "\n";
  }

  save.close();
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

bool World::getPlayerInput(){
  int ch;
  ch = getch();
  if(humanPtr->selectMove(ch)){
    return true;
  }
  return false;;
}

void World::printStats() {
  mvwprintw(stats, 0, 2, "STATS");
  int temp = organisms.size();
  mvwprintw(stats, 1, 1, "%d", temp);
   mvwprintw(stats, 2, 1, "TURN: %d", gameTurn);
  mvwprintw(stats, 3, 1, "IMMORTALITY:");
  if(humanPtr != nullptr){
    int timer = humanPtr->getAbilityTimer();
    if(timer > 0){
      mvwprintw(stats, 4, 1, "ON (%d turns)", timer);
    }
    else if(timer < 0){
      mvwprintw(stats, 4, 1, "COOLDOWN (%d turns)", timer);
    }
    else{
      mvwprintw(stats, 4, 1, "READY TO USE");
    }
  }
  
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
  if(gameTurn == 100){
    saveWorld();
  }
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
  log.erase(0, 1);
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
