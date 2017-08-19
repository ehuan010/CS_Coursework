all: exercise1 exercise2

exercise1: exercise1.o
	g++ -ggdb exercise1.o -o exercise1
	
exercise2: exercise2.o
	g++ - ggdb exercise2.o -o exercise2
	
exercise1.o: exercise1.cpp
	g++ -ggdb -c exercise1.cpp
	
exercise2.o: exercise2.cpp
	g++ -ggdb -c exercise2.cpp
	
clean:
	rm -f exercise1.o exercise2.o exercise1 exercise2
