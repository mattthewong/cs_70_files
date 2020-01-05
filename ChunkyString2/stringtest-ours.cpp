/**
 * \file stringtest.cpp
 *
 * \brief Tests a ChunkyString for correctness.
 */

#include "testing-logger.hpp"
#ifndef LOAD_GENERIC_STRING
/* This test code can be used two ways.  It can either test a local
 * ChunkyString implementation, or it can dynamically load an implementation
 * at runtime and test that.  In the first homework, you'll load an
 * implementation that someone else used, but in later assignments, you'll
 * set the value to zero to use your own.
 */
#define LOAD_GENERIC_STRING 0       // 0 = Normal, 1 = Load Code Dynamically
#endif

#if LOAD_GENERIC_STRING
#include "string-wrapper.hpp"       // Use dynamic loading magic!
using TestingString = GenericString;
#else
#include "chunkystring.hpp"         // Just include and link as normal.
using TestingString = ChunkyString;
#endif

#include <string>
#include <sstream>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>
#include <cassert>

#include "signal.h"
#include "unistd.h"

using namespace std;

static const size_t TESTING_CHUNKSIZE = 12;     // Assuming a chunksize of 12

// Helper functions
/**
 * \brief Assuming chunks are supposed to be at least 1/divisor full, checks
 *        for the lowest allowable utilization for the input string
 *
 * \remarks For insertion only, we assume chunks are at least 1/2 full.
 *          For erase, chunks can go down to 1/4 full.
 *          Since checkUtilization is not a test on its own, but rather
 *          a helper function to be used in other tests, it doesn't
 *          create its own TestingLogger object. Instead, its affirms
 *          will be associated with the TestingLogger of the calling
 *          function. 
 *
 * \param test          TestingString to check
 * \param divisor       Fullness of chunk = 1/divisor
 * \param origin        String to describe the caller of this function to
 *                      aid in human debugging.
 */
//bool checkUtilization(const TestingString& test, size_t divisor)
void checkUtilization(const TestingString& test, size_t divisor)
{
    double utilLimit = 0;

    if (test.size() > 0)
    {
        size_t chunks = 1;
        size_t size = test.size() - 1;
        divisor = TESTING_CHUNKSIZE / divisor;
        chunks += (size + divisor - 1) / divisor;
        utilLimit = double(size) / double(chunks * TESTING_CHUNKSIZE);
        affirm(test.utilization() > utilLimit);
    }
}



// Testing functions

/**
* \brief Tests that default constructor produces a ChunkyString object
*        with size_ = 0 and an empty std::list<Chunk>.
*/
bool defaultTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"default constructor test"};

    TestingString s;

    affirm(s.size() == 0);
    affirm(s.utilization() == 0.0);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that size_ is updated correctly when characters are 
*        added or removed.
*/
bool sizeTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"size test"};

    TestingString s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');

    affirm(s.size() == 4);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that size_ is zero when we create a default TestString.
*/
bool sizeTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"size test"};

    TestingString s;

    affirm(s.size() == 0);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that two teststrings are equivalent in size_ and chars_.
