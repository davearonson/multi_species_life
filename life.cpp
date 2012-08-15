//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Life; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\life.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <stdlib.h>
#include "LfFctory.h"
//## end module.includes

// Cell
#include "Cell.h"
// Life
#include "Life.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class Life 



//## begin Life::FEMALE.attr preserve=no  protected: static const int {V} 0
const int Life::FEMALE = 0;
//## end Life::FEMALE.attr

//## begin Life::MALE.attr preserve=no  protected: static const int {V} 1
const int Life::MALE = 1;
//## end Life::MALE.attr


Life::~Life()
{
  //## begin Life::~Life%.body preserve=yes
  // no subparts that need explicit deletion
  //## end Life::~Life%.body
}



//## Other Operations (implementation)
char Life::GetChar()
{
  //## begin Life::GetChar%1032048077.body preserve=yes
  if (! alive) return ' ';
  else if (sex == MALE) return 'X';
  else return 'x';
  //## end Life::GetChar%1032048077.body
}

unsigned int Life::IsAlive()
{
  //## begin Life::IsAlive%1032011637.body preserve=yes
  return alive;
  //## end Life::IsAlive%1032011637.body
}

int Life::Sex()
{
  //## begin Life::Sex%1032193486.body preserve=yes
  return sex;
  //## end Life::Sex%1032193486.body
}

void Life::TakeTurn()
{
  //## begin Life::TakeTurn%1030739233.body preserve=yes
  if (alive)
  {
    unsigned int n;
    n = cell->CountNeighbors(this);
    if (n < 3 || n > 5) alive = 0;
  }
  //## end Life::TakeTurn%1030739233.body
}

Life * Life::TryToGenerate(Cell *c)
{
  //## begin Life::TryToGenerate%1032193487.body preserve=yes
    unsigned int  dir;

    if (sex == FEMALE)
    {
      for (dir = 1; dir <= 9; dir++)
      {
        Life * l;

        if (dir == 5) continue;
        l = cell->GetNeighborLife (dir);
        if (l == NULL) continue;
        if (typeid (*l) != typeid (*this)) continue;
        if (l->Sex() == MALE)
        {
          l = LifeFactory::MakeSpecificLife (c, this);
          return l;
        }
      }
    }
    return NULL;
  //## end Life::TryToGenerate%1032193487.body
}


// Additional Declarations
//## begin Life.declarations preserve=yes
Life::Life (Cell * c)
{
  alive = 1;
  cell = c;
  sex = random (2);
}

//## end Life.declarations




