#pragma once
#include <ncurses.h>
#include <string.h>

#include "Organism.h"

#define MAX_LOGS_PER_PAGE 10
#define N_GAME_LINES 20
#define M_GAME_COLUMNS 20

class Organism;

class World {
  int x, y;
  Organism ***organisms;

  WINDOW *logsView;
  WINDOW *stats;
  WINDOW *gameMap;
  char **logs;
  size_t logsSz;
  size_t logsPos;

  void printGameMap();
  void printStats();
  void printLogs();
  void clearWindows();
  void addBorders();

public:
  World();
  void addLog(char *&&s);
  void addLog(const char *&s);
  void printWorld();

  int getGameSizeX() const;
  int getGameSizeY() const;
  Organism *getOrganismXY(int x, int y) const;

  ~World();
};
