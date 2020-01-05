/**
 * \file sprite.cpp
 * \author CS 70 Provided Code
 *
 * \brief Implements the Sprite class
 *
 * \details
 *
 * \remarks
 *
 */

#include <cstddef>
#include <iostream>

#include "sprite.hpp"

using namespace std;

Sprite::Sprite(const std::string& fname, int topLeftRow, int topLeftColumn)
{
  ifstream inputFile{fname};

  int widthFromFile=0;
  inputFile >> widthFromFile;

  int heightFromFile=0;
  inputFile >> heightFromFile;

  inputFile.get(); // Read past the newline character after the height. 

  if (widthFromFile != Sprite::SPRITE_WIDTH) {
    cerr << "Warning: Trying to read a Sprite with the wrong width." << widthFromFile << endl;
  }

  if (heightFromFile != Sprite::SPRITE_HEIGHT) {
    cerr << "Warning: Trying to read a Sprite with the wrong height." << endl;    
  }

  for(size_t i = 0; i < SPRITE_WIDTH*SPRITE_HEIGHT; ++i){
    contents_[i] = inputFile.get();
  }

  topLeftRow_ = topLeftRow;
  topLeftColumn_ = topLeftColumn;

  inputFile.close();
}

int Sprite::getTopLeftRow()
{
  return topLeftRow_;
}

int Sprite::getTopLeftColumn()
{
  return topLeftColumn_;
}

char Sprite::getCharAt(size_t row,size_t column)
{
  return contents_[SPRITE_WIDTH * row + column];
}

void Sprite::setLocation(size_t x, size_t y)
{
  topLeftColumn_ = x;
  topLeftRow_ = y;
}

void Sprite::setScrolling(bool flag){
  shouldScroll_ = flag;
}

bool Sprite::getScrolling(){
  return shouldScroll_;
}

void Sprite::moveRight(int maxWidth){
  
  if(topLeftColumn_ < maxWidth){
    ++topLeftColumn_;
  }
  else{
    topLeftColumn_ = -SPRITE_WIDTH;
  }
}
