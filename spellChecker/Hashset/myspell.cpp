/**
 * \file myspell.cpp
 *
 * \author CS 70 Provided Code with additions by pig and heron
 *
 * \brief Implements the UI for the spelling checker
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <list>
#include "hashset.hpp"
#include "stringhash.hpp"
#include "myspell.hpp"
using namespace std;

/**
 * \brief Process input from cin and compare against the dictionary.
 *        If the word is not found and has not been seen before, spelling
 *        corrections are output to cout.
 *
 * \param dictfile Name of dictionary file.
 *
 * \param debug    Boolean corresponding to the -d flag
 */

MySpell::MySpell()
    :wordList_{}, dictionary_{}
{
    //nothing to do here
}

void MySpell::populateDictionary(const std::string& dictfile)
{
    ifstream inputFile{dictfile};
    string word;
    // read words from dictfile into our hashset
    while (inputFile >> word) {
        dictionary_.insert(word);
    }
}

void MySpell::printSuggestions(std::string word)
{

    if(dictionary_.exists(word) == true){
        return;
    }
    // permutate every letter in the word and check 
    // against the dicitonary in our hashset. If match found,
    // insert into list of corrected words    
    else {
        for(size_t i = 0; i < word.length(); ++i){
            for(char let = 'a'; let <= 'z'; ++let){
                char oldLet = word[i];
                word[i] = let;
                if(dictionary_.exists(word) == true){
                    wordList_.push_front(word);
                    std::cout << word << ' ';
                }
                word[i] = oldLet;
            }
        }
    
        // print all corrected words from our wordList to std cout  
        for(auto j = wordList_.begin(); j != wordList_.end(); ++j){
            std::cout << " " << *j;
        } 
    }
}

void MySpell::spellcheck(const string& dictfile, bool debug)
{

    // fill our dictionary with words form dictfile
    populateDictionary(dictfile);

    //print corrected words while searching through input
    string word;
    std::cin >> word;
    while (std::cin >> word) {
        std::cout << word << ": ";
        printSuggestions(word);
    }

    // debug statements
    if(debug == true){
        std::cout << dictionary_.reallocations() << "expansions, " <<
            "load factor " << dictionary_.size() / dictionary_.buckets() << ", " <<
            dictionary_.collisions() << "collisions, " << 
            "longest run " << dictionary_.maximal() << std::endl;
    }
}

/// Main function, processes inputs and runs spellcheck
int main(int argc, const char** argv)
{

    MySpell dict;
    bool debug = false;

    // Process command-line options
    --argc; // Skip past 0th arg (program name)
    ++argv;

    if (argc == 2 && *argv == string("-d")) {
        debug = true;
        --argc;
        ++argv;
    }

    if (argc != 1) {
        cerr << "Usage: ./myspell [-d] dict" << endl;
        exit(2);
    }

    // Check that spelling!
    try {
        dict.spellcheck(argv[0], debug);
    } catch (std::runtime_error err) {
        cerr << err.what() << endl;
        return 1;
    }

    return 0;
}
