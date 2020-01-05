/**
 * \file chunkystring.cpp
 *
 * \authors bobcat and heron
 *
 * \brief Implements the ChunkyString class.
 */

// #ifndef CHUNKYSTRING_HPP_INCLUDED
// #define CHUNKYSTRING_HPP_INCLUDED 1

#include "chunkystring.hpp"
#include "testing-logger.hpp"

#include <cstddef>
#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <type_traits>

using namespace std;

/**
* \brief Default constructor
*
* \details The default constructor builds a ChunkyString object
*          with a size_ of 0, and leaves the chars_ array null.
*
* \note constant time
*/
ChunkyString::ChunkyString(): size_{0} {
    // Nothing else to do here...
}

/**
* \brief Iterator begin() method
*
* \return an iterator that points to the first Chunk of the ChunkyString
*/
ChunkyString::iterator ChunkyString::begin() {
    return iterator(0, chunks_.begin());
}

/**
* \brief Iterator end() method
*
* \return an iterator that points past the last Chunk of the ChunkyString
*/
ChunkyString::iterator ChunkyString::end() {
    return iterator(0, chunks_.end());
}
    
/**
* \brief Iterator constant begin() method
*
* \return a constant iterator that points to the first Chunk of the 
*         ChunkyString
*/
ChunkyString::const_iterator ChunkyString::begin() const {
    return const_iterator(0, chunks_.begin());
}
    
/**
* \brief Iterator constant end() method
*
* \return a constant iterator that points past the last Chunk of the
*         ChunkyString
*/
ChunkyString::const_iterator ChunkyString::end() const {
    return const_iterator(0, chunks_.end());
}

/**
* \brief Inserts a character at the end of the ChunkyString.
*
* \param c Character to insert
* 
* \note constant time
*/
void ChunkyString::push_back(char c) {
    if ((size_ == 0) || (chunks_.back().length_ = Chunk::CHUNKSIZE)) {
        Chunk newChunk = Chunk(c);
        chunks_.push_back(newChunk);
    }
    else {
        Chunk& last = chunks_.back();
        last.chars_[last.length_] = c;
        ++last.length_;
    }
    ++size_;
}

/**
* \brief size() method to return size_ of ChunkyString
*/   
size_t ChunkyString::size() const {
    return size_;
}    

/**
* \brief operator+= method
*
* \details concatenates two ChunkyStrings together
*/ 
ChunkyString& ChunkyString::operator+=(const ChunkyString& rhs) {
    if (rhs.size_ > 0) {
        const_iterator e = rhs.end();
        for (const_iterator i = rhs.begin(); i != e; ++i) {
            Chunk newChunk = *i;
            chunks_.push_back(newChunk);
        }
    }
    size_ += rhs.size();
    return *this;
}

/**
* \brief operator==
*
* \details compares two ChunkyStrings for equality
*
* \return true if the two ChunkyStrings are the same size and
*         have the same contents, false otherwise
*/ 
bool ChunkyString::operator==(const ChunkyString& rhs) const {
    if (size_ == rhs.size_) {
        const_iterator j = begin();
        const_iterator e = rhs.end();
        for (const_iterator i = rhs.begin(); i != e; ++i) {
            if (i.chunksIterator_->chars_[i.charsIndex_] != j.chunksIterator_->chars_[j.charsIndex_]) {
                return false;
            }
            ++j;
        }
        return true;
    }
    return false;
}

/**
* \brief operator!=
*
* \details leverages operator==
*/ 
bool ChunkyString::operator!=(const ChunkyString& rhs) const {
    return !(operator==(rhs));
}

/**
* \brief operator<
*
* \details lexicographical_compare method, leverage built-in library method
*/ 
bool ChunkyString::operator<(const ChunkyString& rhs) const {
    return std::lexicographical_compare(begin(), --end(), rhs.begin(), --rhs.end());
}

/**
* \brief print method
*
* \details prints contents of ChunkyString to standard out
*/
std::ostream& ChunkyString::print(std::ostream& out) const {
    const_iterator e = end();
    for (const_iterator i = begin(); i != e; ++i) {
        char outChar = i.chunksIterator_->chars_[i.charsIndex_];
        out << outChar;
    }
    return out;
}

/**
* \brief Average capacity of each chunk, as a percentage
* \details 
*   This function computes the fraction of the ChunkyString's character
*   cells that are in use. It is defined as 
*
*   \f[\frac{\mbox{number of characters in the string}}
*           {\mbox{number of chunks}\times\mbox{CHUNKSIZE}}  \f] 
*   
*   For reasonably sized strings (i.e., those with more than one or two 
*   characters), utilization should never fall to near one character per 
*   chunk; otherwise the data structure would be wasting too much space.
*
*   The utilization for an empty string is undefined (i.e., any value is
*   acceptable).
*/
double ChunkyString::utilization() const {
    return size() / (float)Chunk::CHUNKSIZE * chunks_.size();
}

// --------------------------------------
// Implementation of ChunkyString::Chunk
// --------------------------------------

/**
* \brief Convenience constructor of Chunk
*
* \param length Value we set length_ data member to.
*/
ChunkyString::Chunk::Chunk(size_t length): length_{length} {
    // Nothing else to do here...
}

// -----------------------------------------
// Implementation of ChunkyString::Iterator
// -----------------------------------------

// Implemented in iterator-private.hpp

// #endif // CHUNKYSTRING_HPP_INCLUDED
