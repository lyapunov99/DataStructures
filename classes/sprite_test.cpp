#include <iostream>
#include "GameSprite.h"

using namespace std;

int main()
{
  GameSprite *s = new GameSprite(200, 100, 10, 10, "mario.jpg");
  s->setId("Mario");
  s->draw();
  delete s;
  return 0;
}
