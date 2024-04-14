#include "../include/World.h"

#include <ncurses.h>

#include <cstring>

World::World() {
  x = M_GAME_COLUMNS;
  y = N_GAME_LINES;

  organisms = new Organism **[y];
  for (int i = 0; i < y - 1; i++) {
    organisms[i] = new Organism *[x];
    // for (int j = 0; j < x; j++) {
    //   organisms[i][j] = nullptr;
    // }
  }

  logs = nullptr;
  logsSz = 0;
  logsPos = 0;
  initscr();
  start_color();

  logsView = newwin(MAX_LOGS_PER_PAGE + 2, 2 * (M_GAME_COLUMNS + 2),
                    M_GAME_COLUMNS + 2, 0);
  stats = newwin(N_GAME_LINES + 2, M_GAME_COLUMNS + 2, 0, 22);
  gameMap = newwin(22, 22, 0, 0);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  wattron(gameMap, COLOR_PAIR(1));

  wattron(stats, COLOR_PAIR(2));

  wattron(logsView, COLOR_PAIR(3));

  refresh();
}

void World::clearWindows() {
  wclear(gameMap);
  wclear(stats);
  wclear(logsView);
}

void World::addBorders() {
  box(logsView, '-', '|');
  box(stats, '-', '|');
  box(gameMap, '-', '|');
}

void World::printGameMap() {
  mvwprintw(gameMap, 0, 2, "MAP");
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
  for (int i = logsPos; i < logsPos + MAX_LOGS_PER_PAGE + 1; i++) {
    mvwprintw(logsView, i % MAX_LOGS_PER_PAGE + 1, 1, "%s", logs[i]);
  }
  wrefresh(logsView);
  // pass
}

void World::printWorld() {
  addBorders();
  printGameMap();
  printLogs();
  printStats();
}

void World::addLog(char *&&s) {
  char **temp = new char *[logsSz + 1];
  for (int i = 0; i < logsSz; i++) {
    temp[i] = logs[i];
  }
  temp[logsSz] = new char[strlen(s)];
  if (logsSz > MAX_LOGS_PER_PAGE) {
    logsPos++;
  }
  strncpy(temp[logsSz], s, strlen(s));
  logsSz++;
  logs = temp;
}

void World::addLog(const char *&s) {
  char **temp = new char *[logsSz + 1];
  for (int i = 0; i < logsSz; i++) {
    temp[i] = logs[i];
  }
  temp[logsSz] = new char[strlen(s)];
  strncpy(temp[logsSz], s, strlen(s));
  if (logsSz > MAX_LOGS_PER_PAGE) {
    logsPos++;
  }
  logsSz++;
  logs = temp;
}

int World::getGameSizeX() const { return x; }
int World::getGameSizeY() const { return y; }
Organism *World::getOrganismXY(int x, int y) const { return organisms[y][x]; }

World::~World() {
  if (logs != nullptr && logsSz > 0) {
    for (int i = 0; i < logsSz; i++) {
      // delete[] logs[i];
    }
    delete[] logs;
  }

  for (int i = 0; i < y; i++) {
    delete[] organisms[i];
  }
  delete[] organisms;
  endwin();
}
