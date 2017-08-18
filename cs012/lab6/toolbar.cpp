#include "toolbar.h"

Toolbar::Toolbar()
{
	this->left = 0;
	this->up = 10;
	this->width = 1;
	this->icon_height = 1;
	quit = Message(Point(left+width/2,up-icon_height/2 - LETTER_HEIGHT/2),"Quit");
}

Toolbar::Toolbar(const Point& ul, float width, float icon_height)
{
	this->left = ul.get_x();
	this->up = ul.get_y();
	this->width = width;
	this->icon_height = icon_height;
	quit = Message(Point(left+width/2-2*LETTER_WIDTH,up-icon_height/2 - LETTER_HEIGHT/2),"Quit",WHITE);
}



void Toolbar::draw_boxes(){

	Rect r(Point(left,up-icon_height*(1+iconlist.size())),width,icon_height,DARK_RED);
	r.set_filled_in(true);
	win<<r;

	//draw horizontal lines
	win<<Line(Point(left,up), Point(left+width,up));

	for(unsigned i=1;i<=iconlist.size()+1;i++){
		win<<Line(Point(left,up-i*icon_height), Point(left+width,up-i*icon_height));
	}




	//draw vertical lines
	win<<Line(Point(left,up),Point(left,up-icon_height*(iconlist.size()+1)));
	win<<Line(Point(left+width,up),Point(left+width,up-icon_height*(1+iconlist.size())));

}

void Toolbar::draw(){
	draw_boxes();
	draw_icons();
}

void Toolbar::add_icon(JShape* icon){
	icon->set_center(Point(left+width/2,up-(iconlist.size()+.5)*icon_height));
	iconlist.push_back(icon);
	quit.move(0,-icon_height);
}

void Toolbar::draw_icons(){

	for(unsigned i=0;i<iconlist.size();i++){
		iconlist[i]->plot();
	}
	win<<quit;
}


int Toolbar::get_clicked(const Point &click){
	for(unsigned i = 0;i<iconlist.size();i++){
		if( click.get_x()<width+left && click.get_x()>left
				&& click.get_y() <= up-i*icon_height
				&& click.get_y() > up-(i+1)*icon_height)
			return i;
	}

	if( click.get_x()<width+left && click.get_x()>left
			&& click.get_y() <= up-iconlist.size()*icon_height
			&& click.get_y() > up-(iconlist.size()+1)*icon_height)
		return -1;


	return -2;
}

