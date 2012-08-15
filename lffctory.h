//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: LifeFactory; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\lffctory.h


#ifndef LfFctory_h
#define LfFctory_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
class Cell;
class Life;
//## end module.additionalDeclarations


//## Class: LifeFactory
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: 0


class LifeFactory 
{
  //## begin LifeFactory.initialDeclarations preserve=yes
  //## end LifeFactory.initialDeclarations

  public:
    //## Destructor (generated)
      ~LifeFactory();


    //## Other Operations (specified)
      //## Operation: MakeRandomLife%1032105035
      static Life * MakeRandomLife(Cell *c, char *lifes);

      //## Operation: MakeSpecificLife%1032105036
      static Life * MakeSpecificLife(Cell *c, Life *l);

    // Additional Public Declarations
      //## begin LifeFactory.public preserve=yes
      //## end LifeFactory.public


  protected:
    // Additional Protected Declarations
      //## begin LifeFactory.protected preserve=yes
      //## end LifeFactory.protected


  private:
    // Additional Private Declarations
      //## begin LifeFactory.private preserve=yes
      //## end LifeFactory.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin LifeFactory.implementation preserve=yes
      //## end LifeFactory.implementation

};

// Class LifeFactory 





#endif


