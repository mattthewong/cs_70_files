/**
 * \file our-movie.cpp
 * \author CS 70 Provided Code
 *
 * \brief Provides the main() function for creating and running
 * a specific asciimation movie. 
 *
 * \details
 *
 * \remarks
 *
 */

#include <iostream>
#include "asciimation.hpp"
#include "sprite.hpp"

using namespace std;

void makeOurMovie() 
{
    Asciimation mymovie = Asciimation("spriteImages/flowingriver.txt");
    mymovie.play();
}

int main()
{
    makeOurMovie();
    return 0;
}
