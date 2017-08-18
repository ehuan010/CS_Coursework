# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = user.o message.o bboard.o
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


user.o: user.h user.cpp

				$(COMPILE_ONLY) user.cpp 


message.o: message.h message.cpp

				$(COMPILE_ONLY) message.cpp 


bboard.o: bboard.h bboard.cpp user.h message.h

				$(COMPILE_ONLY) bboard.cpp 




# ... or clean it up:

clean:

				rm -rf *.out *.o *~ $(OUT) docs 


# ... or generate documentation (you must have a doxygen

# configuration file in the current directory):

docs:

				doxygen Doxyfile 
