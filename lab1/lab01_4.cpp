#include <iostream>

using namespace std;

struct Sprite {
  int x;
  int y;
  string label;
  string resourceUrl;
};

int main()
{
  Sprite *pacman;

  pacman = new Sprite;
  (*pacman).x = 10;
  (*pacman).y = 20;
  (*pacman).label = "Pac-Man";
  (*pacman).resourceUrl = "pacman10-hp-sprite.png";
  cout << (*pacman).label << endl;
  delete pacman;
  return 0;
}
