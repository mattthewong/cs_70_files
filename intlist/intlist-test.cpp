/**
 * \file intlist-test.cpp
 * \authors CS 70 Starter Code
 * \brief The program unit tests the IntList class.
 *
 * \details Part of the CS 70 IntList assignment.
 */

/* Note: In testing, it's always a good idea to #include the header you're
 *       testing without including anything else beforehand.  That way, you
 *       won't accidentally depend on something being included for your
 *       header to compile.
 */
#include "intlist.hpp"
#include "testing-logger.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <list>

#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


///////////////////////////////////////////////////////////
//  TESTING
///////////////////////////////////////////////////////////

// ISSUE 0 TESTS

/** \brief Test default constructor for IntLists
 */
bool defaultConstructorTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"default constructor"};

    // Set up for your test
    IntList myList;

    // Add checks for things that should be true. 
    affirm(myList.size() == 0);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 1 TESTS
// Add tests here for push_front, begin, and the dereference operator.

/** \brief Test push_front
 *  \detail Tests the general case where intList already has elements 
            in it initially.
 */
bool pushFrontTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_front"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(19);
    myList.push_front(20);

    // Fill in the test content here...
    affirm(myList.size() == 3);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test push_front
 *  \detail Tests the edge case where intList only has one element 
            in it initially.
 */
bool pushFrontTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_front"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(20);

    // Fill in the test content here...
    affirm(myList.size() == 2);
    // affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test push_front
 *  \detail Tests the general case where intList has no elements in it 
            initially.
 */
bool pushFrontTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_front"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);

    // Fill in the test content here...
    affirm(myList.size() == 1);
    // affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test begin
 *  \detail Tests the general case where intList already has elements in it.
 */
bool beginTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"begin"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(19);
    myList.push_front(20);

    // Fill in the test content here...
    affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test begin
 *  \detail Tests the edge case where intList only has one element in
            it initially.
 */
bool beginTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"begin"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(20);

    // Fill in the test content here...
    affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test begin
 *  \detail Tests the edge case where intList only has no elements in 
            it initially.
 */
bool beginTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"begin"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);

    // Fill in the test content here...
    affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test operator*
 *  \detail Tests that operator* is returning a reference to the 
            value of the first element in intList.
 */
bool operatorStarTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"operator*"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);

    // Fill in the test content here...
    affirm(*myList.begin() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 2 TESTS

/** \brief Test pop_front
 *  \detail Tests that pop_front is returning the value of the element
            we just removed from the beginning of the list in the case
            where intList has size_ > 1.
 */
bool pop_frontTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"pop_front"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(15);
    myList.push_front(10);
    myList.push_front(5);

    // Fill in the test content here...
    affirm(myList.pop_front() == 5);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test pop_front
 *  \detail Tests that pop_front is returning the value of the element
            we just removed from the beginning of the list in the case
            where intList has size_ == 1.
 */
bool pop_frontTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"pop_front"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);

    // Fill in the test content here...
    affirm(myList.pop_front() == 20);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test pop_front
 *  \detail Tests that pop_front is returning the value of the element
            we just removed from the beginning of the list in the case
            where intList has size_ == 0.
 */
bool pop_frontTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"pop_front"};

    // Set up for your test
    IntList myList;
    
    // Fill in the test content here...
    affirm(myList.pop_front() == 0);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test empty
 *  \detail Tests that empty is returning true when size_ == 0.
 */
bool emptyTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"empty"};

    // Set up for your test
    IntList myList;

    // Fill in the test content here...
    affirm(myList.empty() == true);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test empty
 *  \detail Tests that empty is returning true when size_ == 0.
 */
bool emptyTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"empty"};

    // Set up for your test
    IntList myList;
    myList.push_front(2);

    // Fill in the test content here...
    affirm(myList.empty() == false);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test destructor
 *  \detail Tests that IntList is destroyed when size_ == 0.
 */
bool destructorTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"~IntList"};

    // Set up for your test
    IntList myList;
    myList.~IntList();

    // Fill in the test content here...
    affirm(true);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test destructor
 *  \detail Tests that IntList is destroyed when size_ == 1.
 */
bool destructorTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"~IntList"};

    // Set up for your test
    IntList myList;
    myList.push_front(2);
    myList.~IntList();
    
    // Fill in the test content here...
    affirm(true);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test destructor
 *  \detail Tests that IntList is destroyed when size_ == 2.
 */
bool destructorTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"~IntList"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(15);
    myList.~IntList();
    
    // Fill in the test content here...
    affirm(true);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test destructor
 *  \detail Tests that IntList is destroyed when size_ > 2.
 */
bool destructorTest3()
{
    // Set up the TestingLogger object
    TestingLogger log{"~IntList"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(15);
    myList.push_front(5);
    myList.~IntList();
    
    // Fill in the test content here...
    affirm(true);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 3 TESTS

/** \brief Test push_back
 *  \detail Tests the general case where intList already has elements 
            in it initially.
 */
bool pushBackTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_back"};

    // Set up for your test
    IntList myList;
    myList.push_back(1);
    myList.push_back(19);
    myList.push_back(20);

    // Fill in the test content here...
    affirm(myList.size() == 3);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test push_back
 *  \detail Tests the edge case where intList already has one element 
            in it initially.
 */
bool pushBackTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_back"};

    // Set up for your test
    IntList myList;
    myList.push_back(1);
    myList.push_back(19);

    // Fill in the test content here...
    affirm(myList.size() == 2);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test push_back
 *  \detail Tests the edge case where intList already has no elements in
            it initially.
 */
bool pushBackTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"push_back"};

    // Set up for your test
    IntList myList;
    myList.push_back(1);

    // Fill in the test content here...
    affirm(myList.size() == 1);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test end
 *  \detail Tests the general case where intList already has elements 
            in it.
 */
bool endTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"end"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(19);
    myList.push_front(20);

    IntList::iterator i = myList.begin(); 
    for ( ; i != myList.end(); ++i) {
        // Do nothing...
    }

    // Fill in the test content here...
    affirm(i == myList.end());

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test end
 *  \detail Tests the edge case where intList only has one element in
            it initially.
 */
bool endTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"end"};

    // Set up for your test
    IntList myList;
    myList.push_front(1);
    myList.push_front(20);

    IntList::iterator i = myList.begin(); 
    for ( ; i != myList.end(); ++i) {
        // Do nothing...
    }

    // Fill in the test content here...
    affirm(i == myList.end());

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test end
 *  \detail Tests the edge case where intList only has no elements in
            it initially.
 */
