# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = dog.o person.o
OUT = a.out

# Compile components:
CXX = g++
FLAGS = -W -Wall -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

# Now compile it all:
all: $(OBJECTS)
				$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT) 


dog.o: dog.h dog.cpp

				$(COMPILE_ONLY) dog.cpp 


person.o: person.h person.cpp

				$(COMPILE_ONLY) person.cpp 


# ... or clean it up:

clean:

				rm -rf *.out *.o *~ $(OUT) docs 


# ... or generate documentation (you must have a doxygen

# configuration file in the current directory):

docs:

				doxygen Doxyfile 
