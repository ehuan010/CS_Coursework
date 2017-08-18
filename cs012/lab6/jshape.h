//class Shape header file

#ifndef __JShape_H__
#define __JShape_H__

#include "instinct.h"

//base class
class JShape
{
public:
    JShape();
    JShape(Point);
		JShape(Point,Color);
    Point get_center() const;
    virtual double area() const = 0;
    virtual void plot() const = 0;
		virtual void set_center(const Point& c);
    virtual ~JShape();

private:
    Point center;
protected:
		Color color;
};
  
#endif
