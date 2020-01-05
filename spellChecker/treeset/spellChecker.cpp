/**
 * \file spellChecker.cpp
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

SpellChecker::SpellChecker(const string dictfile)
: filename{dictfile}
{

}

void SpellChecker::populateDictionary(){
    
    // Open provided file
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(1);
    }
    // Read data from the file, one item per line
    // and insert each word into the dictionary
    string line;
    while(inFile.good()) {
        getline(inFile, line);
        dictionary.insert(line);
    }
}

void SpellChecker::similarWords(string inputWord){

    // check for the existence of the inputword in the dictionary
    // print similar words if it does not exist
    if(!dictionary.exists(inputWord)){
        string copyWord = inputWord;
        string possWords = inputWord + ": ";

        // loop through each index of the input word
        // check permutations for each index
        for (size_t i =0; i < inputWord.size(); ++i){
            copyWord = inputWord;

            for( char letter = 'a' ; (int) letter <= 'z'; letter++){

                copyWord[i] = letter;

                if (dictionary.exists(copyWord)){
                    possWords += copyWord + " ";
                }
            }
            
        }
        cout << possWords << endl;
    }
}

string SpellChecker::simplifyInput(string line){
    // find the indices of the first and last characters
    size_t startIndex = 0;
    size_t lastIndex = line.size() - 1;
    while (startIndex < line.size()){
        if(isalpha(line[startIndex])){
            break;
        }
        ++startIndex;
    }
    while ( lastIndex > startIndex){
        if(isalpha(line[lastIndex])){
            break;
        }
        --lastIndex;
    }
    // return the substring from the previous indices
    return line.substr(startIndex, lastIndex +1 - startIndex);
}

void SpellChecker::parseText(){
    
    string line;
    
    // while there is some input
    while(cin >> line ){

        // create placeholder real word
        string realWord = "";
       
        // simplify the input
        line = simplifyInput(line);
        
        // return the lower case version of the input
        for(char elem : line)
            realWord += tolower(elem);

        // add the input to our dictionary
        if (!inputWords.exists(realWord)){
            inputWords.insert(realWord);
            similarWords(realWord);
         }
    }
}

void SpellChecker::debug(){
    // cout << dictionary.reallocations() << " expansions, ";
    // cout << "load factor " << dictionary.load_factor() << ", ";
    // cout << dictionary.collisions() << " collisions, longest run ";
    // cout << dictionary.maximal() << endl;
}
