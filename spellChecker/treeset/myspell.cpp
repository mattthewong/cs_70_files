/**
 * \file myspell.cpp
 *
 * \author CS 70 Provided Code from Koi and Quail (which we then modified)
 *
 * \brief We were unable to corectly implement our spellchecker
 *          last week for our HashSet. A grutor mentioned we could use the
            hashset implementation code from another group if we gave credit 
            to the group, Koi and Quail. This was simply used as a means to complete
            the myspell issue of the TreeSet assignment. 
            We used their hashset spellchecker
            code and modified it to be used by our own treeset class. 
 */
#include "spellChecker.hpp"

template class TreeSet<string>;

/**
 * \brief Process input from cin and compare against the dictionary.
 *        If the word is not found and has not been seen before, spelling
 *        corrections are output to cout.
 *
 * \param dictfile Name of dictionary file.
 *
 * \param debug    Boolean corresponding to the -d flag
 */
void spellcheck(const string& dictfile, bool debug)
{
    // create dictionary and spell check.
    SpellChecker checks{dictfile};
    checks.populateDictionary();
    checks.parseText();

    if (debug){
        checks.debug();
    }
}


/// Main function, processes inputs and runs spellcheck
int main(int argc, const char** argv)
{
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
        spellcheck(argv[0], debug);
    } catch (std::runtime_error err) {
        cerr << err.what() << endl;
        return 1;
    }

    return 0;
}