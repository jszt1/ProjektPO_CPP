#pragma once
#include <ncurses.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Organism.h"


#define MAX_LOGS_PER_PAGE 10
#define N_GAME_LINES 20
#define M_GAME_COLUMNS 20

using namespace std;

struct Pos{
  int x;
  int y;
};

class Organism;
class Human;
//class Wolf;

class World {
  int x, y;
  int gameTurn;
  Pos playerPos;
  std::vector<Organism*> organisms; 
  vector<string> logs;
  WINDOW *logsView;
  WINDOW *stats;
  WINDOW *gameMap;
  Human *humanPtr;
  
  size_t logsSz;
  size_t logsPos;
  static World *world;

  void printGameMap();
  void printStats();
  void printLogs();
  void clearLogs();
  void clearWindows();
  void addBorders();
  

public:
  World(int, int);
  bool getPlayerInput();
  void addLog(Organism*, std::string s);
  void addOrganism(Organism*);
  void findOrganismAndCreate(std::string, int, int);
  void insertOrganismAtEmptySpace(std::string);
  void killOrg(Organism*);
  bool priority(Organism*, Organism*);
  WINDOW *getGameMap();
  WINDOW *getLogsView();
  WINDOW *getStats();
  void printWorld();
  void saveWorld();
  void doTheTurn();

  int getGameSizeX();
  int getGameSizeY();
  static World* getWorld();
  static World* getWorld(int, int);
  static World* getWorld(const char*);
  Organism *getOrganismXY(int x, int y);

  ~World();

  friend class Organism;
  friend class Animal;
};