bool endTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"end"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);

    IntList::iterator i = myList.begin(); 
    for ( ; i != myList.end(); ++i) {
        // Do nothing...
    }

    // Fill in the test content here...
    affirm(i == myList.end());

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 4 TESTS

/** \brief Test insert_after
 *  \detail Tests the edge case where the parameter where points to the 
            front_ of the intList.
 */
bool insertAfterTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"insert_after"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.insert_after(myList.begin(), 10);
    IntList::iterator i = myList.begin();
    ++i;

    // Fill in the test content here...
    affirm(*i == 10);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test insert_after
 *  \detail Tests the general case where the parameter where points 
            to the end of the intList.
 */
bool insertAfterTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"insert_after"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(8);
    myList.push_front(3);

    IntList::iterator point = myList.begin();

    for (size_t i = 0 ; i < myList.size() - 1; ++i) {
        ++point;
    }

    myList.insert_after(point, 10);

    ++point;
    // Fill in the test content here...
    affirm(*point == 10);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test insert_after
 *  \detail Tests the general case where the parameter where points 
            to an element in the middle of intList.
 */
bool insertAfterTest2()
{
    // Set up the TestingLogger object
    TestingLogger log{"insert_after"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(8);
    myList.push_front(3);

    IntList::iterator point = myList.begin();

    for (size_t i = 0 ; i < myList.size() - 1; ++i) {
        ++point;
    }

    myList.insert_after(point, 10);

    ++point;

    // Fill in the test content here...
    affirm(*point == 10);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 5 TESTS

/** \brief Test operator==
 *  \detail Tests the whether or not two IntLists are equal.
 */
bool IntListEqualTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"operator=="};

    // Set up for your test
    IntList myList;
    IntList myList2;
    myList.push_front(20);
    myList.push_front(8);
    myList.push_front(3);
    myList2.push_front(20);
    myList2.push_front(8);
    myList2.push_front(3);

    // Fill in the test content here...
    affirm(myList == myList2);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}


/** \brief Test operator==
 *  \detail Tests the whether or not two IntLists are equal.
 */
bool IntListEqualTest1()
{
    // Set up the TestingLogger object
    TestingLogger log{"operator=="};

    // Set up for your test
    IntList myList;
    IntList myList2;

    // Fill in the test content here...
    affirm(myList == myList2);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test operator!=
 *  \detail Tests the whether or not two IntLists are equal.
 */
bool IntListNotEqualTest()
{
    // Set up the TestingLogger object
    TestingLogger log{"operator!="};

    // Set up for your test
    IntList myList;
    IntList myList2;
    myList.push_front(20);
    myList.push_front(5);
    myList.push_front(3);
    myList2.push_front(20);
    myList2.push_front(8);
    myList2.push_front(3);

    // Fill in the test content here...
    affirm(myList != myList2);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

// ISSUE 6 TESTS
/** \brief Test Copy constructor
 *  \detail Tests whether or not the original list is copied into a
            new list.
 */
bool TestCopyConstructor()
{
    // Set up the TestingLogger object
    TestingLogger log{"IntList"};

    // Set up for your test
    IntList myList;
    myList.push_front(20);
    myList.push_front(5);
    myList.push_front(3);
    IntList myList2 = myList;

    // Fill in the test content here...
    affirm(myList == myList2);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/*
 * Test the IntList!
 */
int main(int, char**)
{
    TestingLogger alltests{"All tests"};
    
    affirm(defaultConstructorTest());
    affirm(pushFrontTest());
    affirm(pushFrontTest1());
    affirm(pushFrontTest2());
    affirm(beginTest());
    affirm(beginTest1());
    affirm(beginTest2());
    affirm(operatorStarTest());
    affirm(pop_frontTest());
    affirm(pop_frontTest1());
    affirm(pop_frontTest2());
    affirm(emptyTest());
    affirm(emptyTest1());
    affirm(destructorTest());
    affirm(destructorTest1());
    affirm(destructorTest2());
    affirm(destructorTest3());
    affirm(pushBackTest());
    affirm(pushBackTest1());
    affirm(pushBackTest2());
    affirm(endTest());
    affirm(endTest1());
    affirm(endTest2());
    affirm(insertAfterTest());
    affirm(insertAfterTest1());
    affirm(insertAfterTest2());
    affirm(IntListEqualTest());
    affirm(IntListEqualTest1());
    affirm(IntListNotEqualTest());
    affirm(TestCopyConstructor());

    // Print a summary of the all the affirmations and exit the program.

    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means 
                        // tests failed.
    }
}

/* Junk to make emacs use the right C++ style when editing this code:
 *   Local Variables:
 *   c-file-style: "stroustrup"
 *   End:
 */
