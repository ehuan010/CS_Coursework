CXX=g++
CXXFLAGS=-g -W -Wall -Werror -pedantic -ansi 
INCLUDE=-I /usr/csshare/include
OBJECTS=rational.o

# compile the program
all: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

rational.o: rational.h rational.cpp
	$(CXX) $(CXXFLAGS) -o rational.o -c rational.cpp

# remove unnecessary files
clean:
	rm -rf *~ a.out *.o
