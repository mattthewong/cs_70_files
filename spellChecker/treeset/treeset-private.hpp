/**
 * \file treeset-private.hpp
 *
 * \author Pig and Heron
 *
 * \brief implements the UI found in "treeset.hpp"
 */

#include <cstddef>
#include <string>
#include <list>
#include <iostream>
#include <type_traits>
#include <random>
#include <algorithm>
#include <cmath>


template <typename T>
TreeSet<T>::TreeSet()
    : size_{0}, root_{nullptr}
{
    // nothing to do here
}
template <typename T>
TreeSet<T>::~TreeSet() {
    delete root_;
}

template <typename T>
TreeSet<T>::Node::~Node() 
{
    if (left_ != nullptr) {
        delete left_;
    }
    if (right_ != nullptr) {
        delete right_;
    }
}

template <typename T>
size_t TreeSet<T>::size() const 
{
    return size_;
}

template <typename T>
void TreeSet<T>::seed()
{
    std::random_device rd;
    gen_.seed(rd());
}

template <typename T>
float TreeSet<T>::getRandomFloat() 
{
    return dis_(gen_);
}

template <typename T>
void TreeSet<T>::insert(const T& value) 
{
    if (root_ == nullptr) {
        insertNodeAtRoot(root_, value);
        ++size_;
        return;
    }

    // generate a random float and calculate odds
    float location = getRandomFloat();
    float rootOdds = 1.0 / (root_->subSize_ + 1);

    if (!exists(value)) {
        if (value < root_->data_) { // randomized insert to left subtree
            if (location <= rootOdds) {
                insertNodeAtRoot(root_->left_, value);
                ++size_;
                return;
            }
            ++size_;
            insertHelper(root_->left_, value);
        }
        else { //randomized insert in right subtree
            if (location <= rootOdds) {
                insertNodeAtRoot(root_->right_, value);
                ++size_;
                return;
            }
            ++size_;
            insertHelper(root_->right_, value);
        }
    }
}

template <typename T>
void TreeSet<T>::insertHelper(Node*& here, const T& value)
{
    if (here == nullptr) {
        here = new Node{value, nullptr, nullptr, 1};
    }
    else if (value < here->data_) {
        insertHelper(here->left_, value);
    }
    else {
        insertHelper(here->right_, value);
    }
}

template <typename T>
int TreeSet<T>::heightHelper(Node* node) const
{
    if (node == nullptr){
        return -1;
    }
    return 1 + std::max(heightHelper(node->left_), 
        heightHelper(node->right_));
}

template <typename T>
void TreeSet<T>::rightRotate(Node*& top) 
{
    
    Node* b = top->left_;   // b is d's left child
    size_t tempSize = 0;
    if (b->left_ != nullptr) {
       tempSize = b->left_->subSize_;
    }
    b->subSize_ = top->subSize_;
    top->subSize_ -= (1 + tempSize);
    top->left_ = b->right_; // C becomes left child of d
    b->right_ = top;        // d becomes right child of b
    top = b;
}

template <typename T>
void TreeSet<T>::leftRotate(Node*& top) 
{
    
    Node* d = top->right_; // d is b's right child
    size_t tempSize = 0;
    if (d->right_ != nullptr) {
       tempSize = d->right_->subSize_;
    }
    d->subSize_ = top->subSize_;
    top->subSize_ -= (1 + tempSize);  
    top->right_ = d->left_; // C becomes right child of b
    d->left_ = top;         // b becomes  left child of d
    top = d;                // top is now d
}

template <typename T>
void TreeSet<T>::insertNodeAtRoot(Node*& here, const T& value) 
{
    if (here == nullptr) {
        here = new Node{value, nullptr, nullptr, 1};
    }
    else if (value < here->data_) {
        insertNodeAtRoot(here->left_, value);
        rightRotate(here);
    }
    else {
        insertNodeAtRoot(here->right_, value);
        leftRotate(here);
    } 
}

template <typename T>
bool TreeSet<T>::exists(const T& value) const 
{
    Node* tempNode = root_;
    return existHelper(value, tempNode);
}

template <typename T>
bool TreeSet<T>::existHelper(const T& value, Node*& node) const {
    if (node == nullptr){
       return false;
   }
    else if (value < node->data_) {
       return existHelper(value,node->left_);
   }
    else if (node->data_ < value) {
       return existHelper(value, node->right_);
   }
    else {
       return true;
   }
}

template <typename T>
void TreeSet<T>::showStatistics(std::ostream& out) const 
{
    size_t nodes = std::pow(2, (height() + 1)) + 1; //perfect tree
    out << "size of tree: " << size() << ", height of tree: "
        << height() << ", a perfect BST with this height would have " 
        << nodes << " nodes" << ", so we are " <<std::abs((log(257)-2) - height()) 
        << "off from perfect height.";
    
}

template <typename T>
std::ostream& TreeSet<T>::print(std::ostream& tree) const 
{
    return print(tree,root_);
}

template <typename T>
std::ostream& TreeSet<T>::print(std::ostream& tree, Node* input) const 
{
    if (input == nullptr){
        tree << "-" << std::endl;
    }
    else {
        tree << "(";
        print(tree, input->left_);
        tree << ",";
        tree << input->data_;
        print(tree,input->right_);
        tree << ")";
    }
    return tree;
}

template <typename T>
int TreeSet<T>::height() const
{
    return heightHelper(root_);
}

template <typename T>
bool TreeSet<T>::Node::operator==(Node& rhs) const 
{
    return (rhs.data_ == data_);
}

template <typename T>
bool TreeSet<T>::Node::operator<( Node& rhs) const
{
    return (data_ < rhs.data_);
     
}
