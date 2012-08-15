//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: World; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\world.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <assert.h>
#include <cstring.h>
#include "Cell.h"
//## end module.includes

// Cell
#include "Cell.h"
// World
#include "World.h"

//## begin module.additionalDeclarations preserve=yes
#define CalcOff(x,y) (y*maxX+x)
//## end module.additionalDeclarations


// Class World 







World::~World()
{
  //## begin World::~World%.body preserve=yes
  int i = maxX * maxY;
  while (i--) delete (*cells)[i];
  delete cells;
  //## end World::~World%.body
}



//## Other Operations (implementation)
Cell * World::GetCellAt(int x, int y)
{
  //## begin World::GetCellAt%1030999900.body preserve=yes
  // must cast maxx & maxy to int for comparison purposes!
  // otherwise, comparison is done as unsigned int.
  // this means that if x or y is negative, it will be seen as huge!
  if (x >= (int) maxX)
  {
    if (wrapX) x -= maxX;
    else return NULL;
  }
  else if (x < 0)
  {
    if (wrapX) x += maxX;
    else return NULL;
  }
  if (y >= (int) maxY)
  {
    if (wrapY) y -= maxY;
    else return NULL;
  }
  else if (y < 0)
  {
    if (wrapY) y = y + maxY;
    else return NULL;
  }
  return (*cells)[CalcOff(x,y)];
  //## end World::GetCellAt%1030999900.body
}

void World::Show()
{
  //## begin World::Show%1031325417.body preserve=yes
  cout << "\033[H";
  unsigned int x, y;

  for (y = 0; y < maxY; y++)
  {
    for (x = 0; x < maxX; x++) cout << GetCellAt(x,y)->GetChar();
    cout << endl;
  }
  cout << "Age: " << age;
  // give the screen some time to catch up!
  sleep (1);
  //## end World::Show%1031325417.body
}

void World::Turn()
{
  //## begin World::Turn%1030739232.body preserve=yes
  unsigned int x, y;
  age++;
  for (y=0; y < maxY; y++) for (x=0; x < maxX; x++) GetCellAt(x,y)->TakeTurn();
  //## end World::Turn%1030739232.body
}


// Additional Declarations
//## begin World.declarations preserve=yes
World::World (unsigned int newMaxX, unsigned int newMaxY,
   					  unsigned int newWrapX, unsigned int newWrapY,
              char * lifes, int odds)
{
  unsigned int x, y;

  age = 0;
  maxX = newMaxX;
  maxY = newMaxY;
  wrapX = newWrapX;
  wrapY = newWrapY;
  cells = new TArray <Cell *> (maxX * maxY);
  for (y = 0; y < maxY; y++)
  {
    for (x = 0; x < maxX; x++)
    {
      (*cells)[CalcOff(x,y)] = new Cell (this, x, y, lifes, odds);
    }
  }
}

//## end World.declarations




