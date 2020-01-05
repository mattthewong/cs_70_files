Authors: hmc-cs-bobcat and hmc-cs-heron
Date: 11/2/2016
Assignment: ChunkyString Week 2

ChunkyString Iterator

    For the ChunkyString, we originally decided in Homework 6 that we would make our
iterator with two private data members: a charsIndex_ to keep track of the position we are
at in the ChunkyString; and a chunkIndex_ to keep track of which Chunk we are at in the 
chunks_ data member of our ChunkyString object.
    After some deliberation, we decided to modify our design. Instead of having charsIndex_
and chunkIndex_, we will be implementing the iterator to have a charsIndex_ and another 
iterator called chunksIterator_. This iterator will be the built-in iterator of the
std::list library. In designing the ChunkyString iterator this way, our main goal was to 
solve the first problem we ran into when trying to write code: how to access a chunk from 
chunks_.
    By using the std::list built-in iterator, we not only create a way to access a distinct
Chunk, we also inherit other methods that allow us to manipulate the chunksIterator_, such as 
the dereference operator (*), the increment (++) and decrement operators (--), the comparison 
operators (== and !=), and other methods as well, like push_back() and size().
    We do, however, still need to write the following methods to manipulate the ChunkyString 
iterator:

\\ Copy constructor
\\ operator=
\\ operator++
\\ operator--
\\ operator*
\\ operator==

    As stated above, the ChunkyString iterator has two private data members: a charsIndex_ and
a chunksIterator_. When copy constructing, we would set our new iterator's charsIndex_ and 
chunksIterator_ equal to the original iterator's charsIndex_ and chunksIterator_, respectively.
    In Homework 6, we said that when incrementing or decrementing the iterator, we would want 
to move along the characters of the ChunkyString. We have not changed our design here; we still
want to move from character to character when incrementing or decrementing. Similarly, we also 
want to keep our dereference behavior intact; when we dereference the ChunkyString iterator, we
want the character that the iterator is currently at. We will also maintain the behavior in
incrementing and decrementing where we will move to the next Chunk, in whichever direction is 
appropriate, once we reach a chars_ space that is null (i.e. contains no character).
    The comparison operator (==), is the only one that changes since we decided to modify the data 
members of our iterator. If we compare two iterators lhs == rhs, we want to be sure that lhs and 
rhs point to the same spot in the same ChunkyString, so we would first check that lhs is pointing 
to the same Chunk as rhs, which can easily be done by using the built-in dereference operator of
the std::list iterator. If lhs and rhs point to the same Chunk and their charIndex_'s match, then
the two iterators are equal. As always, the operator!= should leverage operator==, so its design 
shouldn't change.
    At the moment, we do not foresee the need to write a function to convert from a non-constant
iterator to a constant iterator, but in the event that we decide to write one and use it, we will
probably implement it in the following way. We would simply initialize a constant iterator to have
the same charsIndex_ and chunksIterator_ as the original (non-constant) iterator, and return the
new constant iterator.

    The templated Iterator class returns two types: Element and ChunklistIterator. We need both of
these private data members because we need to not only keep track of the current character in the 
ChunkyString but also the current Chunk, and for the second item, we use the built-in std::list 
iterator.

ChunkyString Chunk

    In Homework 6, we stated that we would have liked to declare Chunk as a class, but now we are
choosing to modify it as a struct instead. We think this is a better decision because structs have
public data members and member functions, and are just their as supporting data structures. They
don't need anything fancy like operators or constructors that need to be specially defined; we can
just set them to default and let C++ handle it.
    A Chunk still has two data members, a chars_ array which holds the characters of the ChunkyString,
and a length_ member which holds the number of characters held in the Chunk. Since Chunk is a struct
and its behavior isn't really that complicated, we chose to make the copy constructor, assignment 
operator, and destructor default. The default constructor has been deleted, which is not something
we would like to change in the provided code. A convenience constructor exists which initializes
the length_ data member of a Chunk.

ChunkyString

    ChunkyString has two data members: size_, which holds the number of characters in the 
ChunkyString, and chunks_, which is a type std::list that holds the actual characters of the 
ChunkyString. Since we changed our design of the ChunkyString iterator, begin() and end() will
also change in their implementation.
    The ChunkyString iterator is responsible for looping through the actual characters of the
ChunkyString while also keeping track of which Chunk we are in, so begin() will return an iterator
that has a charsIndex_ of 0 since we want the very first character of the ChunkyString. In order to
initialize the chunksIterator_, we simply call begin() on the std::list, which will return an 
iterator. Similarly, end() will return an iterator whose charsIndex_ is set to one past the final
character of the ChunkyString, which is the length of the chars_ array of the last Chunk. Thus, 
the iterator returned by end will have an iterator returned by std::list's end() method, and 
charsIndex_ equal to length_ of the last Chunk.
    The push_back() method will change slightly since the iterator changed; the strategy is to
call end() and examine the charsIndex_ of the iterator. If the charsIndex_ is less than
(CHUNKSIZE - 2), then we can just set chars_[charsIndex_] equal to the character we're trying
to push_back(). If length_ is (CHUNKSIZE - 1), the chars_ array is full, in which case we want
to create a new Chunk, copy over the last half of the original Chunk's characters into the new
Chunk, and modify the length_ members of each Chunk accordingly. At this point, the end() iterator
has been invalidated, so we need to call end() again and push_back the character we want to one 
past the last spot in the chars_ array of the last Chunk, which is what end() points to. We also
still want to take care of the case where we try to push_back() to an empty ChunkyString. If this 
occurs, then we make a new Chunk, set chars_[0] to the character we want to push_back(), and then
use std::list's built-in push_back() to push the new Chunk with the character into chunks_.
Regardless of which case is called, size_ needs to be updated after the character is pushed.
    The size() method remains the way we designed it in Homework 6; it simply returns size_.
    Operator+='s design will pretty much remain the same as we defined it in Homework 6. If we 
would like to concatenate lhs += rhs, then we simply set an iterator at the beginning of rhs, 
loop through the characters of rhs, and push_back() each character to lhs. At the end, we update 
lhs.size_ by adding rhs.size_.
    Operator== (lhs == rhs) for a ChunkyString will first check that lhs.size_ is equal to rhs.size_.
If they are not equal, we return false. Otherwise, we loop through either lhs or rhs's characters.
Without loss of generality, let's say we loop through lhs. We compare the characters of lhs and rhs
position by position, and once we find that lhs's character is not equal to rhs's character, we
return false. If both the size and contents of lhs and rhs match, then we return true. As always,
we leverage operator== when writing operator!=.
    Operator< will leverage C++'s built-in lexicographical compare function, which takes in four
iterators (the lower case is important as these iterators are not ChunkyString iterators): begin()
and end() of the first ChunkyString, and begin() and end() of the second ChunkyString.
    The utilization() method will not change from Homework 6, since it's just a calculation.
    The print() method will simply loop through the characters of a ChunkyString and print them
to an ostream.
    The methods insert() and erase() do not have to be written yet.