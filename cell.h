//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Cell; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\cell.h


#ifndef Cell_h
#define Cell_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <cstring.h>
#include <typeinfo.h>
#include <classlib\arrays.h>
//## end module.includes


class World;
class Life;

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: Cell
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class Cell 
{
  //## begin Cell.initialDeclarations preserve=yes
  //## end Cell.initialDeclarations

  public:
    //## Destructor (generated)
      ~Cell();


    //## Other Operations (specified)
      //## Operation: CountNeighbors%1031951764
      unsigned int CountNeighbors(Life *l);

      //## Operation: GetChar%1032048076
      char GetChar();

      //## Operation: GetNeighborCell%1032274217
      Cell * GetNeighborCell(unsigned int dir);

      //## Operation: MoveLife%1032394969
      void MoveLife(int dir);

      //## Operation: GetNeighborLife%1032274218
      Life * GetNeighborLife(unsigned int dir);

      //## Operation: TakeTurn%1031951763
      void TakeTurn();

    // Additional Public Declarations
      //## begin Cell.public preserve=yes
      Cell (World * w, unsigned int myX, unsigned int myY, char * lifes, int odds);
      //## end Cell.public


  protected:

    //## Other Operations (specified)
      //## Operation: TryToGenerate%1032105034
      void TryToGenerate();

    // Data Members for Class Attributes

      //## Attribute: x
      //## begin Cell::x.attr preserve=no  protected: unsigned int {V} 
      unsigned int x;
      //## end Cell::x.attr

      //## Attribute: y
      //## begin Cell::y.attr preserve=no  protected: unsigned int {V} 
      unsigned int y;
      //## end Cell::y.attr

    // Data Members for Associations

      //## Association: <unnamed>%3D6FD3D801A4
      //## Role: Cell::world
      //## begin Cell::world.role preserve=no  protected: World {n -> 1RFHGN}
      World *world;
      //## end Cell::world.role

      //## Association: <unnamed>%3D835E0002A8
      //## Role: Cell::life
      //## begin Cell::life.role preserve=no  protected: Life {1 -> 0..1RFHN}
      Life *life;
      //## end Cell::life.role

    // Additional Protected Declarations
      //## begin Cell.protected preserve=yes
      //## end Cell.protected


  private:
    // Additional Private Declarations
      //## begin Cell.private preserve=yes
      //## end Cell.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Cell.implementation preserve=yes
      //## end Cell.implementation

};

// Class Cell 





#endif


