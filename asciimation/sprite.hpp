/* sprite.hpp
   =========

   interface definition for the Sprite class. Defines the behavior
   of a single asciimation 'character'

 */

#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED 1;

#include <iostream>
#include <fstream>

/**
 * \class Sprite
 * \brief Holds the contents of a single ASCIImation sprite
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, along
 * with the sprite's current location.
 *
 * \remarks
 *    The implemented code only works for a fixed size sprite.
 *
 */
class Sprite {
public:
    // Size of the sprite, in characters
    static const size_t SPRITE_WIDTH = 40;
    static const size_t SPRITE_HEIGHT = 10;

    /**
     * \brief Reads a text file containing the characters for a sprite.
     * \post Should populate the sprite's character array, but doesn't yet.
     */
  Sprite() = delete; // disables default constructor
  Sprite(const std::string& fname, int row, int col);


//function that returns the sprite’s current xlocation.
  int getTopLeftColumn();

//function that returns the sprite’s current y-location.
  int getTopLeftRow();

//returns the cth character in the rth row of sprite’s character array.
  char getCharAt(size_t row, size_t col);

//function that moves the sprite to the location (x,y).
  void setLocation(size_t x, size_t y);

//sets the value of the shouldScroll_ data member.
  void setScrolling(bool flag); 

//returns the current value of shouldScroll_.
  bool getScrolling(); 

//changes Sprite's location one spot to the 
//right (and handles the case when the sprite moves off the edge of the screen
  void moveRight(int maxWidth); 
private:

  int topLeftColumn_; //location of top left column of sprite
  int topLeftRow_; //location of top left row of sprite
  //holds contents of 1D sprite in array
  char contents_[SPRITE_WIDTH*SPRITE_HEIGHT]; 
  bool shouldScroll_; //boolean for if sprite should scroll

  
};

#endif // ifndef SPRITE_HPP_INCLUDED
