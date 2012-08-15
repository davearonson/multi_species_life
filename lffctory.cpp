//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: LifeFactory; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\lffctory.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <dos.h>
#include <iostream.h>
#include <typeinfo.h>
#include "Animal.h"
#include "Plant.h"
//## end module.includes

// LifeFactory
#include "LfFctory.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class LifeFactory 

LifeFactory::~LifeFactory()
{
  //## begin LifeFactory::~LifeFactory%.body preserve=yes
  //## end LifeFactory::~LifeFactory%.body
}



//## Other Operations (implementation)
Life * LifeFactory::MakeRandomLife(Cell *c, char *lifes)
{
  //## begin LifeFactory::MakeRandomLife%1032105035.body preserve=yes
  char    t = lifes[random(strlen(lifes))];
  Life *  l;
  switch (t)
  {
    case 'X':
    case 'x':
      l = new Life (c);
    break;
    case 'P':
    case 'p':
      l = new Plant (c);
    break;
    case 'a':
    case 'A':
      l = new Animal (c);
    break;
    default:
      cout << "ERROR: UNKNOWN LIFE FORM " << c << endl;
      sleep (1);
      exit (1);
      l = NULL;
    break;
  }
  return l;
  //## end LifeFactory::MakeRandomLife%1032105035.body
}

Life * LifeFactory::MakeSpecificLife(Cell *c, Life *l)
{
  //## begin LifeFactory::MakeSpecificLife%1032105036.body preserve=yes
  Life * l2 = NULL;
  // there must be some easier way to do this....
  if (typeid (*l) == typeid (Life)) l2 = new Life (c);
  else if (typeid (*l) == typeid (Plant)) l2 = new Plant (c);
  else if (typeid (*l) == typeid (Animal)) l2 = new Animal (c);
  else
  {
    cout << "ERROR: UNKNOWN LIFE FORM " << l->GetChar() << endl;
    sleep (1);
    exit (1);
  }
  return l2;
  //## end LifeFactory::MakeSpecificLife%1032105036.body
}


// Additional Declarations
//## begin LifeFactory.declarations preserve=yes
//## end LifeFactory.declarations




