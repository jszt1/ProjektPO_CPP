#include <ncurses.h>
#include <string.h>

class World {
  WINDOW *logsView;
  WINDOW *stats;
  WINDOW *gameMap;
  char **logs;
  size_t logsSz;

  void printGameMap();
  void printStats();
  void printLogs();
  void addBorders();

public:
  World();
  void addLog(char *&&s);
  void addLog(const char *&s);
  void printCurse();
  ~World();
};