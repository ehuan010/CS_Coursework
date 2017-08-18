#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -Wall

#Include
INCLUDE=-I/usr/local/include -I/usr/csshare/include -I/usr/csshare/pkgs/instinct_graphics/include -I/usr/csshare/freetype2

#Library locations
LIBDIRS=-L/usr/lib -L/usr/local/lib -L/usr/csshare/lib -L/usr/csshare/pkgs/instinct_graphics/lib

#Libraries
LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -linstinct -lSDL_mixer

#Main program
EXERCISES=test.out compare.out

#Object files
OBJECTS=sorting.o utils.o

all: $(OBJECTS) $(EXERCISES)

test.out:  $(OBJECTS) test.cpp
	$(CXX) $(CXXFLAGS) -o test.out test.cpp $(OBJECTS)

compare.out:  $(OBJECTS)  compare.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o compare.out compare.cpp $(OBJECTS)

sorting.o: sorting.h sorting.cpp
	$(CXX) $(CXXFLAGS) -c sorting.cpp

utils.o: utils.h utils.cpp
	$(CXX) $(CXXFLAGS) -c utils.cpp

clean:
	rm -rf *.o $(EXERCISES) *~ .*.swp .nfs* lab9_framework.tgz
