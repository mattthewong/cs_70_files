/**
 * \file stringhash.hpp
 * \author What are your CS70 aliases?
 *
 * \brief Hash function for strings
 */

#include "stringhash.hpp"

using std::string;

// Hash Function Gallery
//
// These are the hash functions our group has examined, one of them is used
// as myhash (see later code in the file)
//
// All the code below is in an anonymous namespace, so these function names
// are hidden from other code.
namespace {


/**
 * http://stackoverflow.com/questions/8317508/hash-function-for-a-string
 * 
 */
size_t simpleLengthHash(const string& str)
{
    int result = 0;
    for(size_t i = 0; i < str.length(); ++i) {
        result += str[i] * (31^i);
    }
    return result;
}


/**
 * http://stackoverflow.com/questions/628790/have-a-good-hash-function-for-a-c-hash-table
 * 
 *
 */
size_t simpleAddHash(const string& str) {
    size_t h(0);
    for (size_t i=0; i<str.length(); i++) {
        h = (h << 6) ^ (h >> 26) ^ str[i];
}
  return h;
}

/**
 * http://stackoverflow.com/questions/8317508/hash-function-for-a-string
 *
 */  
size_t simpleMultHash(const string& str)
{
    int seed = 131; 
    unsigned long hash = 0;
    for(size_t i = 0; i < str.length(); i++) {
      hash = (hash * seed) + str[i];
   }

   return hash % 341;
}

} // end of anonymous namespace

size_t myhash(const string& str)
{
    // FIXME: Make this code call your favorite of the ones you've defined
    //        above.
    return simpleAddHash(str);
}

// You don't have to fully understand this code, but it is used to provide a
// table used by stringhash-test.cpp, all you need to do is list the name
// of your hash function (for printing) and the actual function name from
// above.
std::initializer_list<HashFunctionInfo> hashInfo = {
    {"Simple Length (Dummy)",   simpleLengthHash},
    {"Simple Add (Dummy)",      simpleAddHash},
    {"Simple Mult (Dummy)",     simpleMultHash}  // No comma for last one
};

