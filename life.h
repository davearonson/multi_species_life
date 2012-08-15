//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Life; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\life.h


#ifndef Life_h
#define Life_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <cstring.h>
//## end module.includes


class Cell;

//## begin module.additionalDeclarations preserve=yes
class Cell;
//## end module.additionalDeclarations


//## Class: Life
//	Should come up with a better way of locating, than
//	marking each w/ x and y, when that data is implied by
//	its location in the world's matrix anyway....  B-(
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class Life 
{
  //## begin Life.initialDeclarations preserve=yes
  //## end Life.initialDeclarations

  public:
    //## Destructor (generated)
      ~Life();


    //## Other Operations (specified)
      //## Operation: GetChar%1032048077
      virtual char GetChar();

      //## Operation: IsAlive%1032011637
      unsigned int IsAlive();

      //## Operation: Sex%1032193486
      //	see sex attribute
      int Sex();

      //## Operation: TakeTurn%1030739233
      virtual void TakeTurn();

      //## Operation: TryToGenerate%1032193487
      //	Try to have this life-form create a new one.  Generally
      //	called by the Cell it is in, due to that Cell being
      //	empty and trying to fill it.  Returns pointer to new
      //	Life, if any, else NULL.
      Life * TryToGenerate(Cell *c);

    // Additional Public Declarations
      //## begin Life.public preserve=yes
      Life (Cell * c);
      //## end Life.public


  protected:
    // Data Members for Class Attributes

      //## Attribute: alive
      //## begin Life::alive.attr preserve=no  protected: unsigned int {U} 1
      unsigned int alive;
      //## end Life::alive.attr

      //## Attribute: sex
      //	0 == n/a, 1 == male, 2 = female, 3 = hermaphrodite
      //## begin Life::sex.attr preserve=no  protected: int {V} 
      int sex;
      //## end Life::sex.attr

      //## Attribute: FEMALE
      //## begin Life::FEMALE.attr preserve=no  protected: static const int {V} 0
      static const int FEMALE;
      //## end Life::FEMALE.attr

      //## Attribute: MALE
      //## begin Life::MALE.attr preserve=no  protected: static const int {V} 1
      static const int MALE;
      //## end Life::MALE.attr

    // Data Members for Associations

      //## Association: <unnamed>%3D835E0002A8
      //## Role: Life::cell
      //## begin Life::cell.role preserve=no  protected: Cell {0..1 -> 1RFHGN}
      Cell *cell;
      //## end Life::cell.role

    // Additional Protected Declarations
      //## begin Life.protected preserve=yes
      //## end Life.protected


  private:
    // Additional Private Declarations
      //## begin Life.private preserve=yes
      //## end Life.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Life.implementation preserve=yes
      //## end Life.implementation

};

// Class Life 





#endif


