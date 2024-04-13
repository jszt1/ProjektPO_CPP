#include <ncurses.h>

#include <cstdio>

#include "include/Curse.h"

int main() {
  Curse cr;
  char *s;
  const char *d = "AAA";
  for (int i = 0; i < 10; i++) {
    sprintf(s, "%d. twoja stara", i);
    cr.addLog(d);
  }
  cr.printCurse();

  getch();
  return 0;
}
