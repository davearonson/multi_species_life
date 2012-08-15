This is a combined demo of C++ and Rational Rose.  It is a variation on the
classic Life cellular automata program.  "Improvements" include using three
different species, with sexes.  Live cells must still have only 3, 4, or 5
neighbors to survive, but in order to generate a new lifeform, there must be a
female next to the blank space, with a male of the same species somewhere next
to her (not necessarily in the same direction).  Searches for both the female
and the male proceed as on a telephone number pad, as does the process of
"time" in general (i.e., which cells get to "go").

The files are as follows:

- wildlife.cpp, the main program

- world.cpp and world.h, the class that holds the primary parameters

- cell.h, the class that provides proximity services, generation of new life
forms in empty spaces, etc.

- life.h, the base class of all life forms

- animal.cpp and animal.h, the animal life forms (eventually to be split up
further, into herbivore and carnivore)

- plant.cpp and plant.h, the plant life forms (possibly eventually to be split
up further)

- lffctory.cpp and lffctory.h, the class that creates a new life form, either
randomly chosen or to duplicate an existing one

- wildlife.ide, the Borland project file

- wildlife.exe, the executable

- wildlife.mdl, the Rational Rose model
