/**
 * \file palindrome.cpp
 * \authors
 *
 * \brief Contains `palindrome` program to identify palidromes.
 *
 * \remarks
 *   The palindrome test is handled by isPalindrome, while all
 *   interaction is handled in main.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/* Helper function for isPalindrome
*  
*  Returns a string free of punctuation, spaces, and 
*  capitalization to properly assess its palidromic nature.
*/
string cleanString(string text)
{

 string lowerString ("");   
/* for loop for checking each value in string and lowering it.
*/
 for(char j : text) {
     lowerString += tolower(j);
 }

 string cleanedString ("");

/* Traverses through the lowercase string, checking 
*  if the character is a letter. If it is, it is added
*   to the cleaned string
*/
 for (char i : lowerString) {
    if (isalpha(i) != 0) {
        cleanedString += i;
    }
 }

return cleanedString;

}


/**
 * \brief Tests a string for being a palindrome.
 * \returns true iff `text` is a palindrome (same backwards and forwards).
 *
 * \remarks
 *   Unfortunately, we currently literally require the characters in
 *   the string to be the same backwards and forwards, rather than
 *   only caring about the letters.
 *
 * \todo Ignore Spaces and punctuation
 * \todo Ignore capitalization
 */
bool isPalindrome(string text /**< Canditate palindrome.*/)
{
    string cleanText = cleanString(text); //clean up string with helper function
    int left  = 0;                      // Indexes of the leftmost and
    int right = cleanText.length() - 1;      // rightmost unchecked character.

    // Check palindrome by moving left and right boundaries progressively
    // closer until they finally meet or pass each other.  Bail early if
    // we find a mismatch.
    while (left < right) {
        if (cleanText[left] != cleanText[right])
            return false;

        ++left;
        --right;
    }

    // All the characters checked out.
    return true;
}


/**
 * \brief
 *   Reads a potential palindrome and then indicates if it is or not.
 *
 * \pre
 *   We ignore the command line arguments, and thus don't provide
 *   names for them.
 *
 * \returns 0
 *   when it exits with no errors, just like any regular main
 *   function.
 */
int main (int, const char*[])
{
    cout << "Enter possible palindrome: ";
    string line;

    getline(cin, line);

    if (isPalindrome(line))
        cout << "Yay, that's a palindrome!" << endl;
    else
        cout << "No, that's not a palindrome." << endl;

    return 0;
}


/* (Junk to make emacs use Stroustrup-style indentation)
 * Local Variables:
 * c-file-style: "stroustrup"
 * End:
 */
