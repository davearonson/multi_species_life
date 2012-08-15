//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Cell; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\cell.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <assert.h>
#include <stdlib.h>
#include <typeinfo.h>
#include "Life.h"
#include "World.h"
#include "Lffctory.h"
//## end module.includes

// Cell
#include "Cell.h"
// World
#include "World.h"
// Life
#include "Life.h"

//## begin module.additionalDeclarations preserve=yes
// difference in x in a given direction, on phone-type numberpad
#define dx(d) ((d-1)/3-1)
// difference in y in a given direction, on phone-type numberpad
#define dy(d) ((d-1)%3-1)
//## end module.additionalDeclarations


// Class Cell 





Cell::~Cell()
{
  //## begin Cell::~Cell%.body preserve=yes
  if (life != NULL) delete life;
  //## end Cell::~Cell%.body
}



//## Other Operations (implementation)
unsigned int Cell::CountNeighbors(Life *l)
{
  //## begin Cell::CountNeighbors%1031951764.body preserve=yes
  unsigned int count = 0;
  unsigned int dir;
  for (dir = 1; dir <= 9; dir++)
  {
    Life *  l2;

    if (dir == 5) continue;
    l2 = GetNeighborLife (dir);
    if (l2 == NULL) continue;
    if (! l2->IsAlive()) continue;
    if (typeid (*l2) == typeid (*l)) count++;
  }
  return count;
  //## end Cell::CountNeighbors%1031951764.body
}

char Cell::GetChar()
{
  //## begin Cell::GetChar%1032048076.body preserve=yes
  return (life == NULL) ? ' ' : life->GetChar();
  //## end Cell::GetChar%1032048076.body
}

Cell * Cell::GetNeighborCell(unsigned int dir)
{
  //## begin Cell::GetNeighborCell%1032274217.body preserve=yes
  return world->GetCellAt (x + dx (dir), y + dy (dir));
  //## end Cell::GetNeighborCell%1032274217.body
}

void Cell::MoveLife(int dir)
{
  //## begin Cell::MoveLife%1032394969.body preserve=yes
  Cell * c = GetNeighborCell (dir);
  assert (c != NULL);
  assert (c->life == NULL);
  c->life = life;
  life = NULL; 
  //## end Cell::MoveLife%1032394969.body
}

Life * Cell::GetNeighborLife(unsigned int dir)
{
  //## begin Cell::GetNeighborLife%1032274218.body preserve=yes
  Cell * c = GetNeighborCell (dir);
  if (c == NULL) return NULL;
  else return c->life;
  //## end Cell::GetNeighborLife%1032274218.body
}

void Cell::TakeTurn()
{
  //## begin Cell::TakeTurn%1031951763.body preserve=yes
  if (life == NULL) TryToGenerate();
  else
  {
    if (life->IsAlive()) life->TakeTurn();
    if (! life->IsAlive())
    {
      delete life;
      life = NULL;
    }
  }
  //## end Cell::TakeTurn%1031951763.body
}

void Cell::TryToGenerate()
{
  //## begin Cell::TryToGenerate%1032105034.body preserve=yes
  unsigned int dir;
  for (dir = 1; dir <= 9; dir++)
  {
    Life *  l;

    if (dir == 5) continue;
    l = GetNeighborLife (dir);
    if (l == NULL) continue;
    if (random (3) == 0) life = l->TryToGenerate (this);
    if (life != NULL) break;
  }
  //## end Cell::TryToGenerate%1032105034.body
}


// Additional Declarations
//## begin Cell.declarations preserve=yes

Cell::Cell (World * w, unsigned int myX, unsigned int myY, char * lifes, int odds)
{
  world = w;
  x = myX;
  y = myY;
  life = (random (odds) == 0) ? LifeFactory::MakeRandomLife (this, lifes) : NULL;
}

//## end Cell.declarations




