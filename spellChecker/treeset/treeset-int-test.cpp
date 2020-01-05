/**
 * \file hashset-cow-test.cpp
 * \author CS 70 Provided Code -- don't add to this file, make a new one.
 *
 * \brief Tests a hashset to ensure that it is properly generic and doesn't
 *        contain any hidden dependencies on being a hashtable of strings.
 *        Does not extensively test HashSet functionality.
 */


/*****************************************************
 * Compatability Tests
 *
 *      Test for any hidden dependencies of HashSet on
 *      functions of the template type or included
 *      files.
 * ***************************************************/

// Don't put any includes before this one!  (Otherwise it won't be as good a
// test of whether the hashset is self sufficient.)  If you make another
// test file, it'll be okay to add other includes, like stringhash.hpp, but
// don't do that here.
#include "treeset.hpp"

#include <ostream> // For std::ostream
#include <cstddef> // For size_t

#include "signal.h" // For signal
#include "unistd.h" // For alarm
#include <algorithm>

template class TreeSet<int>;

#include "testing-logger.hpp"

/// Test insert and exists for cows
bool sizeTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"size test"};

    TreeSet<int> intTree;
    size_t inserts = 20;
    int i = 0;
    for(size_t j = 0; j < inserts; ++j){
        i = rand();
        intTree.insert(i);
    }
    intTree.showStatistics(std::cout);
    affirm(intTree.size() == inserts);
    //intTree.print(std::cout);
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/****************************
 * Boilerplate main function
 * **************************/

// Called if the test runs too long.
static void timeout_handler(int)
{
    // We go super-low-level here, because we can't trust anything in
    // the C/C++ library to really be working right.
    write(STDERR_FILENO, "Timeout occurred!\n", 18);
    abort();
}

/// Run tests
int main()
{
    // Initalize testing environment
    TestingLogger alltests{"All tests"};

    signal(SIGALRM, timeout_handler);   // Call this when the timer expires
    alarm(10);                          // set the timer at 10 seconds

    // Add calls to your tests here...
    affirm(sizeTest());

    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed
    }

}
