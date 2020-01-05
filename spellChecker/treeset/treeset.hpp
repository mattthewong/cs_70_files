/**
 * \file hashset.hpp
 *
 * \author Pig and Heron
 *
 * \brief Provides TreeSet<T>, a randomized binary search tree
 */

#ifndef TREESET_HPP_INCLUDED
#define TREESET_HPP_INCLUDED 1

#include <cstddef>
#include <string>
#include <list>
#include <iostream>
#include <type_traits>
#include <random>

/**
 * \class TreeSet
 * \brief Templeted randomized binary search tree
 *    
 * \details This TreeSet implements randomization as means of 
 *  being balanced.
 *
 * \remarks randomization is generated from code from Noisy Transmission
 *   
 */

 // template declaration
template <typename T>
class TreeSet {

    struct Node;

public:

    /**
     * \brief Constructor for empty tree, height of -1
     *
     */
    TreeSet();

    /**
     * \brief Destructor for tree set
     */
    ~TreeSet();

    /**
     * \brief Returns number of nodes in treeset
     */
    size_t size() const;

    /**
     * \brief Inserts element into treeset
     *
     * \param value     Element to insert
     * 
     * \note randomization is taken care of within this function
     */
    void insert(const T& value);
    
    /**
     * \brief helper function for insert
     *
     * \param value     Element to insert
     * \param here      Node to insert into tree
     * 
     */
    void insertHelper(Node*& here, const T& value);

    /**
     * \brief Checks for presence of element
     *
     * \param value     Element to check
     */
    bool exists(const T& value) const;


    bool existHelper(const T& value, Node*& node) const;
    /**
     * \brief rotates top right.
     *
     * \param top   node we are rotating
     * \note we took this from the notes
     */
    void rightRotate(Node*& top);

    /**
     * \brief rotates top left.
     *
     * \param top   node we are rotating
     * \note we took this from the notes
     */
    void leftRotate(Node*& top);

    /**
     * \brief inserts the value at the root of the tree.
     *
     * \note we took this from the notes
     */
    void insertNodeAtRoot(Node*& here, const T& value);

    /**
     * \brief Prints statistics regarding the set
     *
     */
    void showStatistics(std::ostream& out) const;

    /**
     * \brief Prints the treeset
     *
     */
    std::ostream& print(std::ostream& tree) const;

    /**
     * \brief Prints the treeset
     *
     */
    std::ostream& print(std::ostream& tree, Node* input) const;

    /**
     * \brief Returns height of tree
     *
     */
    int height() const;

    /**
     * \brief helper function to recursively determine height
     *
     */
    int heightHelper(Node* node) const;
    
private:

    size_t size_; ///< number of nodes in treeset

    struct Node {

        T data_; ///< data stored in node
        Node* left_; ///< pointer to left child node
        Node* right_; ///< pointer to right child node
        size_t subSize_; ///< size of subtree from node

        bool operator==(Node& rhs) const;
        bool operator<(Node& rhs) const;
        ~Node();
    };

    /**
     * \brief Returns rando float number for random insertion
     * \note we took this from NoisyTransmission assingnent #codecredz
     */
    float getRandomFloat();
    void seed();
    std::uniform_real_distribution<> dis_;
    std::mt19937 gen_;

    mutable Node* root_; ///< root of treeset
};

#include "treeset-private.hpp"
#endif
