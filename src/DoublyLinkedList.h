///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic DoublyLinkedList collection class.
///
/// @file DoublyLinkedList.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// A generic DoublyLinkedList collection class.
///
class DoublyLinkedList {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* head = nullptr ;     ///< The head pointer for the list
   Node* tail = nullptr ;     ///< The tail pointer for the list
   unsigned int count = 0 ;   ///< Maintain a count of the number of Nodes in the list

public:  /////////////////////////// Public Methods ////////////////////////////
   bool empty() const noexcept ;         ///< `true` if the list is empty
   unsigned int size() const noexcept ;  ///< Return the number of Nodes in the list

   void  push_front( Node* newNode ) noexcept ; ///< Insert `newNode` to the beginning of the list
   void  push_back( Node* newNode ) noexcept ;  ///< Append `newNode` to the end of the list
   Node* pop_front() noexcept ;                 ///< Remove and return the first Node in the list
   Node* pop_back() noexcept ;                  ///< Remove and return the last Node in the list

   void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`
   void insert_before( Node* currentNode, Node* newNode ) ; ///< Insert `newNode` before `currentNode`

   bool isIn( Node* aNode ) const noexcept ; ///< `true` if `aNode` is in the list
   bool isSorted() const noexcept ;          ///< `true` if the list is sorted

   void swap( Node* node1, Node* node2 ) noexcept ;  ///< Swap `node1` and `node2`

   void insertionSort() noexcept ;  ///< Runs the insertion sort algorithm on the list

   Node* get_first() const noexcept ;  ///< Get the first Node in the list
   Node* get_last() const noexcept ;   ///< Get the last Node in the list
   static Node* get_next( const Node* currentNode ) noexcept ;  ///< Get the next Node in the list
   static Node* get_prev( const Node* currentNode ) noexcept ;  ///< Get the previous Node in the list

   void dump() const noexcept ;      ///< Output the contents of this container
   bool validate() const noexcept ;  ///< Check to see if the container is valid
} ;  // class DoubleLinkedList