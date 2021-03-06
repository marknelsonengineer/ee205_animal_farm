///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Where the Wild Things Are
///
/// @file Animal.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "../config.h"
#include "../Container/Node.h"
#include "../Utility/Gender.h"
#include "../Utility/Weight.h"


/// A class that encompasses all Animals on the farm.
///
/// This class should be the parent class of all of the Animals on the farm.
/// It contains 1 abstract method `speak()` that each Animal must implement
/// before it can be instantiated.
///
/// Animals understand things I don't know -- and they know languages which are not made of words.”
///
/// @see https://en.wikipedia.org/wiki/Animal
/// @see https://en.wikipedia.org/wiki/Taxonomy_(biology)
class Animal : public Node {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view KINGDOM_NAME { "Animalia" } ;  ///< The scientific name of the Animal Kingdom.

private:  ///////////////////// Member Variables //////////////////////////////
   std::string species;                     ///< The Animal's biological species
   std::string classification;              ///< The Animal's biological classification
   Gender gender = Gender::UNKNOWN_GENDER;  ///< The Animal's gender.  Scientifically, not all Animals have a gender, but all Animals on Animal Farm have a gender.
   Weight weight;                           ///< The weight of the Animal

public:   /////////////////////// Constructors ////////////////////////////////
   /// Create an Animal with the *minimum* required fields
   Animal( const Weight::t_weight newMaxWeight
          ,const std::string_view newClassification
          ,const std::string_view newSpecies
          );

   /// Create an Animal, populating *all* of the member variables
   Animal( const Gender           newGender
          ,const Weight::t_weight newWeight
          ,const Weight::t_weight newMaxWeight
          ,const std::string_view newClassification
          ,const std::string_view newSpecies
          );

public:   ///////////////////// Getters & Setters /////////////////////////////
   std::string_view getKingdom()        const noexcept;  ///< Get the kingdom, which is `Animalia`
   std::string_view getClassification() const noexcept;  ///< Get the classification
   std::string_view getSpecies()        const noexcept;  ///< Get the species

   Gender           getGender()         const noexcept;  ///< Get the Animal's Gender

   Weight::t_weight getWeight() const noexcept;  ///< Get the Animal's Weight
   void             setWeight( const Weight::t_weight newWeight );  ///< Set the Animal's Weight

protected:  ////////////////////// Protected Methods ///////////////////////////
   void setGender( const Gender newGender );   ///< Set the Animal's Gender

public:   ////////////////////////// Abstract Methods //////////////////////////
   virtual std::string_view speak() const noexcept = 0;    ///< Ask the Animal to say something.  This method is virtual and abstract.
   virtual std::string_view getName() const noexcept = 0;  ///< Get the Cat's name

public:   /////////////////////////// Public Methods ///////////////////////////
   std::string info() const noexcept;         ///< Return one-line of information about this Animal
   void dump()     const noexcept override;   ///< Output the contents of this object (and its parents).
   bool validate() const noexcept override;   ///< Check to see if the Animal object is valid

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Animal& rhs_animal ) const;  ///< Compare two Animals with `<`
   bool operator<=( const Animal& rhs_animal ) const;  ///< Compare two Animals with `<=`
   bool operator> ( const Animal& rhs_animal ) const;  ///< Compare two Animals with `>`
   bool operator>=( const Animal& rhs_animal ) const;  ///< Compare two Animals with `>=`

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
   bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison between two Nodes
   bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison between two Nodes
   bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison between two Nodes
};
