#include "instinct.h"
#include "sorting.h"
#include "utils.h" 

#define LS (LETTER_HEIGHT*1.5)
using namespace std;
typedef void(*SortFunc)(vector<int>&);

// A struct that stores algorithm info
struct SortingMethod{
	SortingMethod() :name(""), func(NULL){ }
	SortingMethod(string name, SortFunc f) 
		:name(name), func(f){ }

	string name;
	SortFunc func;
};

float draw_sort_timing(int x, double y, SortingMethod& m,vector<int>& v);
void draw_graph(vector<SortingMethod> methods,vector<int>& n, vector< vector<float> >& times);

//tests the sorting method at address sort_func on vector v (v is unchanged, this is only for timing purposes). 
float test_sorting_time(SortFunc sort_func, vector<int> v){
	clock_t start = clock();
	(*sort_func)(v);
	clock_t end = clock();
	return static_cast<float>(end - start) / CLOCKS_PER_SEC;
}

//Generates a dataset of size n, and runs all the algorithms on algo_list.
//Displays the results
void test_all_algorithms(vector<SortingMethod>& algo_list ,vector<float>& results, double& cy,int n){
	vector<int> v;
	char str[128];
	sprintf(str,"Generating a vector of size %d...",n);
	string s = str;
	win<<Message(Point(3,cy),s, GREEN);
	win.output_buffer();
	generate_random_set(v, n);
	s= s+"   DONE.";
	win<<Message(Point(3,cy),s, BLACK);
	win.output_buffer();
	cy -= LS*1.2;

	for(unsigned i = 0; i< algo_list.size();i++){
		results.push_back(draw_sort_timing(5+i*22,cy,algo_list[i],v));
	}
	cy -= LS*2.5;
}



//Main function
int instinct_main()
{
	win.coord(0,0,100,100);
	vector<SortingMethod> algo_list;
	algo_list.push_back(SortingMethod("Selection", &selection_sort));
	algo_list.push_back(SortingMethod("Bubble(Opt)", &op_bubble_sort));
	algo_list.push_back(SortingMethod("Insertion", &insertion_sort));
	algo_list.push_back(SortingMethod("STL Sort", &stl_sort));
	// The following needs to be used for assignment 8
	// algo_list.push_back(SortingMethod("Merge Sort", &merge_sort));

	vector<int> n;

	n.push_back(100);
	n.push_back(1000);
	n.push_back(2500);
	n.push_back(5000);
	n.push_back(10000);
	n.push_back(15000);
	n.push_back(20000);
	double cy = 97;

	win<<Message(Point(3,cy),"Starting batch testing...");
	win.output_buffer();
	cy -= LS*1.5;


	vector< vector<float> > times(algo_list.size());
	vector<float> results;
	for(unsigned i = 0; i< n.size();i++){
		test_all_algorithms(algo_list,results,cy,n[i]);
		for(unsigned j=0;j<times.size();j++){
			times[j].push_back(results[j]);
		}
		results.clear();

	}
	cy-=LS;
	win<<Message(Point(3,cy),"TAKE A SCREENSHOT!! (use 'Print Screen' on keyboard)",RED);
	cy-=LS*1.2;
	win<<Message(Point(3,cy),"Click to continue");
	win.output_buffer();
	win.get_click("");
	win.clear_buffer();
	draw_graph(algo_list,n,times);

	win<<Message(Point(25,70),"TAKE ANOTHER SCREENSHOT!!",RED);
	win.output_buffer();

	return 0;
}
//draws the origin
void draw_orig(){
	win<<Line(Point(5,5),Point(95,5));
	win<<Line(Point(5,5),Point(5,95));
	win<<Message(Point(49,1),"n");
	win<<Message(Point(2,93),"t");
}

//draws the data line for (x,y)
void draw_data(vector<int>& x, vector<float>& t, float maxt, float maxx, float minx, Color c){

	for(unsigned i =0; i < x.size()-1;i++){
		win<<Line(Point((x[i]-minx)/(maxx-minx)*90+5,t[i]/maxt*90+5),
				Point((x[i+1]-minx)/(maxx-minx)*90+5,t[i+1]/maxt*90+5),c);

	}

	for(unsigned i =0; i < x.size();i++){
		Circle cir(Point((x[i]-minx)/(maxx-minx)*90+5,t[i]/maxt*90+5),0.5,c);
		cir.set_filled_in(true);
		win<<cir;
	}
}

//draw all the collected information.
void draw_graph(vector<SortingMethod> methods,vector<int>& n, vector< vector<float> >& times){
	vector<Color> colors;
	colors.push_back(RED);
	colors.push_back(GREEN);
	colors.push_back(BLUE);
	colors.push_back(PURPLE);
	colors.push_back(YELLOW);
	colors.push_back(GRAY);

	draw_orig();
	float maxt = 0;
	for(unsigned i=0;i<times.size();i++){
		if(times[i].back()>maxt) maxt = times[i].back();
	}
	for(unsigned i=0;i<times.size();i++){
		draw_data(n,times[i],maxt,n.back(),n[0],colors[i%methods.size()]);
	}
	float cy = 95;
	for(unsigned i=0;i<methods.size();i++){
		win<<Line(Point(10,cy),Point(20,cy),colors[i%methods.size()]);
		win<<Message(Point(23,cy-LETTER_HEIGHT/2),methods[i].name,colors[i%methods.size()]);
		cy -=LS*1.5;
	}

	win<<Message( Point(3,1),n[0]) << Message(Point(90,1),n.back());
}

//runs the algorithm m on m and displays output.
float draw_sort_timing(int x, double y, SortingMethod& m,vector<int>& v){
	float t;
	win<<Message(Point(x,y),m.name,GREEN);
	win<<Line(Point(x-.5,y-0.5),Point(x+LETTER_WIDTH*m.name.length()+0.5,y-0.5));
	win.output_buffer();
	t = test_sorting_time(m.func,v);
	char str[128];
	sprintf(str,"%.3f s",t);
	win<<Message(Point(x+1.5,y-LS),str,BLACK);
	win.output_buffer();
	win<<Message(Point(x,y),m.name,BLACK);
	win.output_buffer();
	return t;
}
