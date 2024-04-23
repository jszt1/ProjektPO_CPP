#pragma once
#include <ncurses.h>
#include <string>
#include <vector>
#include "Organism.h"


#define MAX_LOGS_PER_PAGE 10
#define N_GAME_LINES 20
#define M_GAME_COLUMNS 20

using namespace std;

class Organism;
//class Wolf;

class World {
  int x, y;
  int gameTurn;
  std::vector<Organism*> organisms; 

  WINDOW *logsView;
  WINDOW *stats;
  WINDOW *gameMap;
  vector<string> logs;
  size_t logsSz;
  size_t logsPos;
  static World *world;

  void printGameMap();
  void printStats();
  void printLogs();
  void clearLogs();
  void clearWindows();
  void addBorders();

protected:
  WINDOW *getGameMap();
  WINDOW *getLogsView();
  WINDOW *getStats();

public:
  World(int, int);
  //void addLog(Organism*, const std::string&);
  //void addLog(Organism*, const char* &);
  void addLog(Organism*, std::string &s);
  void addOrganism(Organism*);
  void printWorld();
  void doTheTurn();

  int getGameSizeX() const;
  int getGameSizeY() const;
  static World* getWorld();
  static World* getWorld(int, int);
  Organism *getOrganismXY(int x, int y);

  ~World();

  friend class Organism;
  friend class Animal;
};
