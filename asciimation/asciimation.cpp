/**
 * \file movie.cpp
 * \author CS 70 Provided Code
 *
 * \brief Implements the Movie class
 *
 * \details
 *
 * \remarks
 *
 */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "ncurses-helper.hpp"
#include "asciimation.hpp"
#include "sprite.hpp"

using namespace std;

Asciimation::Asciimation(const string& fname):sprite_(fname,10,30){
  sprite_.setScrolling(true);
}

void Asciimation::clearContents()
{
  for (size_t i=0; i < MOVIE_WIDTH; ++i)
  {
    for(size_t j = 0; j < MOVIE_HEIGHT; ++j){

      asciicontents_[(j*MOVIE_WIDTH)+ i] = ' ';

    }
  } 
}

void Asciimation::updateContents()
{
  // Clear contents by writing a space everywhere, so that we don't keep
  // old contents around when the display updates.
  clearContents();
  
  // Loop through all of the characters in the sprite and copy them to 
  // the right spot in the movie's character array.
  
  int movieRow=0;
  int movieCol=0;
  
  if(sprite_.getScrolling()){
    sprite_.moveRight(MOVIE_WIDTH);
  }
  for (size_t spriteRow=0; spriteRow < sprite_.SPRITE_HEIGHT; ++spriteRow) {
    for(size_t spriteCol=0; spriteCol < sprite_.SPRITE_WIDTH; ++spriteCol) {
      movieRow = spriteRow + sprite_.getTopLeftRow();
      movieCol = spriteCol + sprite_.getTopLeftColumn();
      if ((movieCol>=0) && (movieCol < MOVIE_WIDTH)) {
        
        char spritechar = sprite_.getCharAt(spriteRow, spriteCol);
          
          asciicontents_[(movieRow*MOVIE_WIDTH) + movieCol] = spritechar;    
      }   
    }
  }
}

/**
 * Initializes the screen for ncurses, then repeatedly updates the screen until
 * the user exits by pressing 'q'.
 */
void Asciimation::play() 
{

  // Time to sleep between screen refreshes
  const int PAUSE_TIME_IN_MICROSECONDS = 40000;

  // Set up ncurses so that it's ready to display our asciimation. 
  init_ncurses();

  // Play the movie by refreshing the screen with new data, every so often
  int ch;
  bool finished = false;

  while (not(finished)) {
    // Copy contents to the screen
    updateContents(); // Get updated character values from the sprite object
    copyToScreen();        // Copy the movie's characters to the screen's buffer
    refresh();        // Refresh the screen

    // Sleep between updates
    usleep(PAUSE_TIME_IN_MICROSECONDS);

    // Check to see if the user has entered 'q' to quit yet
    ch = getch();
    if (ch == 'q') {
        finished = true;
    }
  }

  // Return the screen to its normal settings before exiting, since we don't
  // want to leave it in ncurses's prefered setup. 
  cleanup();
}

void Asciimation::copyToScreen() 
{
  for (size_t heightpos=0;heightpos < MOVIE_HEIGHT; ++heightpos){
    for(size_t widthPos = 0; widthPos < MOVIE_WIDTH; ++widthPos){

        mvaddch(heightpos,widthPos,
          asciicontents_[heightpos*MOVIE_WIDTH + widthPos]);

    }

  }
}
   

