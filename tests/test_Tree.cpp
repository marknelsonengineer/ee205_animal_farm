///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Tree class
///
/// @file test_Tree.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <cmath>                     // For pow()
#include <random>                    // For test_bulk_erase_from_Tree



#include "../src/Container/Tree.h"
#include "../src/Animal/Cat.h"

using namespace std;

/// All of the tests will use this one testTree, which must always remain valid.
static Tree testTree;

/// Delete all nodes before and after each of the test cases in this module.
struct TreeTestFixture {
   TreeTestFixture()   {
      testTree.deleteAllNodes();
      Cat::resetCatNames();
      BOOST_TEST_MESSAGE( "setup fixture" );
   }
   ~TreeTestFixture()  {
      testTree.deleteAllNodes();
      Cat::resetCatNames();
      BOOST_TEST_MESSAGE( "teardown fixture" );
   }
} ;


BOOST_AUTO_TEST_SUITE( test_Tree )

   BOOST_FIXTURE_TEST_CASE( test_empty_Tree, TreeTestFixture ) {
      BOOST_CHECK_EQUAL( testTree.empty(), true );
   	BOOST_CHECK_EQUAL( testTree.size(), 0 );
   	BOOST_CHECK_EQUAL( testTree.validate(), true );
   	// BOOST_CHECK_NO_THROW( testTree.dump());
   }


   BOOST_FIXTURE_TEST_CASE( test_insert_Tree, TreeTestFixture ) {
   	BOOST_CHECK_THROW( testTree.insert( nullptr ), invalid_argument );

   	for( int i = 0 ; i < 100 ; i++ ) {
   		Cat& aCat = Cat::generateCat();
   		BOOST_REQUIRE_NO_THROW( testTree.insert( &aCat ));
   		BOOST_REQUIRE_THROW( testTree.insert( &aCat ), logic_error );
   		BOOST_REQUIRE_EQUAL( testTree.empty(), false );
   		BOOST_REQUIRE_EQUAL( testTree.size(), i+1 );
   		BOOST_REQUIRE_EQUAL( testTree.isIn( &aCat ), true );
   		BOOST_REQUIRE_EQUAL( testTree.validate(), true );
   	}

   	// testTree.dump();
   }


   BOOST_FIXTURE_TEST_CASE( test_simple_erase_from_Tree, TreeTestFixture ) {
      Cat& aCat = Cat::generateCat();

      BOOST_CHECK_THROW( testTree.erase( nullptr ), invalid_argument );
      BOOST_CHECK_THROW( testTree.erase( &aCat ),
                         logic_error );  // Try to erase a cat that's not in the Tree

      // Insert and remove the root node 10 times
      for( int i = 0 ; i < 10 ; i++ ) {
         BOOST_REQUIRE_NO_THROW( testTree.insert( &aCat ));
         BOOST_REQUIRE_EQUAL( testTree.empty(), false );
         BOOST_REQUIRE_EQUAL( testTree.size(), 1 );
         BOOST_REQUIRE_EQUAL( testTree.isIn( &aCat ), true );
         BOOST_REQUIRE_EQUAL( testTree.validate(), true );

         BOOST_REQUIRE_NO_THROW( testTree.erase( &aCat ));
         BOOST_REQUIRE_EQUAL( testTree.empty(), true );
         BOOST_REQUIRE_EQUAL( testTree.size(), 0 );
         BOOST_REQUIRE_EQUAL( testTree.isIn( &aCat ), false );
         BOOST_REQUIRE_EQUAL( testTree.validate(), true );
      }
   }

   BOOST_FIXTURE_TEST_CASE( test_getRandomNode, TreeTestFixture ) {
      for( int j = 0 ; j < 10 ; j++ ) {
         testTree.insert( &Cat::generateCat() );
         Node* aNode = testTree.getRandomNode();
         // aNode->dump();
         BOOST_REQUIRE_EQUAL( testTree.isIn( aNode ), true );
      }
   }

   BOOST_FIXTURE_TEST_CASE( test_bulk_operations_on_Tree, TreeTestFixture ) {
      int count = 0;

      for( int i = 0 ; i < 7 ; i++ ) {
         BOOST_REQUIRE_NO_THROW( testTree.deleteAllNodes() );
         count = 0;

         double idealSizeOfList = pow( 2, i );

         BOOST_TEST_MESSAGE( "ideal size of list = [" << idealSizeOfList << "]   remaining cat names = [" << Cat::remaningCatNames() << "]" ) ;

         for( int j = 0 ; j < 1000 ; j++ ) {
            bernoulli_distribution isFixedRNG( testTree.size() / (idealSizeOfList*2) );  // If ideal size is 4, then 4/8 = 0.5
            bool deleteNode = isFixedRNG( ANIMAL_FARM_RNG );

            if( deleteNode ) {
               Node* nodeToDelete = testTree.getRandomNode();
               BOOST_REQUIRE_NO_THROW( testTree.erase( nodeToDelete ) );
               count -= 1;
               BOOST_REQUIRE_EQUAL( testTree.isIn( nodeToDelete ), false );

            } else { // Insert a Node
               Cat& aCat = Cat::generateCat();
               BOOST_REQUIRE_NO_THROW( testTree.insert( &aCat ) );
               count += 1;
               BOOST_REQUIRE_EQUAL( testTree.isIn( &aCat ), true );

            }
            BOOST_REQUIRE_EQUAL( testTree.size(), count );
            BOOST_REQUIRE_EQUAL( testTree.validate(), true );
         }
      }
      BOOST_REQUIRE_NO_THROW( testTree.deleteAllNodes() );
      count = 0;
   }

BOOST_AUTO_TEST_SUITE_END()
