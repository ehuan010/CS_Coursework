# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = date.o
OUT = a.out

# Compile components:
CXX = g++
FLAGS = -W -Wall -Werror -pedantic -ansi
DBGFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)


# The basic compile command:
COMPILE = $(CXX) $(DBGFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)


# Now compile it all:
all: $(OBJECTS)
	$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT) 

date.o: date.h date.cpp
	$(COMPILE_ONLY) date.cpp 

# ... or clean it up:
clean:
	rm -rf *.out *.o *~ $(OUT) docs 

# ... or generate documentation (you must have a doxygen
# configuration file in the current directory):
docs:
	doxygen Doxyfile
