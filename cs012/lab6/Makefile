#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -Wall -Werror -ansi -pedantic

#Include
INCLUDE=-I/usr/local/include -I/usr/csshare/include -I/usr/csshare/pkgs/instinct_graphics/include -I/usr/csshare/freetype2

#Library locations
LIBDIRS=-L/usr/lib -L/usr/local/lib -L/usr/csshare/lib -L/usr/csshare/pkgs/instinct_graphics/lib

#Libraries
LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -linstinct -lSDL_mixer

#Main program
EXERCISES=ex0 ex1 ex2 ex3

#Object files
OBJECTS=jshape.o toolbar.o jrectangle.o jsquare.o jstar.o 

all: $(OBJECTS) $(EXERCISES)
ex1: jshape.o jrectangle.o  ex1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) ex1.cpp -o ex1  jshape.o jrectangle.o 
ex2: $(OBJECTS) ex2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) ex2.cpp -o ex2  $(OBJECTS)
ex3: $(OBJECTS) ex3.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) ex3.cpp -o ex3  $(OBJECTS)
ex4: $(OBJECTS) ex4.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) ex4.cpp -o ex4  $(OBJECTS)
jsquare.o: jrectangle.o jsquare.cpp jsquare.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jsquare.o -c jsquare.cpp 
jrectangle.o: jshape.o jrectangle.cpp jrectangle.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jrectangle.o -c jrectangle.cpp 
jshape.o: jshape.h jshape.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jshape.o -c jshape.cpp 
jstar.o: jstar.h jstar.cpp jshape.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jstar.o -c jstar.cpp 
toolbar.o: toolbar.h toolbar.cpp jshape.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c toolbar.cpp

clean:
	rm -rf *.o ex1 ex2 ex3 ex4 *~ *#
