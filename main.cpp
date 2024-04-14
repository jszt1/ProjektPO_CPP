#include <ncurses.h>

#include <cstdio>

#include "include/World.h"

int main() {
  World cr;
  char s[100];
  const char *d = "AAA";
  for (int i = 0; i < 30; i++) {
    sprintf(s, "%d. twoja stara", i);
    cr.addLog(s);
  }
  cr.printWorld();

  getch();
  return 0;
}
