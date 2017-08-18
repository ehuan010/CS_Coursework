#include "instinct.h"
#include <iostream>
#include "jshape.h"
#include "jrectangle.h"
#include "jsquare.h"
#include "toolbar.h"

#include <vector>

using namespace std;



int instinct_main()
{
	//set window to convenient coordinates
	win.coord(0, 0, 10, 10);
	win.set_title("Paint - Dynamic Binding, Polymorphism");

	/*********** Toolbar Initialization - START ******************/
	Toolbar toolbar(Point(8.5,8.5),1,1);

	//add rectanle icon
	JRectangle icon_rectangle(Point(0, 0), 0.4, 0.8,DARK_BLUE);
	toolbar.add_icon(&icon_rectangle);

	//add square icon
	JSquare icon_square = JSquare(Point(0, 1), 0.6,DARK_GREEN);
	toolbar.add_icon(&icon_square);

	//EX4 only: Add new icons just like above using JStar shape and your custom shape.




	toolbar.draw();
	win.output_buffer();

	/*********** Toolbar Initialization - END ******************/

	//declare vector for storing all shapes
	vector<JShape *> shapes;

	//get user click.
	Point click = win.get_mouse("Choose shape");

	//get_clicked function returns the index of the clicked icon (icon at top has index 0, next has index 1, etc.), 
	//if quit is clicked it returns -1, if the click is not on toolbar it returns -2.
	int selection = toolbar.get_clicked(click);

	//loop until quit box clicked filling vector with pointers to Shapes
	while (selection!=-1)
	{
		//if first icon is clicked...
		if(selection==0){
			//get another click from the user.
			/*...FILL HERE ...*/
      Point location = win.get_mouse("Choose location");

			//create a dynamic rectangle object using new keyword and the 
			//constructor that only gets a Point that you've just acquired.
			//(you can also use the constructor that has a Point and a Color as parameters if you want colored shapes).
			/*...FILL HERE ...*/
      JRectangle *rect = new JRectangle(location, ORANGE);


			//display the object that you've created
			/*...FILL HERE ...*/
      rect->plot();


			//add the object (use its pointer) to the shapes vector
			/*...FILL HERE ...*/
      shapes.push_back(rect);

		}

		//if second icon is clicked...
		else if(selection==1){
			//get another click from the user.
			/*...FILL HERE ...*/
      Point location = win.get_mouse("Choose location");

			//create a dynamic square object using new keyword and the 
			//constructor that only gets a Point that you've just acquired.
			//(you can also use the constructor that has a Point and a Color as parameters if you want colored shapes).
			/*...FILL HERE ...*/
      JSquare *square = new JSquare(location, PINK);


			//display the object that you've created
			/*...FILL HERE ...*/
      square->plot();


			//add the object (use its pointer) to the shapes vector
			/*...FILL HERE ...*/
      shapes.push_back(square);

		}

		//EX4 only: Add new 'else if' statements for additional shapes (jstar and your custom shape) just like above,
		//          where selection stores the order of the clicked icon (starting from 0) in the toolbar.



		win.output_buffer();

		//get the next shape choice from user
		click =  win.get_mouse("Choose next shape or Quit");
		selection = toolbar.get_clicked(click);

	}

	//clear screen before final output of all shapes and total area
	win.clear_buffer();

	//Calculate and output total area with a message.
	/*...FILL HERE ...*/
  double total = 0.0;
  for(unsigned int i = 0; i < shapes.size(); ++i)
  {
    total = total + shapes[i]->area();
  }
  Message m = Message(Point(1,9), total);
  win << m;
	//and output all shapes
	/*...FILL HERE ...*/
  for(unsigned int i = 0; i < shapes.size(); ++i)
  {
    shapes[i]->plot();
  }

	win.output_buffer();

	//delete all the dynamic objects you've created before exiting the program
	/*...FILL HERE ...*/
  for(unsigned int i = 0; i < shapes.size(); ++i)
  {
    delete shapes[i];
  }

	return 0;
}
