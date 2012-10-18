#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "a4.h"

using namespace std;

void quest(Room *start, int rooms)
{
  // The following is an initial solution.
  // It doesn't seg fault, but it also never finds the exit!
  srand(time(NULL));
  while (1) {
    if (start->exit()) {
      return;
    }
    int randdir = rand() % DIRS;
    if (start->dirs[randdir]) {
      go(randdir);
      start = start->dirs[randdir];
    }
  }
}
