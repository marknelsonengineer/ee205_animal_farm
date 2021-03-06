///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Demonstrates the use of a DoublyLinkedList
///
/// Orchestrates the entire program:
///    Starting Animal Farm 2
/// ...and end by printing
///    Done with Animal Farm 2
///
/// @file main_doublyLinkedList.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>

#include "config.h"
#include "Animal/AnimalFactory.h"
#include "Container/DoublyLinkedList.h"

using namespace std ;


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   DoublyLinkedList catDB ;

   Animal& newAnimal { AnimalFactory::newRandomAnimal() };

   newAnimal.dump();
   cout << "========" << endl;

   // Put 16 Animals in the list
   for( int i = 0 ; i < 8 ; i++ ) {
      catDB.addFront( &AnimalFactory::newRandomAnimal());
      catDB.addBack( &AnimalFactory::newRandomAnimal());
   }

   for( Animal* pAnimal = (Animal*) catDB.getFirst() ; pAnimal != nullptr ; pAnimal = (Animal*) List::getNext(
           (Node*) pAnimal ) ) {
      cout << pAnimal->speak() << endl;
   }
   cout << "========" << endl;

   catDB.validate() ;
   catDB.dump() ;
   catDB.removeAll() ;
   catDB.dump() ;

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
