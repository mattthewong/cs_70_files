/*
 * \file intlist.cpp
 * \authors YOUR ALIASES HERE
 * \brief Implemenation of IntList and its private classes.
*/

#include "intlist.hpp"
#include "testing-logger.hpp"

using namespace std;

IntList::IntList() 
    : back_{nullptr},
      front_{nullptr},
      size_{0}
{
    affirm(consistent() && empty());
}

IntList::~IntList()
{       
    for (size_t i = 0; i != size_; ++i) {
        Element* temp = front_->next_;
        delete front_;
        front_ = temp;
        temp = nullptr;
    }
    back_ = nullptr;
    size_ = 0;
}

IntList::IntList(const IntList& orig)
    : back_{nullptr}, front_{nullptr}, size_{0}
{
    if (orig.size_ > 0) {
        for (Iterator i = orig.begin(); i != orig.end(); ++i) {
            push_back(*i);
        }
    }
        
    affirm(consistent());
}

void IntList::swap(IntList& rhs)
{
    // This is the canonical way to swap arbitrary types; this incantation
    // will call std::swap unless we're swapping a class that provides its
    // own swap function (like we do), in which case that swap is called.
    // Here we end up calling std::swap since the swapped parts are primitives.

    using std::swap;

    swap(back_, rhs.back_);
    swap(front_, rhs.front_);
    swap(size_, rhs.size_);
    affirm(consistent());
}

void swap(IntList& lhs, IntList& rhs) { lhs.swap(rhs); }

IntList& IntList::operator=(const IntList& rhs)
{
    // Assignment is implemented idiomatically for C++, using "the swap trick"
    IntList copy = rhs;
    swap(copy);

    affirm(consistent());
    return *this;
}


size_t IntList::size() const
{ 
    return size_;
}


bool IntList::empty() const
{
    return (size_ == 0);
}



bool IntList::operator==(const IntList& rhs) const
{
    if (rhs.size_ != size_) {
        return false;
    }

    Iterator i = begin();
    Iterator j = rhs.begin();
    for ( ; i != end(); ++i, ++j) {
        if (*i != *j) {
            return false;
        }
    }
    return true;
}



bool IntList::operator!=(const IntList& rhs) const
{
    // Idiomatic code: leverage == to implement !=
    return !operator==(rhs);
}



void IntList::push_front(int pushee)
{
    Element* newpointer = new Element(pushee, nullptr);

    if (size_ == 0) {
        back_ = newpointer;
        front_ = newpointer;
    }

    else {
        newpointer->next_ = front_;
        front_ = newpointer;
    }
    
    newpointer = nullptr;
    ++size_;

    affirm(consistent() && !empty());
}


int IntList::pop_front()
{
    int val = 0;
    
    if (size_ == 1) {
        val = front_->value_;
        delete front_;
        front_ = nullptr;
        back_ = nullptr;
        --size_;
    }

    else if (size_ > 1) {
        val = front_->value_;
        Element* temp = front_->next_;
        delete front_;
        front_ = temp;
        --size_;
        temp = nullptr;
    }
    
    affirm(consistent());
    return val;
}

void IntList::push_back(int pushee)
{
    Element* newpointer = new Element(pushee, nullptr);

    if (size_ == 0) {
        back_ = newpointer;
        front_ = newpointer;
    }

    else {
        back_->next_ = newpointer;
        back_ = newpointer;
    }
    
    newpointer = nullptr;
    ++size_;

    affirm(consistent());
}



void IntList::insert_after(iterator where, int value)
{
    Element* newElement = new Element(value, nullptr);

    if (where == back_) {
        (where.current_)->next_ = newElement;
        back_ = newElement;
    }

    else { 
        Element* setNext = (where.current_)->next_;
        (where.current_)->next_ = newElement;
        newElement->next_ = setNext;
    }
    
    ++size_;
    affirm(consistent() && !empty());
}



IntList::iterator IntList::begin() const
{
    return Iterator(front_);
}

IntList::iterator IntList::end() const
{
    Iterator temp = Iterator(front_);
    for (size_t i = 0; i < size_; ++i) {
        temp.current_ = (temp.current_)->next_;
    }
    return temp;
}


bool IntList::consistent() const
{
    return ((front_ == nullptr) && (back_ == nullptr) && (size_ == 0))
           || ((front_ == back_) && (size_ == 1))
           || ((front_ != back_) && (size_ > 1));
}

// --------------------------------------
// Implementation of IntList::Element
// --------------------------------------

IntList::Element::Element(int value, Element* next) : value_{value}, next_{next}
{
    // Nothing else to do.
}

// --------------------------------------
// Implementation of IntList::Iterator
// --------------------------------------

IntList::Iterator::Iterator(Element* current) : current_{current}
{
    // Nothing else to do.
}


IntList::Iterator& IntList::Iterator::operator++()
{
    Element* nextEl = current_->next_;
    current_ = nextEl;
    return *this;
}

int& IntList::Iterator::operator*() const
{
    return current_->value_;
}


bool IntList::Iterator::operator==(const Iterator& rhs) const
{
    return current_ == rhs.current_;
}

bool IntList::Iterator::operator!=(const Iterator& rhs) const
{
    return !(*this == rhs);
}

