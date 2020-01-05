/**
 * \file myspell.hpp
 *
 * \author CS 70 Provided Code with additions by pig and heron
 *
 * \brief Interface for our spell checker
 */

#include <string>
#include <iostream>
#include <stdexcept>

class MySpell {

public:
    //default constructor for creating a MySpell object.
    MySpell();

    //main function that reads dictfile and 
    void spellcheck(const std::string& dictfile, bool debug);

    //populates the hashset dictionary with the words in "filename.txt"
    void populateDictionary(const std::string& dictfile);

    /*prints the suggestions to the words that are spelled incorrectly 
    /in the form of the misspelled word, followed with a colon, space, and
    /the suggested words separated by spaces.
    */
    void printSuggestions(std::string word);

private:
    std::list<std::string> wordList_; // holds corrected words
    HashSet<std::string> dictionary_; // holds dictionary of words

};