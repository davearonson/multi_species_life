//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Plant; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: d:\dja\computer\src\rose\wildlife\plant.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// Plant
#include "Plant.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class Plant 

Plant::~Plant()
{
  //## begin Plant::~Plant%.body preserve=yes
  //## end Plant::~Plant%.body
}



//## Other Operations (implementation)
char Plant::GetChar()
{
  //## begin Plant::GetChar%1032105038.body preserve=yes
  if (! alive) return ' ';
  else if (sex == MALE) return 'P';
  else return 'p';
  //## end Plant::GetChar%1032105038.body
}


// Additional Declarations
//## begin Plant.declarations preserve=yes
Plant::Plant (Cell * c)
  : Life (c)
{
}
//## end Plant.declarations




