#include "instinct.h"
#include "jrectangle.h"
#include<iostream>

using namespace std;

void order_test1(){
	cout<<"** TEST 1 - Start **"<<endl;
	cout<<"calling JRectangle(Point) constructor..."<<endl;
	//Create a static (do not use new) JRectangle object at point (5,5)
	JRectangle rect(Point(5,5));
	//Draw the JRectangle using its plot() function
	rect.plot();
	win.output_buffer();
	cout<<"** TEST 1 - End **"<<endl;
}

int instinct_main(){
	//Ex1: Testing order of constructor/destructor calls;
	//1. On JRectangle
	order_test1();
		//check terminal to observe output.
	
	return 0;

}


