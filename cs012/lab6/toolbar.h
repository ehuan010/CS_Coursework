#ifndef _JTOOLBAR_H_
#define _JTOOLBAR_H_

#include "jshape.h"
#include <vector>

using namespace std;


class Toolbar{
	private:
		vector<JShape*> iconlist;
		float left, up;
		float width, icon_height;

		void draw_icons();
		void draw_boxes();
		Message quit;
		int selection;

	public:
		Toolbar();
		Toolbar(const Point& upperleft, float width, float icon_height);
		void draw();
		void add_icon(JShape* icon);
		int get_clicked(const Point &click);


};


#endif
