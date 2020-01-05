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


/**
 * \class Cow
 * \brief
 *   Test class which implements the bare minimum to be usable with a HashSet.
 * \remarks
 *   As this class is very brief and intended purely for testing
 *   purposes, we keep it completely contained within this file. Doing
 *   so on production level code is problematic.
 */
class Cow {

public:
    /// Non-default constructor.
    // (Classes used with hash tables aren't required to have a default
    //  constructor.)
    explicit Cow(size_t numHats);

private:
    size_t numHats_;   ///< How many hats does our Cow have?

    // Give external functions friend access
    friend std::ostream& operator<<(std::ostream& out, const Cow& printMe);
    friend bool operator==(const Cow& lhs, const Cow& rhs);
    friend bool operator<(const Cow& lhs, const Cow& rhs);
};
Cow::Cow(size_t numHats) : numHats_{numHats} {
    // nothing else to do
}
/// Equality for Cows
bool operator==(const Cow& lhs, const Cow& rhs)
{
    return lhs.numHats_ == rhs.numHats_;
}
std::ostream& operator<<(std::ostream& out, const Cow& printMe) {
    for (size_t i = 0; i < printMe.numHats_; ++i)
        out << "        _====_\n";

    out << "         (__)\n"    // Shamelessly taken from Debian's (& Ubuntu's)
        << "         (oo)\n"    //    apt-get moo
        << "   /------\\/ \n"   // (apt has "super cow" powers)
        << "  / |    ||  \n"
        << " *  /\\---/\\  \n"
        << "    ~~   ~~  \n";
    return out; 
}

bool operator<(const Cow& lhs, const Cow& rhs)
{
    return lhs.numHats_ < rhs.numHats_;
}

template class TreeSet<Cow>;

/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for HashSet
 * ***************************************************/

#include "testing-logger.hpp"

/// Test insert and exists for cows
bool cowTestSuite()
{
    // Set up the TestingLogger object
    TestingLogger log{"example test"};

    Cow mabel(3);
    Cow a(1);
    Cow b(2);
    Cow c(43);
    Cow d(5);
    TreeSet<Cow> myTree;
    affirm(!myTree.exists(mabel));
    myTree.insert(mabel);
    //std::cout << myTree.size() << std::endl;
    myTree.insert(a);
    //std::cout << myTree.size() << std::endl;
    myTree.insert(b);
    //std::cout << myTree.size() << std::endl;
    myTree.insert(c);
    
    myTree.insert(d);
    affirm(myTree.size() == 5);
    affirm(myTree.exists(mabel));
    std::cout << myTree.size() << std::endl;
    std::cout << myTree.height() << std::endl;
    myTree.print(std::cout);
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();

}
//Tests insert() and size() when adding one cow to the TreeSet myTree.
bool checkSize()
{
// Set up the TestingLogger object
    TestingLogger log{"checksize"};

    Cow matt(1);
    TreeSet<Cow> myTree;
    affirm(!myTree.exists(matt));
    affirm(myTree.size()==0);
    myTree.insert(matt);
    affirm(myTree.exists(matt));
    affirm(myTree.size()==1);
    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}
// Tests the reinsertion of the same cow to TreeSet myTree.
bool checkSize1()
{
// Set up the TestingLogger object
    TestingLogger log{"checksize1"};

    Cow matt(1);
    TreeSet<Cow> myTree;
    affirm(!myTree.exists(matt));
    affirm(myTree.size()==0);
    myTree.insert(matt);
    affirm(myTree.exists(matt));
    affirm(myTree.size()==1);
    myTree.insert(matt);
    affirm(myTree.size()==1);
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
    affirm(cowTestSuite());
    affirm(checkSize());
    affirm(checkSize1());
    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed.
    }

}

