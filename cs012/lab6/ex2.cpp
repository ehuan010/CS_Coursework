#include "instinct.h"
#include "jsquare.h"
#include<iostream>

using namespace std;

void order_test1(){
	cout<<"** TEST 1 - Start **"<<endl;
	cout<<"calling JSquare(Point) constructor..."<<endl;
	//Create a static (do not use new) JSquare object at point (1,8)
	JSquare square(Point(1,8));
  //Display Message of the area of the JSquare
  Message m1 = Message(Point(0.5,7.2), square.area());
  win << m1;
	//Draw the JSquare using its plot() function
	square.plot();
	win.output_buffer();
	cout<<"** TEST 1 - End **"<<endl;
}

void order_test2(){
	cout<<"** TEST 2 - Start **"<<endl;
	cout<<"calling JRectangle(Point) constructor..."<<endl;
	//Create a static (do not use new) JRectangle object at point (2,2)
  JRectangle rect(Point(2,2));
  //Display Message of the area of the JRectangle
  Message m1 = Message(Point(1.5,1.2), rect.area());
  win << m1;
	//Draw the JRectamgle using its plot() function
  rect.plot();
	win.output_buffer();
	cout<<"** TEST 2 - End **"<<endl;
}

void order_test3(){
	cout<<"** TEST 3 - Start **"<<endl;
	cout<<"calling JSquare(Point,double,Color) constructor..."<<endl;
	//Create a dynamic JSquare object at point (7,8)
	JSquare *square = new JSquare(Point(7,8), 2.0, RED);
  //Display Message of the area of the JSquare
  Message m1 = Message(Point(6,6.7), square->area());
  win << m1;
	//Draw the JSquare using its plot() function
	square->plot();
	win.output_buffer();
	cout<<"** TEST 3 - End **"<<endl;
}

void order_test4(){
	cout<<"** TEST 4 - Start **"<<endl;
	cout<<"calling JRect(Point, Color) constructor..."<<endl;
	//Create a dynamic JRectangle object at point (2,6)
  JRectangle *rect = new JRectangle(Point(2,6), BLUE);
  //Display Message of the area of the JRectangle
  Message m1 = Message(Point(1.5,5.2), rect->area());
  win << m1;
	//Draw the JRectangle using its plot() function
  rect->plot();
	win.output_buffer();
	cout<<"** TEST 4 - End **"<<endl;
}

void order_test5(){
	cout<<"** TEST 5 - Start **"<<endl;
	cout<<"calling JSquare(Point,double,Color) constructor..."<<endl;
  //Create a vector of pointers to JSquares
  vector<JSquare*>vs;
	//Create a dynamic JSquare object at point (7,6) amd (7.5)
	JSquare *square1 = new JSquare(Point(7,6), 0.5, RED);
  JSquare *square2 = new JSquare(Point(7,5), 0.5, RED);
  vs.push_back(square1);
  vs.push_back(square2);
  //Display Message of the area of the JSquare
  Message m1 = Message(Point(6,5.7), square1->area());
  Message m2 = Message(Point(6,4.7), square2->area());
  win << m1 << m2;
	//Draw the JSquare using its plot() function
  for(unsigned int i = 0; i < vs.size(); ++i)
  {
    vs[i]->plot();
  }
	win.output_buffer();
	cout<<"** TEST 5 - End **"<<endl;
}

void order_test6(){
	cout<<"** TEST 6 - Start **"<<endl;
	cout<<"calling JRectangle(Point,double,double Color) constructor..."<<endl;
  //Create a vector of pointers to JRectangle
  vector<JRectangle*>vs;
	//Create a dynamic JRectangle object at point (7,4) and (7,3)
	JRectangle *rect1 = new JRectangle(Point(7,4), 0.25, 0.5, GREEN);
  JRectangle *rect2 = new JRectangle(Point(7,3), 0.25, 0.5, GREEN);
  vs.push_back(rect1);
  vs.push_back(rect2);
  //Display Message of the area of the JRectangle
  Message m1 = Message(Point(6,3.6), rect1->area());
  Message m2 = Message(Point(6,2.6), rect2->area());
  win << m1 << m2;
	//Draw the JRectangle using its plot() function
  for(unsigned int i = 0; i < vs.size(); ++i)
  {
    vs[i]->plot();
  }
	win.output_buffer();
	cout<<"** TEST 5 - End **"<<endl;
}

int instinct_main(){
	//Ex1: Testing order of constructor/destructor calls;
	//1. On JSquare
	order_test1();
  //2. On JRectangle
  order_test2();
  //3. On JSquare Pointer
  order_test3();
  //4. On JRectangle Pointer
  order_test4();
  //5. On vector of JSquare Pointer
  order_test5();
  //6. On vector of JRectangle Pointer
  order_test6();
		//check terminal to observe output.
	
	return 0;

}


