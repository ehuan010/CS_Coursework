# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = message.o
OUT = a.out

# Compile components:
CXX = g++
FLAGS = -W -Wall -Werror -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

# Now compile it all:
all: $(OBJECTS)
				$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT) 


message.o: message.h message.cpp

				$(COMPILE_ONLY) message.cpp 


# ... or clean it up:

clean:

				rm -rf *.out *.o *~ $(OUT) docs 


# ... or generate documentation (you must have a doxygen

# configuration file in the current directory):

docs:

				doxygen Doxyfile 
