//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Animal; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\animal.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "Cell.h"
//## end module.includes

// Animal
#include "Animal.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class Animal 


Animal::~Animal()
{
  //## begin Animal::~Animal%.body preserve=yes
  //## end Animal::~Animal%.body
}



//## Other Operations (implementation)
char Animal::GetChar()
{
  //## begin Animal::GetChar%1032105037.body preserve=yes
  if (! alive) return ' ';
  else if (sex == MALE) return 'A';
  else return 'a';
  //## end Animal::GetChar%1032105037.body
}

void Animal::TakeTurn()
{
  //## begin Animal::TakeTurn%1032394970.body preserve=yes
  int  n;

  if (! alive) return;
  if (loseTurn == 1)
  {
    loseTurn = 0;
    return;
  }
  n = cell->CountNeighbors (this);
  if (n < 3 || n > 5) alive = 0;  // too lonely/crowded to survive
  else if (n == 3 || n == 5) TryToMove();  // too lonely/crowded for comfort
  //## end Animal::TakeTurn%1032394970.body
}

void Animal::TryToMove()
{
  //## begin Animal::TryToMove%1032442620.body preserve=yes
  int dir = random (9) + 1;
  if (dir == 5) return;
  Cell * tmpCell = cell->GetNeighborCell (dir);
  if (tmpCell == NULL) return;
  if (cell->GetNeighborLife (dir) != NULL) return;
  cell->MoveLife (dir);
  cell = tmpCell;
  if (dir > 5) loseTurn = 1;
  //## end Animal::TryToMove%1032442620.body
}


// Additional Declarations
//## begin Animal.declarations preserve=yes
Animal::Animal (Cell * c)
  : Life (c)
{
  loseTurn = 0;
}
//## end Animal.declarations




