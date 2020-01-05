/**
 * \file lineshuffler.cpp
 * \author CS 70 Provided Code
 *
 * \brief
 *   Implements LineShuffler. See lineshuffler.hpp for function
 *   descriptions.
 */

#include "lineshuffler.hpp"
#include "exchange.hpp"
#include "random.hpp"
using namespace std;

LineShuffler::LineShuffler()
    //: count_(0)
{
    // Nothing else to do.
}


string LineShuffler::removeLine()
{
    // Choose a random line.
    //int index = rnd_.next(storedLines_.size());
    string line = storedLines_[0];

    // Delete the string at storedLines_[index] and move the other strings up.
    storedLines_.erase(storedLines_.begin());
    //--storedLines_.size();

    return line;
}


void LineShuffler::addLine(string line)
{
    storedLines_.push_back(line);
    //++count_;
}


bool LineShuffler::isEmpty() const
{
    return storedLines_.size() == 0;
}

void LineShuffler::shuffleStoredLines(){
    for(size_t i = 0; i < storedLines_.size(); ++i){//loops through the size of the stored lines vector
        size_t randindex = rnd_.next(storedLines_.size());//gets a random index each time
        exchange(storedLines_[i], storedLines_[randindex]); //exchanges the value of the line at index i with the value at the random index!
    }
}

/* (Junk to make emacs use a specific indentation style)
 * Local Variables:
 * c-file-style: "stroustrup"
 * End:
 */
