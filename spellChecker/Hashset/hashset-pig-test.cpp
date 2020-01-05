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

#include "hashset.hpp"
#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <string>
#include "signal.h" // For signal
#include "unistd.h" // For alarm

class Pig {

public:
    /// Non-default constructor.
    // (Classes used with hash tables aren't required to have a default
    //  constructor.)
    explicit Pig(std::string name);


    std::string name_;   ///< name of our pig

    // Give external functions friend access
    friend bool operator==(const Pig& lhs, const Pig& rhs);
};

/// Equality for Pigs
bool operator==(const Pig& lhs, const Pig& rhs)
{
    return lhs.name_ == rhs.name_;
}

Pig::Pig(std::string name)
    : name_(name)
{
    // Nothing (else) to do.
}

/// Hash function for Pig
size_t myhash(const Pig& inputPig)
{
//     std::string str = inputPig.name_;
//     size_t h = 0; // initialized hash value
//     for (size_t i=0; i<str.length(); i++) {
//         h = (h << 6) ^ (h >> 26) ^ str[i];
// }
//   return h;
    return 42;
}


// Explicitly instantiate the entire templated class (normally C++ is lazy
// and only instantiates the things it needs as it needs them, here we make
// it do everything.)

template class HashSet<Pig>;

/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for HashSet
 * ***************************************************/

#include "testing-logger.hpp"

/// Test insert and exists for cows
bool pigTestSuite()
{
    // Set up the TestingLogger object
    TestingLogger log{"example test"};

    // initilze pig one and set of Pigs
    Pig one("Bob");
    HashSet<Pig> pigSet;

    affirm(!pigSet.exists(one));
    pigSet.insert(one);
    affirm(pigSet.exists(one));

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();

}
//checks insertion of same pig, affirming that size_ is 1.
bool insertPigTest() {
    // Set up the TestingLogger object
    TestingLogger log{"insertPigTest"};
    HashSet<Pig> pigSet;
    Pig one("Anthony");
    Pig two("Anthony");
    affirm(!pigSet.exists(one));
    affirm(!pigSet.exists(two));
    pigSet.insert(one);
    pigSet.insert(two);
    affirm(pigSet.exists(one));
    affirm(pigSet.size() == 1);
    return log.summarize();
}
//checks insertion of two different pigs, affirming that size_ is 2.
bool insertPigTest1() {
    // Set up the TestingLogger object
    TestingLogger log{"insertPigTest1"};
    HashSet<Pig> pigSet;
    Pig one("Anthony");
    Pig two("Matt");
    affirm(!pigSet.exists(one));
    affirm(!pigSet.exists(two));
    pigSet.insert(one);
    pigSet.insert(two);

    affirm(pigSet.exists(one));
    affirm(pigSet.exists(two));

    affirm(pigSet.size() == 2);
    affirm(pigSet.collisions() == 1);
    affirm(pigSet.maximal() == 2);

    return log.summarize();
}

bool 
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
int main(int argc, char** argv)
{
    // Initalize testing environment
    TestingLogger alltests{"All tests"};

    signal(SIGALRM, timeout_handler);   // Call this when the timer expires
    alarm(10);                          // set the timer at 10 seconds

    // Add calls to your tests here...
    affirm(pigTestSuite());
    affirm(insertPigTest());
    affirm(insertPigTest1());
    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed.
    }

}

