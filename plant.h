//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Plant; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\plant.h


#ifndef Plant_h
#define Plant_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// Life
#include "Life.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: Plant
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class Plant : public Life  //## Inherits: <unnamed>

{
  //## begin Plant.initialDeclarations preserve=yes
  //## end Plant.initialDeclarations

  public:
    //## Destructor (generated)
      ~Plant();


    //## Other Operations (specified)
      //## Operation: GetChar%1032105038
      char GetChar();

    // Additional Public Declarations
      //## begin Plant.public preserve=yes
      Plant (Cell * c);
      //## end Plant.public


  protected:
    // Additional Protected Declarations
      //## begin Plant.protected preserve=yes
      //## end Plant.protected


  private:
    // Additional Private Declarations
      //## begin Plant.private preserve=yes
      //## end Plant.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Plant.implementation preserve=yes
      //## end Plant.implementation

};

// Class Plant 





#endif


