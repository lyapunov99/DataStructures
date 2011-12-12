#include <iostream>
#include "Rect.h"

using namespace std;

class GameSprite: public Rect
{
 public:
  GameSprite();
  GameSprite(int length, int width);
  GameSprite(int length, int width, int x, int y);
  GameSprite(int length, int width, int x, int y, string imageURL);
  void draw();
  ~GameSprite();
 private:
  int dx;
  int dy;
  string imageURL;
  int colorR;
  int colorG;
  int colorB;
  int frame;
};
