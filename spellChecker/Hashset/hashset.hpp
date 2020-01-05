/**
 * \file hashset.hpp
 *
 * \author Pig and Heron
 *
 * \brief Provides HashSet<T>, a set class template, using hash tables
 */

#ifndef HASHSET_HPP_INCLUDED
#define HASHSET_HPP_INCLUDED 1

#include <cstddef>
#include <string>
#include <forward_list>
#include <iostream>
#include <type_traits>
using namespace std;
/**
 * \class HashSet
 * \brief Templeted hash set capable of amortized 
 *  constant time insert and lookup functions.
 *    
 * \details This HashSet implements separate chaining as means of 
 *  collision resolution.
 *
 * \remarks
 *   Uses C++11's STL singly-linked list.
 */

// template declaration
template <typename T>

class HashSet {

const double LOAD = 1.0; ///< size/buckets load factor
public:
   
    HashSet();

    /**
     * \brief Destructor
     */
    ~HashSet();

    /**
     * \brief Insert element into HashSet
     * \param Element to be inserted into table
    **/
    void insert(const T& element);

    /**
     * \brief HashSet lookup 
     * \param Element to be looked for in HashSet
     * \returns True if element is already in the table
    **/
    bool exists(const T& element) const;

    // Table data
    size_t size() const; ///< Number of items stored in table
    size_t buckets() const; ///< Number of buckets in table
    size_t reallocations() const; ///< Number of times table has resized
    size_t collisions() const; ///< Number of bucket collisions following insertions 
    size_t maximal() const; ///< Length of longest separete-chain in table

    private:
        
        size_t size_; ///< Total number of items in all linked lists
        size_t buckets_; ///< Current number of buckets in table
        size_t reallocations_; ///< Number of table resizes
        size_t collisions_; ///< Number of table collisions
        size_t maximal_; ///< Length of longest linked-list in table
        std::forward_list<T>* hashArray_; ///< Array holding linked lists
};

// Because the hashset code is templated, it must appear in this header file
// instead of a normal .cpp file. We do this by moving the nasty implementation
// details into hashset-private.hpp, and recursively including that here.  This
// way, readers don't see the actual code unless they want to, and aren't forced
// to manually include two separate header files every time they want to use
// this hash table.

#include "hashset-private.hpp"

#endif
