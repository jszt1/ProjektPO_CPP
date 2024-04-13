#include "../include/Curse.h"

#include <ncurses.h>

Curse::Curse() {
  logs = nullptr;
  logsSz = 0;

  initscr();
  start_color();

  logsView = newwin(12, 44, 22, 0);
  stats = newwin(22, 22, 0, 22);
  gameMap = newwin(22, 22, 0, 0);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  wattron(gameMap, COLOR_PAIR(1));

  wattron(stats, COLOR_PAIR(2));

  wattron(logsView, COLOR_PAIR(3));

  refresh();
}

void Curse::addBorders() {
  box(logsView, '#', '#');
  box(stats, '#', '#');
  box(gameMap, '#', '#');
}

void Curse::printGameMap() {
  wrefresh(gameMap);
  // pass
}

void Curse::printStats() {
  wrefresh(stats);
  // pass
}

void Curse::printLogs() {
  for (int i = 0; i < logsSz; i++) {
    mvwprintw(logsView, i, 1, "%s", logs[i]);
  }
  wrefresh(logsView);
  // pass
}

void Curse::printCurse() {
  addBorders();
  printGameMap();
  printLogs();
  printStats();
}

void Curse::addLog(char *&&s) {
  char **temp = new char *[logsSz + 1];
  for (int i = 0; i < logsSz; i++) {
    temp[i] = logs[i];
  }
  temp[logsSz] = new char[strlen(s)];
  for (int i = 0; i < strlen(s); i++) {
    temp[logsSz][i] = s[i];
  }
  logsSz++;
  delete[] logs;
  logs = temp;
}

void Curse::addLog(const char *&s) {
  char **temp = new char *[logsSz + 1];
  for (int i = 0; i < logsSz; i++) {
    temp[i] = logs[i];
  }
  temp[logsSz] = new char[strlen(s)];
  for (int i = 0; i < strlen(s); i++) {
    temp[logsSz][i] = s[i];
  }
  logsSz++;
  logs = temp;
  // for (int i = 0; i < logsSz; i++) {
  //    temp[i] = logs[i];
  //  }
  //  if (logsSz > 0) {
  //    for (int i = 0; i < logsSz; i++) {
  //      delete[] logs[i];
  //    }
  //    delete[] logs;
  //  }
  //  temp[++logsSz] = (char *)s;
  //  logs = temp;
}
Curse::~Curse() {
  if (logs != nullptr && logsSz > 0) {
    for (int i = 0; i < logsSz; i++) {
      // delete[] logs[i];
    }
    delete[] logs;
  }
  endwin();
}
