//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: World; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\world.h


#ifndef World_h
#define World_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <classlib\arrays.h> // needed for container to hold cells
#if 0
//## end module.includes


class Cell;

//## begin module.additionalDeclarations preserve=yes
#endif
class Cell;
//## end module.additionalDeclarations


//## Class: World
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: 1


class World 
{
  //## begin World.initialDeclarations preserve=yes
  //## end World.initialDeclarations

  public:
    //## Destructor (generated)
      ~World();


    //## Other Operations (specified)
      //## Operation: GetCellAt%1030999900
      //	ARGS ARE PURPOSELY SIGNED!  Could wrap around to other
      //	side of world.
      Cell * GetCellAt(int x, int y);

      //## Operation: Show%1031325417
      void Show();

      //## Operation: Turn%1030739232
      void Turn();

    // Additional Public Declarations
      //## begin World.public preserve=yes
  		World::World (unsigned int newMaxX, unsigned int newMaxY,
	      					  unsigned int newWrapX, unsigned int newWrapY,
                    char * lifes, int odds);
      //## end World.public


  protected:
    // Data Members for Class Attributes

      //## Attribute: age
      //## begin World::age.attr preserve=no  protected: unsigned int {V} 0
      unsigned int age;
      //## end World::age.attr

      //## Attribute: maxX
      //## begin World::maxX.attr preserve=no  protected: unsigned int {V} 10
      unsigned int maxX;
      //## end World::maxX.attr

      //## Attribute: maxY
      //## begin World::maxY.attr preserve=no  protected: unsigned int {V} 10
      unsigned int maxY;
      //## end World::maxY.attr

      //## Attribute: wrapX
      //## begin World::wrapX.attr preserve=no  protected: unsigned int {V} 0
      unsigned int wrapX;
      //## end World::wrapX.attr

      //## Attribute: wrapY
      //## begin World::wrapY.attr preserve=no  protected: unsigned int {V} 0
      unsigned int wrapY;
      //## end World::wrapY.attr

    // Data Members for Associations

      //## Association: <unnamed>%3D6FD3D801A4
      //## Role: World::cells
      //## begin World::cells.role preserve=no  protected: Cell {1 -> nRFHN}
      TArray<Cell *> *cells;
      //## end World::cells.role

    // Additional Protected Declarations
      //## begin World.protected preserve=yes
      //## end World.protected


  private:
    // Additional Private Declarations
      //## begin World.private preserve=yes
      //## end World.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin World.implementation preserve=yes
      //## end World.implementation

};

// Class World 





#endif


