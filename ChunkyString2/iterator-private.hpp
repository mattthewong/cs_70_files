/*********************************************************************
 * ChunkyString::Iterator class.
 *********************************************************************
 *
 * Implementation for the templated ChunkyString iterator
 *
 */

 // No default constructor because it's synthesized

template <typename Element, typename ChunklistIterator>
ChunkyString::Iterator<Element, ChunklistIterator>::Iterator(
            size_t index, ChunklistIterator i) : 
            charsIndex_{index}, chunksIterator_{i}
{
    // Nothing else to do here...
}

template <typename Element, typename ChunklistIterator>
ChunkyString::Iterator<Element, ChunklistIterator>::Iterator(
            const ChunkyString::Iterator<value_type, chunklist_iter_t>& i) : 
            charsIndex_{i.charsIndex_}, chunksIterator_{i.chunksIterator_}
{
    // Nothing else to do here...
}

template <typename Element, typename ChunklistIterator>
ChunkyString::Iterator<Element, ChunklistIterator>& ChunkyString::Iterator<Element, ChunklistIterator>::operator++()
{
    if (charsIndex_ == chunksIterator_->length_ - 1) {
        ++chunksIterator_; // move to next Chunk
        charsIndex_ = 0; // reset to top of chars_
    }
    else {
        ++charsIndex_; // move to next character in chars_
    }
    return *this;
}

template <typename Element, typename ChunklistIterator>
ChunkyString::Iterator<Element, ChunklistIterator>& ChunkyString::Iterator<Element, ChunklistIterator>::operator--()
{
    if (charsIndex_ == 0) {
        --chunksIterator_;
        charsIndex_ = chunksIterator_->length_ - 1;
    }
    else {
        --charsIndex_;
    }
    return *this;
}

template <typename Element, typename ChunklistIterator>
typename ChunkyString::Iterator<Element, ChunklistIterator>::reference 
    ChunkyString::Iterator<Element, ChunklistIterator>::operator*() const
{
    return chunksIterator_->chars_[charsIndex_];
}

template <typename Element, typename ChunklistIterator>
bool  ChunkyString::Iterator<Element, ChunklistIterator>::operator==(
        const Iterator<Element, ChunklistIterator>& rhs) const
{
    return ((chunksIterator_ == rhs.chunksIterator_) && (charsIndex_ == rhs.charsIndex_));
}
