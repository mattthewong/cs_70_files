
/**
 * \file hashset-private.hpp
 *
 * \author What are your CS70 aliases?
 *
 * \brief Implements HashSet<T>, a hash-table class template
 *
 * \remark There is no include-guard for this file, because it is
 *         only #included by hashset.hpp, inside hashset.hpp's
 *         own include guard.
 */

// Includes required for your templated code go here
#include <cstddef>
#include <string>
#include <forward_list>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include "stringhash.hpp"
// Templated code for member functions goes here

template <typename T>
HashSet<T>::HashSet()
    : size_{0}, buckets_{1},reallocations_{0}, collisions_{0}, 
        maximal_{0}
{
     hashArray_ = new std::forward_list<T>[1];
}

template <typename T>
HashSet<T>::~HashSet() 
{
    delete[] hashArray_;
}

template <typename T>
size_t HashSet<T>::size() const
{
    return size_;
}

template <typename T>

void HashSet<T>::insert(const T& element)
{
    double currentLoad = size_ / buckets_;
    if(exists(element)){
        return;
    }
    else {
        
        if(currentLoad < LOAD) { //if size_ /buckets ratio is less than 1
            ++size_; //add element and increase size
            long hashValue = myhash(element);
            size_t location = hashValue % buckets_;
            if(hashArray_[location].empty() == false){
                        ++collisions_;
            }
            hashArray_[location].push_front(element);

            //utilize distance from algorithm library to get distance    
            //from end to begin in each forward list (cast as size_t)
            if((size_t) std::distance(hashArray_[location].begin(), 
                hashArray_[location].end()) > maximal_){
                ++maximal_;
            }
        }
        else { //if the ratio of size_ / buckets is greater than 1
            ++reallocations_; // must reallocate in this case
            collisions_ = 0; // reset collisions for new array
            maximal_ = 0; // reset maximal for new array

            // new array twice the size           
            std::forward_list<T>* NewhashArray_ = 
            new std::forward_list<T>[buckets_ * 2];

            //loop through old array, and rehash and insert everything.
            for(size_t item = 0; item < buckets_; ++item) {
                for(auto i = hashArray_[item].begin(); 
                    i != hashArray_[item].end(); ++i) {
                    long NewhashValue = myhash(*i);
                    size_t newlocation = NewhashValue % (buckets_*2);

                    //add everything back into the hasharray.
                    if(NewhashArray_[newlocation].empty() == false){
                        ++collisions_;
                    }
                    NewhashArray_[newlocation].push_front(*i);

                    if((size_t) 
                        std::distance(NewhashArray_[newlocation].begin(),
                    NewhashArray_[newlocation].end()) > maximal_){
                        ++maximal_;
                    }
                }
            }
           
        buckets_ = buckets_ * 2; // update bucket size
        delete[] hashArray_;
        hashArray_ = NewhashArray_;
        insert(element); 
        }
    }    
}

template <typename T>
bool HashSet<T>::exists(const T& element) const
{
    // check bucket where element should be
    size_t location = myhash(element) % buckets_;

    // find algorith to check the linked list present in location
    return find(hashArray_[location].begin(), hashArray_[location].end(), 
        element) != hashArray_[location].end();
}

template <typename T>
size_t HashSet<T>::buckets() const
{
    return buckets_;
}

template <typename T>
size_t HashSet<T>::reallocations() const
{
    return reallocations_;
}

template <typename T>
size_t HashSet<T>::collisions() const
{
    return collisions_;
}

template <typename T>
size_t HashSet<T>::maximal() const
{
    return maximal_;
}
