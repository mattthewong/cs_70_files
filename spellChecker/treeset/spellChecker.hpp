/**
 * \file spellChecker.hpp
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

#ifndef SPELLCHECKER_HPP_INCLUDED
#define SPELLCHECKER_HPP_INCLUDED 1

#include "treeset.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

class SpellChecker{
public:
	SpellChecker() = delete;
	SpellChecker(const std::string dictfile);


	/**
	* \brief parse the input word
	*
	* \param line a string that we preprocess
	*	
	*/
	std::string simplifyInput(string line);

	/**
	* \brief check the spelling of a word and print out suggestions
	*
	* \param inputWord the word that we want to check
	* 
	*/
	void similarWords(string inputWord);

	/*
	*
	* \brief populate dictionary with a file of words
	*
	*/
	void populateDictionary();

	/*
	* \brief parse the input text file in cin 
	*/
	void parseText();

	void debug();

private:
	TreeSet<string> dictionary; /// a treeset dictionary of words
	TreeSet<string> inputWords; /// a a treeset input words
	string filename; /// a string of the file inputted
};


#endif
