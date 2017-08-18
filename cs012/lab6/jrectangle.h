//rectangle header file

#ifndef __JRectangle_H__
#define __JRectangle_H__

#include "jshape.h"
#include "instinct.h"

class JRectangle : public JShape
{
public:
    JRectangle();
    JRectangle(Point);
		JRectangle(Point center, Color color);
    JRectangle(Point, double, double);
		JRectangle(Point c, double h, double w, Color color);

    virtual double area() const;
    virtual void plot() const;
    virtual ~JRectangle();

private:
    double height;
    double width;
};

#endif
