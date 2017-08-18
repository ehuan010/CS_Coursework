#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -Wall

#Include
INCLUDE=

#Library locations
LIBDIRS=

#Libraries
LIBS=

#Main program
EXERCISES=test.out gen.out

#Object files
OBJECTS=sorting.o utils.o

all: $(OBJECTS) $(EXERCISES)

test.out:  $(OBJECTS) test.cpp
	$(CXX) $(CXXFLAGS) -o test.out test.cpp $(OBJECTS)

gen.out:  $(OBJECTS) generate_tests.cpp
	$(CXX) $(CXXFLAGS) -o gen.out generate_tests.cpp $(OBJECTS)

sorting.o: sorting.h sorting.cpp
	$(CXX) $(CXXFLAGS) -c sorting.cpp

utils.o: utils.h utils.cpp
	$(CXX) $(CXXFLAGS) -c utils.cpp

clean:
	rm -rf *.o $(EXERCISES) *~ .*.swp .nfs*
