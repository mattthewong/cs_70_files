/* movie.hpp
   =========

   Interface definition for the Movie class, which handles the main screen
   and coordination of an asciimation movie.

 */
#ifndef ASCIIMATION_HPP_INCLUDED
#define ASCIIMATION_HPP_INCLUDED = 1;

#include "sprite.hpp"


/**
 * \class Asciimation
 * \brief Holds the contents of an ASCIImation movie
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */
class Asciimation {
public:
    static const size_t MOVIE_WIDTH = 80;
    static const size_t MOVIE_HEIGHT = 40;
     
    /**
     * \brief Creates the current display showing the sprite
     * \post The current display contents are up to date and
     * ready to display to the screen.
     */
    
    Asciimation(const std::string& fname);
    
    //updates the contents of the asciimation.
    void updateContents();

    /**
     * \brief Displays an asciimation on the screen until the user enters "q"
     * \post The screen is destroyed.
     */
    void play();

    /**
     * \brief Displays the current display on the screen
     * \post No change to the asciimation object
     */
    /*copies characters from the movie's character array to the screen. It should
     use the ncurses function mvaddch to copy each element of the movie’s character
      array to the right spot on the screen. */
      
    void copyToScreen();

private:
    // The sprite to display in this movie.
    char asciicontents_[MOVIE_WIDTH*MOVIE_HEIGHT];
    // The characters to display on the screen.
    Sprite sprite_;
    // clears sprite from screen
    void clearContents();

};

#endif // ifndef ASCIIMATION_HPP_INCLUDED