*/
bool stringsEqualTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings equal test"};

    TestingString d;
    TestingString v;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('d');
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');

    affirm(d == v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that two teststrings are not equivalent in size_ and chars_.
*/
bool stringsNotEqualTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings not equal test"};

    TestingString d;
    TestingString v;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('d');
    v.push_back('e');
    v.push_back('f');
    v.push_back('g');

    affirm(d != v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that two teststrings are equal in size_ and not equal in
*        chars_.
*/
bool stringsNotEqualTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings not equal test1"};

    TestingString d;
    TestingString v;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('d');
    v.push_back('e');
    v.push_back('f');
    v.push_back('g');
    v.push_back('h');

    affirm(d != v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that one filled string and one empty string
*  are not equivalent in size_ and chars_.
*/
bool stringsNotEqualTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings not equal test"};

    TestingString d;
    TestingString v;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');

    affirm(d != v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that one teststrings is lexicographically less 
*        than the other string. (Strings same length)
*/
bool stringsLessThan()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings less than test"};

    TestingString d;
    TestingString v;
    d.push_back('a');
    v.push_back('e');
    

    affirm(d < v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that one teststrings is lexicographically less 
*        than the other string. (Strings different length)
*/
bool stringsLessThan1()
{
    // Set up the TestingLogger object
    TestingLogger log{"strings less than test"};

    TestingString d;
    TestingString v;
    d.push_back('e');
    d.push_back('a');
    v.push_back('e');
    v.push_back('c');
    v.push_back('b');

    affirm(d < v);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that the utilization is greater 
*  than or equal to 0.5 once chars are added.
*/
bool stringUtilization()
{
    // Set up the TestingLogger object
    TestingLogger log{"utilizationtest"};

    TestingString d;
   
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    affirm(d.utilization() >= 0.5);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests that the utilization is greater 
*  than or equal to 0.5 once chars are added.
*/
bool stringUtilization1()
{
    // Set up the TestingLogger object
    TestingLogger log{"utilizationtest"};

    TestingString d;
   
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.erase(d.begin());
    d.erase(--d.end());
    affirm(d.utilization() >= 0.25);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether we modified our Teststring by adding a char to
*        the end of it.
*        
*/
bool stringPushBackTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"pushbacktest"};

    TestingString d;
    d.push_back('a');
    d.push_back('c');
    affirm(*(--d.end()) == 'c');
    affirm(d.size() == 2);
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether we modified our Teststring by adding a char to it.
*        
*/
bool stringInsert()
{
    // Set up the TestingLogger object
    TestingLogger log{"inserttest"};

    TestingString d;
    d.push_back('a');
    d.insert(d.begin(), 'b');

    affirm(d.size() == 2);
    affirm(*(d.begin()) == 'b');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether the TestingString is being erased from properly.
*        
*/
bool stringErase()
{
    // Set up the TestingLogger object
    TestingLogger log{"Erasetest"};

    TestingString d;
    d.push_back('a');
    d.push_back('b');
    d.erase(d.begin());

    affirm(d.size() == 1);
    affirm(*(d.begin()) == 'b');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether string concatenation is working properly.
*        
*/
bool stringConcat()
{
    // Set up the TestingLogger object
    TestingLogger log{"+=test"};

    TestingString d;
    TestingString v;
    TestingString a;
    d.push_back('a');
    d.push_back('b');
    v.push_back('c');
    v.push_back('d');
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    a.push_back('d');
    d += v;

    affirm(a.size() == d.size());
    affirm(a == d);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether the front iterator is pointing to the correct character.
*        
*/
bool iteratorBeginTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"begin"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('d');

    affirm(*(d.begin()) == 'a');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests whether the end() iterator is pointing to one past the end.
*        
*/
bool iteratorEndTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"end"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    d.push_back('d');

    affirm(*(--d.end()) == 'd');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests iterator equality.
*        
*/
bool iteratorEqualityTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"iterator equality"};

    TestingString d;
    
    d.push_back('a');

    affirm(--d.end() == d.begin());

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests iterator inequality.
*        
*/
bool iteratorInequalityTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"iterator inequality"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');

    affirm(--d.end() != d.begin());

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests iterator preincrementing.
*        
*/
bool iteratorIncrementTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"iterator increment"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');

    affirm(*(++d.begin()) == 'b');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests iterator predecrmenting.
*        
*/
bool iteratorDecrementTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"iterator decrement"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');

    affirm(*(--d.end()) == 'b');

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/**
* \brief Tests iterator dereferencing.
*        
*/
bool iteratorDereferenceTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"iterator dereferencing"};

    TestingString d;
    
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');

    affirm(*(d.begin()) == 'a');
    affirm(*(++d.begin()) == 'b');
    affirm(*(--d.end()) == 'c');
    
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

//--------------------------------------------------
//           RUNNING THE TESTS
//--------------------------------------------------

// Called if the test runs too long.
static void timeout_handler(int)
{
    // We go super-low-level here, because we can't trust anything in
    // the C/C++ library to really be working right.
    write(STDERR_FILENO, "Timeout occurred!\n", 18);
    abort();
}

/// Run tests
int main(int argc, char** argv)
{
    // Initalize testing environment
    TestingLogger alltests{"All tests"};

#if LOAD_GENERIC_STRING
    // Load the desired string implementation, if that's what we're doing.

    if (argc != 2) {
        cerr << "Usage ./stringtest plugin" << endl;
        exit(0);
    }

    GenericString::loadImplementation(argv[1]);
#else
    // No setup to do if we're using ChunkyString directly
#endif
    
    signal(SIGALRM, timeout_handler);   // Call this when the timer expires
    alarm(10);                          // set the timer at 10 seconds

    // Add calls to your tests here...
    // affirm(exampleTest());
    affirm(defaultTest());
    affirm(sizeTest());
    affirm(sizeTest1());
    affirm(stringsEqualTest());
    affirm(stringsNotEqualTest());
    affirm(stringsNotEqualTest1());
    affirm(stringsNotEqualTest2());
    affirm(stringsLessThan());
    affirm(stringsLessThan1());
    affirm(stringUtilization());
    // affirm(stringUtilization1());
    // affirm(stringErase());
    affirm(stringConcat());
    affirm(iteratorBeginTest());
    affirm(iteratorEndTest());
    affirm(iteratorEqualityTest());
    affirm(iteratorInequalityTest());
    affirm(iteratorIncrementTest());
    affirm(iteratorDecrementTest());
    affirm(iteratorDereferenceTest());

    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed.
    }
}

/* (Junk to make emacs use Stroustrup-style indentation)
 * Local Variables:
 * c-file-style: "stroustrup"
 * End:
 */
