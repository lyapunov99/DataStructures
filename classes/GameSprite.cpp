#include <iostream>
#include "Rect.h"
#include "GameSprite.h"

GameSprite::GameSprite(): Rect()
{
  dx = 0;
  dy = 0;
  frame = 0;
}

GameSprite::GameSprite(int length, int width): Rect(length, width)
{
  dx = 0;
  dy = 0;
  frame = 0;
}

GameSprite::GameSprite(int length, int width, int x, int y): Rect(length, width, x, y)
{
  dx = 0;
  dy = 0;
  frame = 0;
}

GameSprite::GameSprite(int length, int width, int x, int y, string imageURL): Rect(length, width, x, y)
{
  dx = 0;
  dy = 0;
  frame = 0;
  this->imageURL = imageURL;
}

void GameSprite::draw()
{
  cout << "Drawing " << getId() << endl;
}

GameSprite::~GameSprite()
{
  cout << "Eliminating game sprite from memory..." << endl;
}
