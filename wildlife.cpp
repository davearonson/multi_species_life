// includes, system
#include <except.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

// includes, project
#include "Cell.h"
#include "World.h"

// defines

// declarations, vars
char *   progName;
World *  theWorld;

// declarations, funcs
void  CleanUp (void);
int   GetBoolArg (char * arg, char * leader, int &var);
int   GetIntArg (char * arg, char * leader, int &var, int min, int max);
int   GetOptListArg (char * arg, char * leader, char c1, int &v1, char c2, int &v2);
int   GetStringArg (char * arg, char * leader, char ** ptr);
void  GiveUsage (void);
int   Init (int maxX, int maxY, int wrapX, int wrapY, char * lifes, int odds);
int   Run (void);
void  Terminate (void);

// funcs

int main (int argc, char * argv[])
{
  int     i;
  char *  lifes = "XPPAA";
  int     maxX = 10;
  int     maxY = 10;
  int     odds = 10;
  int     wrapX = 0;
  int     wrapY = 0;

  progName = argv[0];
  for (i = 1; i < argc; i++)
  {
    char * arg = argv[i];
    if (GetIntArg (arg, "-x", maxX, 1, INT_MAX)) continue;
    else if (GetIntArg (arg, "-y", maxY, 1, INT_MAX)) continue;
    else if (GetIntArg (arg, "-o", odds, 1, INT_MAX)) continue;
    else if (GetOptListArg (arg, "-w", 'x', wrapX, 'y', wrapY)) continue;
    else if (GetStringArg (arg, "-l", &lifes)) continue;
    else if (! strcmp (arg, "-h")) GiveUsage();
    else
    {
      cout << "ERROR: Unrecognized argument '" << arg << '\'' << endl << endl;
      GiveUsage();
    }
  }
  if (Init (maxX, maxY, wrapX, wrapY, lifes, odds))
  {
    while (Run());
    CleanUp();
  }
  return 0;
}


void CleanUp (void)
{
  delete theWorld;
}


int GetBoolArg (char * arg, char * leader, int &var)
{
  int len = strlen (leader);

  if (strncmp (arg, leader, len) != 0) return 0;
  arg += len;
  switch (*arg)
  {
    case 'y': case 'Y': case 't': case 'T': case '1': var = 1; break;
    case 'n': case 'N': case 'f': case 'F': case '0': var = 0; break;
    default:
      cout << "ERROR: " << leader << " must be y/Y/t/T/1/n/N/f/F/0!" << endl << endl;
      GiveUsage();
    break;
  }
  return 1;
}


int GetIntArg (char * arg, char * leader, int &var, int min, int max)
{
  int len = strlen (leader);

  if (strncmp (arg, leader, len) != 0) return 0;
  var = atoi (arg + len);
  if (var < min)
  {
    cout << "ERROR: " << leader << " must be at least " << min << '!' << endl << endl;
    GiveUsage ();
  }
  else if (var > max)
  {
    cout << "ERROR: " << leader << " must be at most " << max << '!' << endl << endl;
    GiveUsage ();
  }
  return 1;
}


// need to convert this to use varargs eventually
int GetOptListArg (char * arg, char * leader,
                   char c1, int &v1, char c2, int &v2)
{
  int     len = strlen (leader);
  char *  p;

  if (strncmp (arg, leader, len) != 0) return 0;
  for (p = arg + len; *p != '\0'; p++)
  {
    if (*p == c1) v1 = 1;
    else if (*p == c2) v2 = 1;
    else
    {
      cout << "Unknown option " << *p << " in argument " << arg << endl;
      GiveUsage();
    }
  }
  return 1;
}


int GetStringArg (char * arg, char * leader, char ** ptr)
{
  int     len = strlen (leader);

  if (strncmp (arg, leader, len) != 0) return 0;
  *ptr = arg + len;
  return 1;
}



void GiveUsage (void)
{
  cout << "Usage: " << progName << " [-o#] [-w{xy}] [-x#] [-y#]" << endl;
  cout << endl;
  cout << "-o: odds of life (# to 1 against); default 10" << endl;
  cout << "-w: wrap in X and/or Y direction; default neither" << endl;
  cout << "-x: number of columns (1-" << INT_MAX << ", default 10)" << endl;
  cout << "-y: number of rows (1-" << INT_MAX << ", default 10)" << endl;
  cout << endl;
  cout << "# denotes an integer, and {xy} denotes x, y, or both" << endl;
  exit (1);
}


int Init (int maxX, int maxY, int wrapX, int wrapY, char * lifes, int odds)
{
  set_terminate (Terminate);
  randomize();
  theWorld = new World (maxX, maxY, wrapX, wrapY, lifes, odds);
  cout << "\033[H\033[J";
  theWorld->Show();
  return 1;
}


int Run (void)
{
  theWorld->Turn();
  theWorld->Show();
  return 1;
}


void Terminate (void)
{
  cout << "Terminate has been called!" << endl;
  CleanUp();
}

