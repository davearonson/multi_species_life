//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Animal; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\animal.h


#ifndef Animal_h
#define Animal_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// Life
#include "Life.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: Animal
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class Animal : public Life  //## Inherits: <unnamed>

{
  //## begin Animal.initialDeclarations preserve=yes
  //## end Animal.initialDeclarations

  public:
    //## Destructor (generated)
      ~Animal();


    //## Other Operations (specified)
      //## Operation: GetChar%1032105037
      char GetChar();

      //## Operation: TakeTurn%1032394970
      void TakeTurn();

    // Additional Public Declarations
      //## begin Animal.public preserve=yes
      Animal (Cell * c);
      //## end Animal.public


  protected:

    //## Other Operations (specified)
      //## Operation: TryToMove%1032442620
      void TryToMove();

    // Data Members for Class Attributes

      //## Attribute: loseTurn
      //## begin Animal::loseTurn.attr preserve=no  protected: int {V} 0
      int loseTurn;
      //## end Animal::loseTurn.attr

    // Additional Protected Declarations
      //## begin Animal.protected preserve=yes
      //## end Animal.protected


  private:
    // Additional Private Declarations
      //## begin Animal.private preserve=yes
      //## end Animal.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Animal.implementation preserve=yes
      //## end Animal.implementation

};

// Class Animal 





#endif


